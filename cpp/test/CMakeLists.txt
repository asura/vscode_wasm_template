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

if (EMSCRIPTEN)
target_link_libraries(
  Tester_${PROJECT_NAME}
  idbfs.js
)

set_target_properties(
  Tester_${PROJECT_NAME}
  PROPERTIES
  LINK_FLAGS
  "-s ASYNCIFY -s ASYNCIFY_STACK_SIZE=1048576 -s \"ASYNCIFY_IMPORTS=['mountIDBFS']\""
)
endif()
