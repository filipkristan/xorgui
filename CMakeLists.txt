cmake_minimum_required(VERSION 3.28)
project(xorgui C)

set(CMAKE_C_STANDARD 11)

add_library(xorgui STATIC
        include/XORGUI/xorgui.c
        include/XORGUI/xorgui.h
        include/XORGUI/checklist.c
        include/XORGUI/checklist.h
        include/XORGUI/makeRect.c
        include/XORGUI/makeRect.h
        include/XORGUI/checkbox.c
        include/XORGUI/checkbox.h
        include/XORGUI/update.c
        include/XORGUI/update.h
        include/XORGUI/button.c
        include/XORGUI/button.h
        include/XORGUI/label.c
        include/XORGUI/label.h
        include/XORGUI/misc.h
        include/XORGUI/misc.c
)

target_include_directories(xorgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(DIRECTORY include/ DESTINATION include)
install(TARGETS xorgui DESTINATION lib)
target_link_libraries(xorgui PUBLIC X11)

add_executable(demo src/main.c)
target_include_directories(demo PRIVATE /usr/local/include)
target_link_directories(demo PRIVATE /usr/local/lib)
target_link_libraries(demo PRIVATE xorgui X11)