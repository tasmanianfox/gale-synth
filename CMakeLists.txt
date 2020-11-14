set(APP_NAME gale)

cmake_minimum_required(VERSION 3.10)

project(${APP_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .build)

# Sources START

set(FILES_SOURCE)
set(FILES_HEADERS)

list(APPEND FILES_HEADERS)

list(APPEND FILES_SOURCE
    src/ports/native/main.c
    )

set(all_code_files
    ${FILES_SOURCE}
    )

# Sources END

option(type "(native|lv2|vst). WARNING: only native is implemented." native)

if(type STREQUAL "native")
    add_subdirectory(src/ports/native)
endif()

if(type STREQUAL "vst")
    message( FATAL_ERROR "VST build is not implemented." )
endif()

if(type STREQUAL "lv2")
    message( FATAL_ERROR "LV2 build is not implemented." )
endif()

add_executable(${APP_NAME} ${all_code_files})