
#include <unistd.h>

#include "ft_otool.h"

static void print_arch(uint32_t arch) {

    if (arch && arch != HOSTARCH) {
        if (arch)
            write(STDOUT_FILENO, " - ", 3);
        if (arch == CPU_TYPE_POWERPC)
            write(STDOUT_FILENO, "ppc", 3);
        else if (arch == CPU_TYPE_POWERPC64)
            write(STDOUT_FILENO, "ppc64", 5);
        else if (arch == CPU_TYPE_I386)
            write(STDOUT_FILENO, "i386", 4);
        else if (arch == CPU_TYPE_X86_64)
            write(STDOUT_FILENO, "x86_64", 6);
        else
            write(STDOUT_FILENO, "unknown", 7);
    }
}

void print_filename(const char *name, const char *sub, uint32_t arch) {

    if (name) {
        write(STDOUT_FILENO, name, ft_strlen(name));
        if (sub) {
            write(STDOUT_FILENO, "(", 1);
            write(STDOUT_FILENO, sub, ft_strlen(sub));
            print_arch(arch);
            write(STDOUT_FILENO, ")", 1);
        }
        write(STDOUT_FILENO, ":\n", 2);
    }
}
