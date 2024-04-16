if(PNG_INTEL_SSE)
  target_sources(png PRIVATE
    intel_init.c
    filter_sse2_intrinsics.c
  )
endif()