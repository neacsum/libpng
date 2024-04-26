#ifndef PNG_WUTIL_H
#define PNG_WUTIL_H

#include <png/png.h>
#include <pngstruct.h>


void
png_compress_IDAT (png_structrp png_ptr, png_const_bytep row_data, 
  size_t row_data_length, int flush);

/* Grab pixels out of a row for an interlaced pass */
void
png_do_write_interlace (png_row_infop row_info, png_bytep row, int pass);

void
png_free_buffer_list (png_structrp png_ptr, png_compression_bufferp* list);
/* Free the buffer list used by the compressed write code. */

/* Write various chunks */

/* Write the IHDR chunk, and update the png_struct with the necessary
 * information.
 */
void 
png_write_IHDR (png_structrp png_ptr, png_uint_32 width, png_uint_32 height, 
  int bit_depth, int color_type, int compression_method, int filter_method,
  int interlace_method);

void
png_write_PLTE (png_structrp png_ptr, png_const_colorp palette, 
  png_uint_32 num_pal);

void
png_write_IEND (png_structrp png_ptr);

void 
png_write_gAMA_fixed (png_structrp png_ptr, png_fixed_point file_gamma);

void
png_write_sBIT (png_structrp png_ptr, png_const_color_8p sbit, int color_type);

void
png_write_cHRM_fixed (png_structrp png_ptr, const png_xy* xy);
/* The xy value must have been previously validated */

void
png_write_sRGB (png_structrp png_ptr, int intent);

void
png_write_eXIf (png_structrp png_ptr, png_bytep exif, int num_exif);

void 
png_write_iCCP (png_structrp png_ptr, png_const_charp name, png_const_bytep profile);
/* The profile must have been previously validated for correctness, the
 * length comes from the first four bytes.  Only the base, deflate,
 * compression is supported.
 */

void 
png_write_sPLT (png_structrp png_ptr, png_const_sPLT_tp palette);

void
png_write_tRNS (png_structrp png_ptr, png_const_bytep trans, 
  png_const_color_16p values, int number, int color_type);

void
png_write_bKGD (png_structrp png_ptr, png_const_color_16p values, int color_type);

void
png_write_hIST (png_structrp png_ptr, png_const_uint_16p hist, int num_hist);

/* Chunks that have keywords */
void
png_write_tEXt (png_structrp png_ptr, png_const_charp key, png_const_charp text,
  size_t text_len);

void
png_write_zTXt (png_structrp png_ptr, png_const_charp key, png_const_charp text, 
  int compression);

void
png_write_iTXt (png_structrp png_ptr, int compression, png_const_charp key,
  png_const_charp lang, png_const_charp lang_key, png_const_charp text);

int
png_set_text_2 (png_const_structrp png_ptr, png_inforp info_ptr, 
  png_const_textp text_ptr, int num_text);

void
png_write_oFFs (png_structrp png_ptr, png_int_32 x_offset, png_int_32 y_offset,
  int unit_type);

void
png_write_pCAL (png_structrp png_ptr, png_charp purpose, png_int_32 X0, 
  png_int_32 X1, int type, int nparams, png_const_charp units, png_charpp params);

void
png_write_pHYs (png_structrp png_ptr, png_uint_32 x_pixels_per_unit,
  png_uint_32 y_pixels_per_unit, int unit_type);

void
png_write_tIME (png_structrp png_ptr, png_const_timep mod_time);

void
png_write_sCAL_s (png_structrp png_ptr, int unit, png_const_charp width,
  png_const_charp height);

/* Called when finished processing a row of data */
void
png_write_finish_row (png_structrp png_ptr);

/* Internal use only.   Called before first row of data */
void
png_write_start_row (png_structrp png_ptr);

#endif
