#ifndef PNGERROR_H
#define PNGERROR_H

#include <png/png.h>

/* Application errors (new in 1.6); use these functions (declared below) for
 * errors in the parameters or order of API function calls on read.  The
 * 'warning' should be used for an error that can be handled completely; the
 * 'error' for one which can be handled safely but which may lose application
 * information or settings.
 *
 * By default these both result in a png_error call prior to release, while in a
 * released version the 'warning' is just a warning.  However if the application
 * explicitly disables benign errors (explicitly permitting the code to lose
 * information) they both turn into warnings.
 *
 * If benign errors aren't supported they end up as the corresponding base call
 * (png_warning or png_error.)
 */
void 
png_app_warning (png_const_structrp png_ptr, const char* message);

/* The application provided invalid parameters to an API function or called
 * an API function at the wrong time, libpng can completely recover.
 */

void
png_app_error (png_const_structrp png_ptr, const char* message);

/* As above but libpng will ignore the call, or attempt some other partial
 * recovery from the error.
 */

void 
png_chunk_report (png_const_structrp png_ptr, const char* message, int error);
/* Report a recoverable issue in chunk data.  On read this is used to report
 * a problem found while reading a particular chunk and the
 * png_chunk_benign_error or png_chunk_warning function is used as
 * appropriate.  On write this is used to report an error that comes from
 * data set via an application call to a png_set_ API and png_app_error or
 * png_app_warning is used as appropriate.
 *
 * The 'error' parameter must have one of the following values:
 */
#define PNG_CHUNK_WARNING     0 /* never an error */
#define PNG_CHUNK_WRITE_ERROR 1 /* an error only on write */
#define PNG_CHUNK_ERROR       2 /* always an error */

#if defined(PNG_FLOATING_POINT_SUPPORTED)
void PNG_NORETURN
png_fixed_error (png_const_structrp png_ptr, const char* name);
#endif

/* Various internal functions to handle formatted warning messages, currently
 * only implemented for warnings.
 */
/* Utility to dump an unsigned value into a buffer, given a start pointer and
 * and end pointer (which should point just *beyond* the end of the buffer!)
 * Returns the pointer to the start of the formatted string.  This utility only
 * does unsigned values.
 */
char* 
png_format_number (const char* start, char* end, int format, size_t number);

/* Convenience macro that takes an array: */
#define PNG_FORMAT_NUMBER(buffer, format, number)                                                  \
  png_format_number (buffer, buffer + (sizeof buffer), format, number)

/* Suggested size for a number buffer (enough for 64 bits and a sign!) */
#define PNG_NUMBER_BUFFER_SIZE 24

/* These are the integer formats currently supported, the name is formed from
 * the standard printf(3) format string.
 */
#define PNG_NUMBER_FORMAT_u     1 /* chose unsigned API! */
#define PNG_NUMBER_FORMAT_02u   2
#define PNG_NUMBER_FORMAT_d     1 /* chose signed API! */
#define PNG_NUMBER_FORMAT_02d   2
#define PNG_NUMBER_FORMAT_x     3
#define PNG_NUMBER_FORMAT_02x   4
#define PNG_NUMBER_FORMAT_fixed 5 /* choose the signed API */

/* Puts 'string' into 'buffer' at buffer[pos], taking care never to overwrite
 * the end.  Always leaves the buffer nul terminated.  Never errors out (and
 * there is no error code.)
 */
size_t 
png_safecat (png_charp buffer, size_t bufsize, size_t pos, const char* string);

/* New defines and members adding in libpng-1.5.4 */
#define PNG_WARNING_PARAMETER_SIZE  32
#define PNG_WARNING_PARAMETER_COUNT 8 /* Maximum 9; see pngerror.c */

/* An l-value of this type has to be passed to the APIs below to cache the
 * values of the parameters to a formatted warning message.
 */
typedef char png_warning_parameters[PNG_WARNING_PARAMETER_COUNT][PNG_WARNING_PARAMETER_SIZE];

void 
png_warning_parameter (png_warning_parameters p, int number, const char* string);
/* Parameters are limited in size to PNG_WARNING_PARAMETER_SIZE characters,
 * including the trailing '\0'.
 */

void
png_warning_parameter_unsigned (png_warning_parameters p, int number, int format, 
  size_t value);
/* Use size_t because it is an unsigned type as big as any we
 * need to output.  Use the following for a signed value.
 */

void 
png_warning_parameter_signed (png_warning_parameters p, int number, int format, 
  png_int_32 value);

void 
png_formatted_warning (png_const_structrp png_ptr, png_warning_parameters p,
  const char* message);
/* 'message' follows the X/Open approach of using @1, @2 to insert
 * parameters previously supplied using the above functions.  Errors in
 * specifying the parameters will simply result in garbage substitutions.
 */

#endif
