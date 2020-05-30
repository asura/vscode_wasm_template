include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

add_executable(
  sample
  main.cpp
)

if (EMSCRIPTEN)
  add_executable(
    interface
    interface.cpp
    ShapefileReader.cpp
  )

  set_target_properties(
    interface
    PROPERTIES
    LINK_FLAGS
    "-s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\"]'"
  )
endif()
