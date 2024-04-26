This is a fork of **libpng** at version 1.6.39.

The initial goal of this fork was only to reorganize code to make it compliant with [Dogfood Layout](https://neacsu.net/docs/programming/code_layout/uccl/).

The original README file can be found [here](README.orig).

# What is different from "official" **libpng**
- Code layout - As stated before that was the primary goal.
- Static linking is the preferred form of linking.
- There is support only for major platforms. Currently I'm building and testing only for Windows and Linux (Ubuntu).

# Building
Use [CPM](https://github.com/neacsum/cpm) to build the library:
1. Download latest CPM executable for [Windows](https://github.com/neacsum/cpm/releases/download/latest/cpm.exe) or [Linux](https://github.com/neacsum/cpm/releases/download/latest/cpm).
2. Set the `DEV_ROOT` environment variable to the root of your development tree:
   ```
   $ export DEV_ROOT=my_path
   ```
   or
   ```
   C:\> set DEV_ROOT=c:\my_path
   ```
3. Run CPM to fetch and build **libpng** and any dependencies:
   ```
   cpm -u git@github.com:neacsum/libpng.git libpng
   ```
## Building other artifacts (examples, test programs, etc.)
The simplified build process described above builds only the static library in release configuration.
To build other targets you can use one of the following commands:
- `cmake --workflow --preset lib_debug`  - build debug library
- `cmake --workflow --preset all_release` - build library, examples and test programs in release configuration
- `cmake --workflow --preset all_degug` - build library, examples and test program in debug mode

# Content
File | Description
-----|------------
BUILD.bat | Windows build script
CMakeLists.txt | CMake configuration file
CMakePresets.json | CMake preset build configurations
cpm.json | CPM configuration file
png.sln | Visual Studio solution file
| include | directory for header files (private and public API)
| include/png | directory for public API headers
| docs | directory for documentation (including [user manual](docs/libpng-manual.md))
| examples | sample programs
| fab | files related to build process



## Configuration flags removed
- `PNG_STDIO_SUPPORTED` - all supported platforms have _stdio.h_
- `PNG_WRITE_FLUSH_SUPPORTED` - optional flushing adds very little memory overhead
- `PNG_WRITE_SUPPORTED` - this library supports reading and writing of PNG files
- `PNG_READ_SUPPORTED` - same
- `PNG_CONSOLE_IO_SUPPORTED` - error handling will be restructured at some point
- `PNG_VERSION_INFO_ONLY` - DLL versioning is not a priority
- `PNG_SIMPLIFIED_READ` - simplified API is always available
- `PNG_SIMPLIFIED_WRITE` - same
- `PNG_SIMPLIFIED_WRITE_STDIO_SUPPORTED` - yes, _stdio.h_ is available
- `PNG_POINTER_INDEXING_SUPPORTED` - any standard conforming compiler can do pointer indexing
- `PNG_SEQUENTIAL_READ_SUPPORTED`
- `PNG_EASY_ACCESS`

The following active feature selection flags have been removed: `PNG_bKGD_SUPPORTED`,`PNG_cHRM_SUPPORTED`, `PNG_gAMA_SUPPORTED`, `PNG_pCAL_SUPPORTED`,`PNG_pHYs_SUPPORTED`, `PNG_sBIT_SUPPORTED`, `PNG_sBIT_SUPPORTED`,`PNG_iCCP_SUPPORTED`, `PNG_sPLT_SUPPORTED`, `PNG_TEXT_SUPPORTED`,`PNG_zTXt_SUPPORTED`,`PNG_iTXt_SUPPORTED`, `PNG_WRITE_zTXt_SUPPORTED`,`PNG_tIME_SUPPORTED`, `PNG_tRNS_SUPPORTED`, `PNG_sCAL_SUPPORTED`,`PNG_SET_UNKNOWN_CHUNKS_SUPPORTED`, `PNG_HANDLE_AS_UNKNOWN_SUPPORTED`,`PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED`,`PNG_SEQUENTIAL_READ_SUPPORTED`, `PNG_INFO_IMAGE_SUPPORTED`, `PNG_SET_USER_LIMITS_SUPPORTED`,`PNG_INCH_CONVERSIONS_SUPPORTED`, `PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED`, `PNG_GET_PALETTE_MAX_SUPPORTED`, `PNG_READ_INT_FUNCTIONS_SUPPORTED`, `PNG_WRITE_INT_FUNCTIONS_SUPPORTED`, `PNG_SAVE_INT_32_SUPPORTED`, `PNG_SET_OPTION_SUPPORTED`, `PNG_TIME_RFC1123_SUPPORTED`, `PNG_COLORSPACE_SUPPORTED`, `PNG_CONVERT_tIME_SUPPORTED`, `PNG_GAMMA_SUPPORTED`, `PNG_WRITE_tRNS_SUPPORTED`, `PNG_WRITE_tIME_SUPPORTED`, `PNG_WRITE_tEXt_SUPPORTED`, `PNG_WRITE_sRGB_SUPPORTED`, `PNG_WRITE_sPLT_SUPPORTED`, `PNG_WRITE_sCAL_SUPPORTED`, `PNG_WRITE_sBIT_SUPPORTED`, `PNG_WRITE_pHYs_SUPPORTED`, `PNG_WRITE_pCAL_SUPPORTED`, `PNG_WRITE_oFFs_SUPPORTED`, `PNG_WRITE_iTXt_SUPPORTED`, `PNG_WRITE_hIST_SUPPORTED`, `PNG_WRITE_gAMA_SUPPORTED`, `PNG_WRITE_eXIf_SUPPORTED`, `PNG_WRITE_cHRM_SUPPORTED`, `PNG_WRITE_bKGD_SUPPORTED`, `PNG_WRITE_WEIGHTED_FILTER_SUPPORTED`, `PNG_WRITE_USER_TRANSFORM_SUPPORTED`, `PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED`, `PNG_WRITE_TRANSFORMS_SUPPORTED`, `PNG_WRITE_TEXT_SUPPORTED`, `PNG_WRITE_SWAP_SUPPORTED`, `PNG_WRITE_SWAP_ALPHA_SUPPORTED`, `PNG_WRITE_SHIFT_SUPPORTED`, `PNG_WRITE_PACK_SUPPORTED`, `PNG_WRITE_PACKSWAP_SUPPORTED`, `PNG_WRITE_OPTIMIZE_CMF_SUPPORTED`, `PNG_WRITE_INVERT_SUPPORTED`, `PNG_WRITE_INVERT_ALPHA_SUPPORTED`, `PNG_WRITE_INTERLACING_SUPPORTED`, `PNG_WRITE_GET_PALETTE_MAX_SUPPORTED`, `PNG_WRITE_FILTER_SUPPORTED`, `PNG_WRITE_FILLER_SUPPORTED`, `PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED`, `PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED`, `PNG_WRITE_COMPRESSED_TEXT_SUPPORTED`, `PNG_WRITE_CHECK_FOR_INVALID_INDEX_SUPPORTED`, `PNG_WRITE_BGR_SUPPORTED`, `PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED`, `PNG_WRITE_16BIT_SUPPORTED`, `PNG_WARNINGS_SUPPORTED`, `PNG_USER_TRANSFORM_PTR_SUPPORTED`, `PNG_USER_TRANSFORM_INFO_SUPPORTED`, `PNG_USER_MEM_SUPPORTED`, `PNG_USER_LIMITS_SUPPORTED`, `PNG_USER_CHUNKS_SUPPORTED`, `PNG_UNKNOWN_CHUNKS_SUPPORTED`, `PNG_SIMPLIFIED_WRITE_BGR_SUPPORTED`, `PNG_SIMPLIFIED_WRITE_AFIRST_SUPPORTED`, `PNG_SIMPLIFIED_READ_BGR_SUPPORTED`, `PNG_SIMPLIFIED_READ_AFIRST_SUPPORTED`, `PNG_SET_OPTION_SUPPORTED`, `PNG_SAVE_UNKNOWN_CHUNKS_SUPPORTED`
`PNG_READ_zTXt_SUPPORTED`, `PNG_READ_tRNS_SUPPORTED`, `PNG_READ_tIME_SUPPORTED`, `PNG_READ_tEXt_SUPPORTED`, `PNG_READ_sRGB_SUPPORTED`, `PNG_READ_sPLT_SUPPORTED`, `PNG_READ_sCAL_SUPPORTED`, `PNG_READ_sBIT_SUPPORTED`, `PNG_READ_pHYs_SUPPORTED`, `PNG_READ_pCAL_SUPPORTED`, `PNG_READ_oFFs_SUPPORTED`, `PNG_READ_iTXt_SUPPORTED`, `PNG_READ_iCCP_SUPPORTED`, `PNG_READ_hIST_SUPPORTED`, `PNG_READ_gAMA_SUPPORTED`, `PNG_READ_eXIf_SUPPORTED`, `PNG_READ_cHRM_SUPPORTED`, `PNG_READ_bKGD_SUPPORTED`, `PNG_READ_USER_TRANSFORM_SUPPORTED`, `PNG_READ_USER_CHUNKS_SUPPORTED`, `PNG_READ_UNKNOWN_CHUNKS_SUPPORTED`, `PNG_READ_TRANSFORMS_SUPPORTED`, `PNG_READ_TEXT_SUPPORTED`, `PNG_READ_SWAP_SUPPORTED`, `PNG_READ_SWAP_ALPHA_SUPPORTED`, `PNG_READ_STRIP_ALPHA_SUPPORTED`, `PNG_READ_STRIP_16_TO_8_SUPPORTED`, `PNG_READ_SHIFT_SUPPORTED`, `PNG_READ_SCALE_16_TO_8_SUPPORTED`, `PNG_READ_RGB_TO_GRAY_SUPPORTED`, `PNG_READ_QUANTIZE_SUPPORTED`, `PNG_READ_PACK_SUPPORTED`, `PNG_READ_OPT_PLTE_SUPPORTED`, `PNG_READ_INVERT_SUPPORTED`, `PNG_READ_INVERT_ALPHA_SUPPORTED`, `PNG_READ_INTERLACING_SUPPORTED`, `PNG_READ_GRAY_TO_RGB_SUPPORTED`, `PNG_READ_GET_PALETTE_MAX_SUPPORTED`, `PNG_READ_GAMMA_SUPPORTED`, `PNG_READ_FILLER_SUPPORTED`, `PNG_READ_EXPAND_SUPPORTED`, `PNG_READ_EXPAND_16_SUPPORTED`, `PNG_READ_COMPRESSED_TEXT_SUPPORTED`, `PNG_READ_COMPOSITE_NODIV_SUPPORTED`, `PNG_READ_CHECK_FOR_INVALID_INDEX_SUPPORTED`, `PNG_READ_BGR_SUPPORTED`, `PNG_READ_BACKGROUND_SUPPORTED`, `PNG_READ_ANCILLARY_CHUNKS_SUPPORTED`, `PNG_READ_ALPHA_MODE_SUPPORTED`, `PNG_READ_16BIT_SUPPORTED`, `PNG_PROGRESSIVE_READ_SUPPORTED`, `PNG_FORMAT_BGR_SUPPORTED`,`PNG_FORMAT_AFIRST_SUPPORTED`, `PNG_BUILD_GRAYSCALE_PALETTE_SUPPORTED`, `PNG_BENIGN_READ_ERRORS_SUPPORTED`, `PNG_BENIGN_ERRORS_SUPPORTED`, `PNG_16BIT_SUPPORTED`

A system-wide loadable library should have all the features available in case an application needs those. If linking with a static library, linkers are sufficiently smart to pick only required modules. 
Some of these feature selection flags were not even used (e.g. `PNG_SIMPLIFIED_READ_BGR_SUPPORTED`, `PNG_SET_USER_LIMITS_SUPPORTED`, `PNG_SET_OPTION_SUPPORTED`, `PNG_READ_TEXT_SUPPORTED`)

The following inactive feature selection flags and their associated code have been removed:
- PNG_MNG_FEATURES_SUPPORTED - MNG seems like a dead format

## Other changes
- All PNG source files are renamed to *.CPP and compiled as C++ code
- Huge _pngpriv.h_ include file has been broken in individual includes:
	- _pngmem.h_ - private functions defined in _pngmem.cpp_
	- _pngerror.h_ private functions defined in _pngerror.cpp_
	- _trans.h_ private functions defined in _pngrtran.cpp_, _pngwtran.cpp_ and _pngtrans.cpp_
	- _rutil.h_ private functions defined in _rutil.cpp_
	- _wutil.h_ private functions defined in _wutil.cpp_
- Some redefinitions of standard types have been removed:
	- `png_charp` - `char*`
	- `png_const_charp` - `const char*`
- Removed `png_voidcast` and `png_constcast` macros. Why choose casting style in a header file when you can do it in the source file where you know if it is a "C" or a "C++" file.
- Separate callback signatures for user read and write functions. Const-correctness is important.
- Added const qualifiers to `png_malloc_ptr` and `png_free_ptr`