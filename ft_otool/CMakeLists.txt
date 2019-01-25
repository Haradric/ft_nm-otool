
cmake_minimum_required(VERSION 3.12.2 FATAL_ERROR)

project(ft_otool VERSION 0.1.0 LANGUAGES C)

add_executable(ft_otool)

target_compile_options(ft_otool PRIVATE -Wall -Wextra -Werror)

target_link_libraries(ft_otool
    PRIVATE
        libft
)

target_include_directories(ft_otool
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(ft_otool
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/ft_otool.h

    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_otool.c
        ${CMAKE_CURRENT_LIST_DIR}/src/file_types_handlers.c
        ${CMAKE_CURRENT_LIST_DIR}/src/macho32.c
        ${CMAKE_CURRENT_LIST_DIR}/src/macho64.c
        ${CMAKE_CURRENT_LIST_DIR}/src/fat.c
        ${CMAKE_CURRENT_LIST_DIR}/src/print.c
        ${CMAKE_CURRENT_LIST_DIR}/src/error.c
        ${CMAKE_CURRENT_LIST_DIR}/src/utils.c
        ${CMAKE_CURRENT_LIST_DIR}/src/mode.c
)
