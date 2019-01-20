
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "ft_otool.h"

static int otool(const char *arg) {

    struct stat statbuf;
    int         ret;
    int         fd;
    char        *ptr;

    if ((fd = open(arg, O_RDONLY)) < 0 )
        terminate("otool", arg);

    if (fstat(fd, &statbuf) == -1)
        terminate("otool", arg);

    if (!S_ISREG(statbuf.st_mode) && !S_ISLNK(statbuf.st_mode))
        terminate_custom("nm", arg, "is not a regular file");

    if (statbuf.st_size == 0)
        terminate_custom("otool", arg, "the file is empty");

    if ((ptr = mmap(NULL, statbuf.st_size, \
                    PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
        terminate_custom("otool", arg, "can't map file into memory");

    ret = otool_read_file(arg, NULL, ptr, statbuf.st_size);

    if (munmap(ptr, statbuf.st_size) == -1)
        terminate("otool", arg);

    if (close(fd) == -1)
        terminate("otool", arg);

    return (ret);
}

int     main(int argc, char **argv) {

    size_t i;
    int    ret;

    if (argc == 1)
        return (otool("a.out"));

    ret = 0;
    i = 1;
    while (i < (size_t)argc) {
        ret += otool(argv[i]);
        i++;
    }

    return (ret);
}
