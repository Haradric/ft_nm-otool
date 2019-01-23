/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "ft_nm.h"

static int nm_init(const char *arg, nm_obj_t *file) {

    ft_memset(file, 0, sizeof(*file));

    if ((file->fd = open(arg, O_RDONLY)) < 0 ) {
        error("nm", arg);
        return (1);
    }

    if (fstat(file->fd, &file->st) == -1) {
        error("nm", arg);
        return (1);
    }

    if ((!S_ISREG(file->st.st_mode) && !S_ISLNK(file->st.st_mode)) || \
        file->st.st_size == 0) {
        error_custom("nm", arg, "not a valid object file");
        return (1);
    }

    if ((file->ptr = mmap(NULL, file->st.st_size, \
                          PROT_READ, MAP_PRIVATE, file->fd, 0)) == MAP_FAILED) {
        error_custom("nm", arg, "can't map file into memory");
        return (1);
    }

    return (0);
}

static void nm_deinit(nm_obj_t *file) {

    if (file->ptr)
        munmap(file->ptr, file->st.st_size);

    if (file->fd >= 3)
        close(file->fd);
}

static int nm(int argc, const char *arg) {

    nm_obj_t info;
    int      ret = 1;

    if (!nm_init(arg, &info))
        ret = nm_read_file(arg, info.ptr, info.st.st_size, (argc == 2) ? 0 : 1);

    nm_deinit(&info);

    return (ret);
}

int     main(int argc, char **argv) {

    size_t i;
    int    ret;

    if (argc == 1)
        return (nm(argc, "a.out"));

    ret = 0;
    i = 1;
    while (i < (size_t)argc) {
        ret += nm(argc, argv[i]);
        i++;
    }

    return (ret);
}
