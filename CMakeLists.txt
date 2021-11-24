cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(code03)

# 添加自定义cmake文件目录
# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# 使用Utility.cmake
# include(Utility)

find_package(Git QUIET)
if(GIT_FOUND)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY
      ${CMAKE_SOURCE_DIR}
    )
  execute_process(
    COMMAND ${GIT_EXECUTABLE} symbolic-ref --short -q HEAD
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY
      ${CMAKE_SOURCE_DIR}
    )
  execute_process(
  COMMAND ${GIT_EXECUTABLE} log -1 --format=%ad --date=local
    OUTPUT_VARIABLE GIT_DATE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY
      ${CMAKE_SOURCE_DIR}
  )
endif()

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.cc.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.cc
  @ONLY
  )

set(SOURCES main.cc version.cc)

add_executable(main ${SOURCES})