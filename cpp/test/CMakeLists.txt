include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}/third_party/Catch2/single_include
)

add_executable(
  Tester_${PROJECT_NAME}
  Tester.cpp
  double.cpp
  ifstream.cpp
  path_planning.cpp
  sum.cpp
  uint64_t.cpp
)
