#pragma once
#ifndef PNG_RUTIL_H
#define PNG_RUTIL_H

#include <png/png.h>

void
png_check_chunk_length (png_const_structrp png_ptr, png_uint_32 chunk_length);

void
png_check_chunk_name (png_const_structrp png_ptr, png_uint_32 chunk_name);

/* Combine a row of data, dealing with alpha, etc. if requested.  'row' is an
 * array of png_ptr->width pixels.  If the image is not interlaced or this
 * is the final pass this just does a memcpy, otherwise the "display" flag
 * is used to determine whether to copy pixels that are not in the current pass.
 *
 * Because 'png_do_read_interlace' (below) replicates pixels this allows this
 * function to achieve the documented 'blocky' appearance during interlaced read
 * if display is 1 and the 'sparkle' appearance, where existing pixels in 'row'
 * are not changed if they are not in the current pass, when display is 0.
 *
 * 'display' must be 0 or 1, otherwise the memcpy will be done regardless.
 *
 * The API always reads from the png_struct row buffer and always assumes that
 * it is full width (png_do_read_interlace has already been called.)
 *
 * This function is only ever used to write to row buffers provided by the
 * caller of the relevant libpng API and the row must have already been
 * transformed by the read transformations.
 *
 * The PNG_USE_COMPILE_TIME_MASKS option causes generation of pre-computed
 * bitmasks for use within the code, otherwise runtime generated masks are used.
 * The default is compile time masks.
 */
#ifndef PNG_USE_COMPILE_TIME_MASKS
#define PNG_USE_COMPILE_TIME_MASKS 1
#endif
void
png_combine_row (png_const_structrp png_ptr, png_bytep row, int display);

/* Read "skip" bytes, read the file crc, and (optionally) verify png_ptr->crc */
int 
png_crc_finish (png_structrp png_ptr, png_uint_32 skip);

/* Read bytes into buf, and update png_ptr->crc */
void 
png_crc_read (png_structrp png_ptr, png_bytep buf, png_uint_32 length);

/* Expand an interlaced row: the 'row_info' describes the pass data that has
 * been read in and must correspond to the pixels in 'row', the pixels are
 * expanded (moved apart) in 'row' to match the final layout, when doing this
 * the pixels are *replicated* to the intervening space.  This is essential for
 * the correct operation of png_combine_row, above.
 */
void
png_do_read_interlace (png_row_infop row_info, png_bytep row, int pass,
  png_uint_32 transformations);

void
png_handle_bKGD (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_cHRM (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_eXIf (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void 
png_handle_gAMA (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_hIST (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_iCCP (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void 
png_handle_IEND (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

/* Decode the IHDR chunk */
void
png_handle_IHDR (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_iTXt (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_oFFs (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_pCAL (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_pHYs (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void 
png_handle_PLTE (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_sBIT (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void 
png_handle_sCAL (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_sPLT (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_sRGB (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_tEXt (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_tIME (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_tRNS (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

void
png_handle_zTXt (png_structrp png_ptr, png_inforp info_ptr, png_uint_32 length);

/* This is the function that gets called for unknown chunks.  The 'keep'
 * argument is either non-zero for a known chunk that has been set to be
 * handled as unknown or zero for an unknown chunk.  By default the function
 * just skips the chunk or errors out if it is critical.
 */
void
png_handle_unknown (png_structrp png_ptr, png_inforp info_ptr, 
  png_uint_32 length, int keep);

/* Read the chunk header (length + type name) */
png_uint_32
png_read_chunk_header (png_structrp png_ptr);

/* Unfilter a row: check the filter value before calling this, there is no point
 * calling it for PNG_FILTER_VALUE_NONE.
 */
void
png_read_filter_row (png_structrp pp, png_row_infop row_info, png_bytep row,
  png_const_bytep prev_row, int filter);

/* This cleans up when the IDAT LZ stream does not end when the last image
 * byte is read; there is still some pending input.
 */
void 
png_read_finish_IDAT (png_structrp png_ptr);

/* Finish a row while reading, dealing with interlacing passes, etc. */
void
png_read_finish_row (png_structrp png_ptr);

/* Read 'avail_out' bytes of data from the IDAT stream.  If the output buffer
 * is NULL the function checks, instead, for the end of the stream.  In this
 * case a benign error will be issued if the stream end is not found or if
 * extra data has to be consumed.
 */
void
png_read_IDAT_data (png_structrp png_ptr, png_bytep output, size_t avail_out);

/* Read and check the PNG file signature */
void
png_read_sig (png_structrp png_ptr, png_inforp info_ptr);

/* Initialize the row buffers, etc. */
void
png_read_start_row (png_structrp png_ptr);

int
png_zlib_inflate (png_structrp png_ptr, int flush);
#define PNG_INFLATE(pp, flush) png_zlib_inflate (pp, flush)

#endif