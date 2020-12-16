set(APP_NAME gale)

cmake_minimum_required(VERSION 3.10)

project(${APP_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/.build)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/.build)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries

INCLUDE_DIRECTORIES(src ${GTKMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})

# Sources START

set(FILES_SOURCE)

list(APPEND FILES_SOURCE
    src/synth/app/app.cpp
    src/synth/core/node/connection.cpp
    src/synth/core/node/node.cpp
    src/synth/core/project.cpp
    src/synth/core/node/oscillator/simple_oscillator.cpp
    src/synth/core/node/output/stream_output.cpp
    src/synth/core/node/port.cpp
    src/synth/app/project/project.cpp
    src/synth/app/project/project_node.cpp
    src/synth/ui/window_main/menu.cpp
    src/synth/ui/window_main/project_area.cpp
    src/synth/ui/window_main/window_main.cpp
    src/synth/ui/window_main/node_container_widget.cpp
    src/synth/ui/window_main/node_widget.cpp
    )
# Sources END

# exe = executable file, lib = shared library
set(target_type "exe")

# Target-specific parameters START

option(type "(native|lv2|vst). WARNING: only native is implemented." native)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/src/ports")
if(type STREQUAL "native")
    include("src/ports/native/CMakeLists.txt")
endif()

if(type STREQUAL "vst")
    message( FATAL_ERROR "VST build is not implemented." )
endif()

if(type STREQUAL "lv2")
    include("src/ports/lv2/CMakeLists.txt")
endif()

# Target-specific parameters END

set(all_code_files
    ${FILES_SOURCE}
    )

if (target_type STREQUAL "exe")
    add_executable(${APP_NAME} ${all_code_files})
endif()
if (target_type STREQUAL "lib")
    add_library(${APP_NAME} SHARED ${all_code_files})
endif()

target_link_libraries(${APP_NAME} ${GTKMM_LIBRARIES})