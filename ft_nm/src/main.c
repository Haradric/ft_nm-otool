
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "ft_nm.h"

static int nm(int argc, const char *arg) {

    struct stat statbuf;
    int         ret;
    int         fd;
    char        *ptr;

    if ((fd = open(arg, O_RDONLY)) < 0 )
        terminate("nm", arg);

    if (fstat(fd, &statbuf) == -1)
        terminate("nm", "fstat");

    if (!S_ISREG(statbuf.st_mode) && !S_ISLNK(statbuf.st_mode))
        terminate_custom("nm", arg, "is not a regular file");

    if ((ptr = mmap(NULL, statbuf.st_size, \
                    PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
        terminate("nm", "mmap");

    ret = nm_read_file((argc == 2) ? NULL : arg, NULL, ptr, statbuf.st_size);

    if (munmap(ptr, statbuf.st_size) == -1)
        terminate("nm", "munmap");

    if (close(fd) == -1)
        terminate("nm", "close");

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
