/* libconf.h - library build configuration */

/* libpng version 1.6.44.git */

/* Copyright (c) 2018-2024 Cosmin Truta */
/* Copyright (c) 1998-2002,2004,2006-2018 Glenn Randers-Pehrson */

/* This code is released under the libpng license. */
/* For conditions of distribution and use, see the disclaimer */
/* and license in png.h */

/* libconf.h */
/* Machine generated file: DO NOT EDIT */
/* Derived from: scripts/pnglibconf.dfa */
#ifndef PNG_LIBCONF_H
#define PNG_LIBCONF_H
/* options */
#define PNG_16BIT_SUPPORTED
#define PNG_ALIGNED_MEMORY_SUPPORTED
/*#undef PNG_ARM_NEON_API_SUPPORTED*/
/*#undef PNG_ARM_NEON_CHECK_SUPPORTED*/
/*#undef PNG_BENIGN_WRITE_ERRORS_SUPPORTED*/
/*#undef PNG_DISABLE_ADLER32_CHECK_SUPPORTED*/
/*#undef PNG_ERROR_NUMBERS_SUPPORTED*/
#define PNG_FIXED_POINT_SUPPORTED
#define PNG_FLOATING_ARITHMETIC_SUPPORTED
#define PNG_FLOATING_POINT_SUPPORTED
/*#undef PNG_MIPS_MSA_API_SUPPORTED*/
/*#undef PNG_POWERPC_VSX_API_SUPPORTED*/

#define PNG_SETJMP_SUPPORTED
/* end of options */
/* settings */
#define PNG_API_RULE 0
#define PNG_DEFAULT_READ_MACROS 1
#define PNG_GAMMA_THRESHOLD_FIXED 5000
#define PNG_IDAT_READ_SIZE PNG_ZBUF_SIZE
#define PNG_INFLATE_BUF_SIZE 1024
#define PNG_LINKAGE_API extern
#define PNG_LINKAGE_CALLBACK extern
#define PNG_LINKAGE_DATA extern
#define PNG_LINKAGE_FUNCTION extern
#define PNG_MAX_GAMMA_8 11
#define PNG_QUANTIZE_BLUE_BITS 5
#define PNG_QUANTIZE_GREEN_BITS 5
#define PNG_QUANTIZE_RED_BITS 5
#define PNG_TEXT_Z_DEFAULT_COMPRESSION (-1)
#define PNG_TEXT_Z_DEFAULT_STRATEGY 0
#define PNG_USER_CHUNK_CACHE_MAX 1000
#define PNG_USER_CHUNK_MALLOC_MAX 8000000
#define PNG_USER_HEIGHT_MAX 1000000
#define PNG_USER_WIDTH_MAX 1000000
#define PNG_ZBUF_SIZE 8192
#define PNG_ZLIB_VERNUM 0 /* unknown */
#define PNG_Z_DEFAULT_COMPRESSION (-1)
#define PNG_Z_DEFAULT_NOFILTER_STRATEGY 0
#define PNG_Z_DEFAULT_STRATEGY 1
#define PNG_sCAL_PRECISION 5
#define PNG_sRGB_PROFILE_CHECKS 2
/* end of settings */
#endif /* PNG_LIBCONF_H */
