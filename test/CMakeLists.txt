include_directories(
  ${PROJECT_SOURCE_DIR}/third_party/Catch2/single_include
)

add_executable(
  Tester_${PROJECT_NAME}
  Tester.cpp
)
