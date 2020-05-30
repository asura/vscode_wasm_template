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
  )
endif()
