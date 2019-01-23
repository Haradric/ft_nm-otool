
cmake_minimum_required(VERSION 3.12)

include(${CMAKE_CURRENT_LIST_DIR}/libftprintf/CMakeLists.txt)

project(libft)

set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_library(${PROJECT_NAME} STATIC "")

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        libftprintf
)

target_compile_options(${PROJECT_NAME}
    PUBLIC
        -Wall
        -Wextra
        -Werror
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/libft.h
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_atoi.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_bzero.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_isalnum.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_isalpha.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_isascii.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_isdigit.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_isprint.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_isspace.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_itoa.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstadd.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstdel.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstdelone.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstdup.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstdupelem.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstfind.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstfreeelem.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstfreelist.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstgetelem.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstgetlast.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstinsert.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstisinlist.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstiter.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstlen.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstmap.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstnew.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstpushback.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstpushfront.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstremoveelem.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstrsort.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstsort.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_lstswap.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memalloc.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memccpy.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memchr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memcmp.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memcpy.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memdel.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memmove.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_memset.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_nbrlen.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_power.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putchar.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putchar_fd.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putendl.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putendl_fd.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putnbr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putnbr_fd.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putstr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_putstr_fd.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_realloc.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strcat.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strchr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strclr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strcmp.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strcpy.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strdel.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strdup.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strequ.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_striter.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_striteri.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strjoin.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strlcat.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strlen.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strmap.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strmapi.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strncat.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strncmp.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strncpy.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strnequ.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strnew.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strnstr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strrchr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strsplit.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strstr.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strsub.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strtolower.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strtoupper.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_strtrim.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_tolower.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_toupper.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_wcharlen.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_wchartochar.c
)
