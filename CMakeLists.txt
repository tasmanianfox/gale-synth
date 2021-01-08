cmake_minimum_required(VERSION 3.10)

set(APP_NAME gale)
project(${APP_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS core)

include_directories(src)
include(${wxWidgets_USE_FILE})

# Windows / Visual C++
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

# Sources START

set(FILES_SOURCE)

list(APPEND FILES_SOURCE
    src/gui/app/app.cpp
    src/core/node/connection.cpp
    src/core/node/node.cpp
    src/core/project.cpp
    src/core/node/oscillator/simple_oscillator.cpp
    src/core/node/output/stream_output.cpp
    src/core/node/port.cpp
    src/gui/app/project/project.cpp
    src/gui/app/project/project_node.cpp
    src/gui/windows/window_main/connections_widget.cpp
    src/gui/windows/window_main/menu.cpp
    src/gui/windows/window_main/project_area.cpp
    src/gui/windows/window_main/window_main.cpp
    src/gui/windows/window_main/node_container_widget.cpp
    src/gui/windows/window_main/node_port_widget.cpp
    src/gui/windows/window_main/node_widget.cpp
    )
# Sources END

# Target-specific parameters START

# app = executable file, lib = shared library
set(target_type "lib")
# native|lv2|vst
set(type "native")

if(type STREQUAL "native")
    include("src/targets/native/CMakeLists.txt")
    set(target_type "app")
endif()

if(type STREQUAL "vst")
    message( FATAL_ERROR "VST build is not implemented." )
endif()

if(type STREQUAL "lv2")
    include("src/targets/lv2/CMakeLists.txt")
endif()

# Target-specific parameters END

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/.build)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/.build)

if (target_type STREQUAL "app")
    add_executable(${APP_NAME} ${FILES_SOURCE})
endif()
if (target_type STREQUAL "lib")
    add_library(${APP_NAME} SHARED ${FILES_SOURCE})
endif()

target_link_libraries(${APP_NAME} ${wxWidgets_LIBRARIES})