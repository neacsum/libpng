if (PNG_ARM_NEON)
  target_sources(png PRIVATE
    arm_init.c
    filter_neon.S
    filter_neon_intrinsics.c
    palette_neon_intrinsics.c
  )
endif()