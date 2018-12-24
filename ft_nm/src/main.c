
#include <stdlib.h>   // EXIT_*
#include <fcntl.h>    // open()
#include <stdio.h>    // perror()
#include <sys/stat.h> // fstat()
#include <sys/mman.h> // mmap(), munmap()
#include <unistd.h>   // close()
//#include <ar.h>

#include "libft.h"
#include "nm.h"

static int	nm(int argc, const char *arg) {

	int			ret;
	int         fd;
	char        *ptr;
	struct stat statbuf;

	if ((fd = open(arg, O_RDONLY)) < 0 )
		terminate("nm", arg);

	if (fstat(fd, &statbuf) == -1)
		terminate("nm", "fstat");

	if (!S_ISREG(statbuf.st_mode) && !S_ISLNK(statbuf.st_mode))
		terminate_custom("nm", arg, "is not a regular file");

	if ((ptr = mmap(NULL, statbuf.st_size, \
					PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		terminate("nm", "mmap");

	if (argc != 2)
		ft_printf("\n%s:\n", arg);

	ret = nm_read_file(arg, ptr);

	if (munmap(ptr, statbuf.st_size) == -1)
		terminate("nm", "munmap");

	if (close(fd) == -1)
		terminate("nm", "close");

	return (ret);
}

int     main(int argc, char **argv) {

	size_t	i;
	int		ret;

//	 a.out if no args
    if (argc < 2)
		terminate_custom("error", "nm <input files>", "usage");

	i = 1;
	ret = 0;
	while (i < (size_t)argc) {
//		process ar archives
//		https://docs.oracle.com/cd/E36784_01/html/E36873/ar.h-3head.html
		ret += nm(argc, argv[i]);
		++i;
	}

    return (ret);
}
