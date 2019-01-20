
#include <unistd.h>

#include "ft_otool.h"

void print_filename_arch(const char *name, uint32_t cpu) {

    if (cpu == CPU_TYPE_POWERPC)
        print_filename(name, "ppc");
    else if (cpu == CPU_TYPE_POWERPC64)
        print_filename(name, "ppc64");
    else if (cpu == CPU_TYPE_I386)
        print_filename(name, "i386");
    else if (cpu == CPU_TYPE_X86_64)
        print_filename(name, "x86_64");
}

void print_filename(const char *name, const char *sub) {

    if (name) {
        write(STDOUT_FILENO, "\n", 1);
        write(STDOUT_FILENO, name, ft_strlen(name));
        if (sub) {
            write(STDOUT_FILENO, "(", 1);
            write(STDOUT_FILENO, sub, ft_strlen(sub));
            write(STDOUT_FILENO, ")", 1);
        }
        write(STDOUT_FILENO, ":\n", 2);
    }
}
