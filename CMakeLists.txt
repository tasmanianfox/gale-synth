set(APP_NAME gale)

cmake_minimum_required(VERSION 3.10)

project(${APP_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .build)
set(CMAKE_BUILD_FILES_DIRECTORY .build)
set(CMAKE_BUILD_DIRECTORY .build)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries

INCLUDE_DIRECTORIES(src ${GTKMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})

# Sources START

set(FILES_SOURCE)
# set(FILES_HEADERS)

# list(APPEND FILES_HEADERS
#     # src/synth/ui/window_main/menu.h
#     src/synth/ui/window_main/window_main.hpp
#     )

list(APPEND FILES_SOURCE
    # src/synth/ui/window_main/menu.c
    src/synth/app/app.cpp
    src/synth/ui/window_main/window_main.cpp
    )


# Sources END

option(type "(native|lv2|vst). WARNING: only native is implemented." native)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/src/ports")
if(type STREQUAL "native")
    include("src/ports/native/CMakeLists.txt")
endif()

if(type STREQUAL "vst")
    message( FATAL_ERROR "VST build is not implemented." )
endif()

if(type STREQUAL "lv2")
    message( FATAL_ERROR "LV2 build is not implemented." )
endif()

set(all_code_files
    ${FILES_SOURCE}
    )

add_executable(${APP_NAME} ${all_code_files})
target_link_libraries(${APP_NAME} ${GTKMM_LIBRARIES})