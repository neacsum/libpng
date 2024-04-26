#pragma once
#ifndef PNG_TRANS_H
#define PNG_TRANS_H

#include <png/png.h>

/* Handle the transformations for reading and writing */

void
png_init_read_transformations (png_structrp png_ptr);

void
png_do_read_transformations (png_structrp png_ptr, png_row_infop row_info);

/* Optional call to update the users info structure */
void 
png_read_transform_info (png_structrp png_ptr, png_inforp info_ptr);

void
png_do_bgr (png_row_infop row_info, png_bytep row);

void
png_do_check_palette_indexes (png_structrp png_ptr, png_row_infop row_info);

void
png_do_invert (png_row_infop row_info, png_bytep row);

void
png_do_packswap (png_row_infop row_info, png_bytep row);

void
png_do_strip_channel (png_row_infop row_info, png_bytep row, int at_start);

void 
png_do_swap (png_row_infop row_info, png_bytep row);

void
png_do_write_transformations (png_structrp png_ptr, png_row_infop row_info);


#endif