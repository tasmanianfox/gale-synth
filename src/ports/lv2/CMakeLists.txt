pkg_check_modules(LV2 lv2 REQUIRED)

# Sources START

list(APPEND FILES_HEADERS)

list(APPEND FILES_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    )

# Sources END


set(target_type "lib")