
cmake_minimum_required(VERSION 3.12.2 FATAL_ERROR)

project(nm VERSION 0.1.0 LANGUAGES C)

add_executable(nm)

target_compile_options(nm PRIVATE -Wall -Wextra -Werror)

target_link_libraries(nm
    PRIVATE
        libft
)

target_include_directories(nm
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(nm
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/nm.h

    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
        ${CMAKE_CURRENT_LIST_DIR}/src/nm.c
        ${CMAKE_CURRENT_LIST_DIR}/src/sort.c
		${CMAKE_CURRENT_LIST_DIR}/src/print.c
        ${CMAKE_CURRENT_LIST_DIR}/src/error.c
		${CMAKE_CURRENT_LIST_DIR}/src/macho32.c
		${CMAKE_CURRENT_LIST_DIR}/src/macho64.c
)
