#ifndef PNGMEM_H
#define PNGMEM_H

#include <png/png.h>

/* Free memory from internal libpng struct */
void
png_destroy_png_struct (png_structrp png_ptr);

/* Internal base allocator - no messages, NULL on failure to allocate.  This
 * does, however, call the application provided allocator and that could call
 * png_error (although that would be a bug in the application implementation.)
 */
png_voidp
png_malloc_base (png_const_structrp png_ptr, size_t size);

/* Internal array allocator, outputs no error or warning messages on failure,
 * just returns NULL.
 */
png_voidp
png_malloc_array (png_const_structrp png_ptr, int nelements, size_t element_size);

/* The same but an existing array is extended by add_elements.  This function
 * also memsets the new elements to 0 and copies the old elements.  The old
 * array is not freed or altered.
 */
png_voidp
png_realloc_array (png_const_structrp png_ptr, png_const_voidp array, int old_elements,
                   int add_elements, size_t element_size);

#endif
