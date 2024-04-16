if(PNG_POWERPC_VSX)
  target_sources(png PRIVATE
    powerpc_init.c
    filter_vsx_intrinsics.c
  )
endif()