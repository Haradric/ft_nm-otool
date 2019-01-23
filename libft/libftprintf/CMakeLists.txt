
cmake_minimum_required(VERSION 3.12)

project(libftprintf)

set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_library(${PROJECT_NAME} STATIC "")

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        libft
)

target_compile_options(${PROJECT_NAME}
    PUBLIC
        -Wall
        -Wextra
        -Werror
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include/libftprintf.h
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_printf.h
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_printf.c
        ${CMAKE_CURRENT_LIST_DIR}/src/read_modifiers.c
        ${CMAKE_CURRENT_LIST_DIR}/src/read_modifiers2.c
        ${CMAKE_CURRENT_LIST_DIR}/src/read_arguments.c
        ${CMAKE_CURRENT_LIST_DIR}/src/read_arguments2.c
        ${CMAKE_CURRENT_LIST_DIR}/src/clean_description.c
        ${CMAKE_CURRENT_LIST_DIR}/src/useful_things.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_percent.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_x.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_s.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_ls.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_c.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_o.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_di.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_u.c
        ${CMAKE_CURRENT_LIST_DIR}/src/processing_p.c
        ${CMAKE_CURRENT_LIST_DIR}/src/wchar.c
)
