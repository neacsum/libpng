cmake_minimum_required(VERSION 3.15.0)

project(png 
  VERSION 1.6.39
  LANGUAGES C CXX)

#CMake debugging stuff
set (VARLIST true)
set (CMAKE_VERBOSE_MAKEFILE true)

set(PNGLIB_MAJOR 1)
set(PNGLIB_MINOR 6)
set(PNGLIB_REVISION 39)
#set(PNGLIB_SUBREVISION 0)
set(PNGLIB_SUBREVISION "neacsum")
set(PNGLIB_NAME libpng${PNGLIB_MAJOR}${PNGLIB_MINOR})
set(PNGLIB_VERSION ${PNGLIB_MAJOR}.${PNGLIB_MINOR}.${PNGLIB_REVISION})
set(PNGLIB_SHARED_SOVERSION ${PNGLIB_MAJOR}${PNGLIB_MINOR})
set(PNGLIB_SHARED_VERSION ${PNGLIB_SHARED_SOVERSION}.${PNGLIB_REVISION}.${PNGLIB_SUBREVISION})


set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(TESTS_DIR "${CMAKE_SOURCE_DIR}/tests")
set(TOOLS_DIR "${CMAKE_SOURCE_DIR}/extras/tools")

if(UNIX AND NOT APPLE AND NOT BEOS AND NOT HAIKU AND NOT EMSCRIPTEN)
  find_library(M_LIBRARY m)
  if(NOT M_LIBRARY)
    set(M_LIBRARY "")
  endif()
else()
  # libm is not needed and/or not available.
  set(M_LIBRARY "")
endif()

find_library(Z_LIBRARY zlib)
if(NOT Z_LIBRARY)
  if(UNIX)
    set(Z_LIBRARY "libz.a")
  else()
    set(Z_LIBRARY "zlib.lib")
  endif()
endif()

# Public CMake configuration variables.
option(PNG_STATIC "Build static lib" ON)
option(PNG_EXECUTABLES "Build libpng executables" OFF)
option(PNG_TESTS "Build libpng tests" ON)
option(PNG_TOOLS "Build libpng tools" ON)
option(PNG_INSTALL "Install libpng libary" ON)

# Many more configuration options could be added here.
option(PNG_DEBUG "Build with debug output" OFF)
option(PNG_HARDWARE_OPTIMIZATIONS "Enable hardware optimizations" ON)

# Set definitions for ARM.
if(PNG_HARDWARE_OPTIMIZATIONS AND (TARGET_ARCH MATCHES "^(arm|aarch64)"))
  if(TARGET_ARCH MATCHES "^(arm64|aarch64)")
    set(PNG_ARM_NEON_POSSIBLE_VALUES on off)
    set(PNG_ARM_NEON "on"
        CACHE STRING "Enable ARM NEON optimizations: on|off; on is default")
  else()
    set(PNG_ARM_NEON_POSSIBLE_VALUES check on off)
    set(PNG_ARM_NEON "off"
        CACHE STRING "Enable ARM NEON optimizations: check|on|off; off is default")
  endif()
  set_property(CACHE PNG_ARM_NEON
               PROPERTY STRINGS ${PNG_ARM_NEON_POSSIBLE_VALUES})
  list(FIND PNG_ARM_NEON_POSSIBLE_VALUES ${PNG_ARM_NEON} index)
  if(index EQUAL -1)
    message(FATAL_ERROR "PNG_ARM_NEON must be one of [${PNG_ARM_NEON_POSSIBLE_VALUES}]")
  elseif(NOT ${PNG_ARM_NEON} STREQUAL "off")
    if(${PNG_ARM_NEON} STREQUAL "on")
      add_definitions(-DPNG_ARM_NEON_OPT=2)
    elseif(${PNG_ARM_NEON} STREQUAL "check")
      add_definitions(-DPNG_ARM_NEON_CHECK_SUPPORTED)
    endif()
  else()
    add_definitions(-DPNG_ARM_NEON_OPT=0)
  endif()
endif()

# Set definitions for PowerPC.
if(PNG_HARDWARE_OPTIMIZATIONS AND (TARGET_ARCH MATCHES "^(powerpc*|ppc64*)"))
  set(PNG_POWERPC_VSX_POSSIBLE_VALUES on off)
  set(PNG_POWERPC_VSX "on"
      CACHE STRING "Enable POWERPC VSX optimizations: on|off; on is default")
  set_property(CACHE PNG_POWERPC_VSX
               PROPERTY STRINGS ${PNG_POWERPC_VSX_POSSIBLE_VALUES})
  list(FIND PNG_POWERPC_VSX_POSSIBLE_VALUES ${PNG_POWERPC_VSX} index)
  if(index EQUAL -1)
    message(FATAL_ERROR "PNG_POWERPC_VSX must be one of [${PNG_POWERPC_VSX_POSSIBLE_VALUES}]")
  elseif(NOT ${PNG_POWERPC_VSX} STREQUAL "off")
    if(${PNG_POWERPC_VSX} STREQUAL "on")
      add_definitions(-DPNG_POWERPC_VSX_OPT=2)
    endif()
  else()
    add_definitions(-DPNG_POWERPC_VSX_OPT=0)
  endif()
endif()

# Set definitions for Intel.
if(PNG_HARDWARE_OPTIMIZATIONS AND (TARGET_ARCH MATCHES "^(AMD64|i?86|x86_64*)"))
  set(PNG_INTEL_SSE_POSSIBLE_VALUES on off)
  set(PNG_INTEL_SSE "on"
      CACHE STRING "Enable INTEL_SSE optimizations: on|off; on is default")
  set_property(CACHE PNG_INTEL_SSE
               PROPERTY STRINGS ${PNG_INTEL_SSE_POSSIBLE_VALUES})
  list(FIND PNG_INTEL_SSE_POSSIBLE_VALUES ${PNG_INTEL_SSE} index)
  if(index EQUAL -1)
    message(FATAL_ERROR "PNG_INTEL_SSE must be one of [${PNG_INTEL_SSE_POSSIBLE_VALUES}]")
  elseif(NOT ${PNG_INTEL_SSE} STREQUAL "off")
    if(${PNG_INTEL_SSE} STREQUAL "on")
      add_definitions(-DPNG_INTEL_SSE_OPT=1)
    endif()
  else()
    add_definitions(-DPNG_INTEL_SSE_OPT=0)
  endif()
endif()

if (PNG_STATIC)

  # Build static libary
  add_library(png STATIC)
  target_include_directories(png PRIVATE include)
  target_include_directories(png PUBLIC include/png)
  add_subdirectory(src)
  set_target_properties (png PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY 
      ${CMAKE_SOURCE_DIR}/lib/${CMAKE_C_COMPILER_ARCHITECTURE_ID}
  )
  target_link_libraries(png ${Z_LIBRARY} ${M_LIBRARY})

else()

  # Build shared libary
  add_library(png SHARED)
  target_include_directories(png PRIVATE include)
  target_include_directories(png PUBLIC include/png)
  add_subdirectory(src)
  set_target_properties (png PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
      ${CMAKE_SOURCE_DIR}/bin/${CMAKE_C_COMPILER_ARCHITECTURE_ID}
    ARCHIVE_OUTPUT_DIRECTORY 
      ${CMAKE_SOURCE_DIR}/lib/${CMAKE_C_COMPILER_ARCHITECTURE_ID}
  )
endif()

if (PNG_TOOLS)
  
  # Build tools in directory ${TOOLS_DIR} (extra/tools)
  include_directories(png PRIVATE include)
  link_directories(${CMAKE_SOURCE_DIR}/lib/${CMAKE_C_COMPILER_ARCHITECTURE_ID})
  link_libraries(png)

  add_executable(pngfix ${TOOLS_DIR}/pngfix.c)
  add_dependencies(pngfix png)

  add_executable(png-fix-itxt ${TOOLS_DIR}/png-fix-itxt.c)
  add_dependencies(png-fix-itxt png)
  add_executable(pngcp ${TOOLS_DIR}/pngcp.c)
  add_dependencies(pngcp png)
  add_executable(genpng ${TOOLS_DIR}/genpng.c)
  add_dependencies(genpng png)

  add_executable(makesRGB ${TOOLS_DIR}/makesRGB.c)
  add_executable(cvtcolor ${TOOLS_DIR}/cvtcolor.c)
  add_executable(checksum-icc ${TOOLS_DIR}/checksum-icc.c)

  set_property(TARGET pngfix png-fix-itxt pngcp genpng makesRGB cvtcolor checksum-icc
    PROPERTY RUNTIME_OUTPUT_DIRECTORY
      ${CMAKE_SOURCE_DIR}/bin/${CMAKE_C_COMPILER_ARCHITECTURE_ID})  
endif()

if (PNG_TESTS)

  # Build executables used for testing
  include_directories(png PRIVATE include)
  link_directories(${CMAKE_SOURCE_DIR}/lib/${CMAKE_C_COMPILER_ARCHITECTURE_ID})
  link_libraries(png)

  add_executable(pngvalid ${TESTS_DIR}/pngvalid.cpp)
  add_dependencies(pngvalid png)

  add_executable(pngtest ${TESTS_DIR}/pngtest.c)
  add_dependencies(pngtest png)

  set_property(TARGET pngvalid pngtest
    PROPERTY RUNTIME_OUTPUT_DIRECTORY
      ${CMAKE_SOURCE_DIR}/bin/${CMAKE_C_COMPILER_ARCHITECTURE_ID})  

endif()

# List all variables
if (VARLIST)
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
endif()
