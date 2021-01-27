add_compile_definitions(GALE_TYPE_LV2)

find_library(LV2 NAMES lv2)

set(target_type "lib")

# Sources START

list(APPEND FILES_HEADERS)

list(APPEND FILES_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/lv2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/lv2_ui.cpp
    )

# Sources END

