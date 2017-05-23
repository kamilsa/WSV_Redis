cmake_minimum_required(VERSION 3.3.0 FATAL_ERROR)
project(WSV_Redis LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 11)

include_directories(
        # Library headers.
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set(WSV_INCLUDE
    include/wsv/wsv.h
    )
set(WSV_SRC
        src/wsv/wsv_redis.cc
        include/wsv/wsv_redis.h)

set(LIBWSV_NAME wsv)
add_library(${LIBWSV_NAME}
    ${WSV_INCLUDE}
    ${WSV_SRC}
)

set(SOURCE_FILES main.cpp src/wsv/wsv_redis.cc)

add_executable(WSV_Redis ${SOURCE_FILES})

add_subdirectory(cpp_redis)

target_link_libraries(WSV_Redis
    cpp_redis
    )