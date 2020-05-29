cmake_minimum_required(VERSION 3.0.0)

project(
  sample
  VERSION 0.1.0
  LANGUAGES CXX
)

# C++規格
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug or Release
if(CMAKE_BUILD_TYPE)
  if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
  else()
    message(FATAL_ERROR "変数CMAKE_BUILD_TYPEにはDebugかReleaseを指定してください")
  endif()
else()
  message(FATAL_ERROR "変数CMAKE_BUILD_TYPEが定義されていません")
endif()

# ビルドコマンドを出力 (要 CMake 2.8.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
