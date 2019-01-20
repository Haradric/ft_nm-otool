
#include <unistd.h>

#include "ft_otool.h"

static void print_text_sect(void *ptr, uint32_t size, uint32_t vm_addr) {

    char const *msg = "Contents of ("SEG_TEXT","SECT_TEXT") section\n";
    int const  step = 16;
    void   *end;
    size_t i;

    write(STDOUT_FILENO, msg, ft_strlen(msg));

    end = ptr + size;
    while (ptr < end) {
        write(STDOUT_FILENO, uint32_hex_str(vm_addr), 8);
        write(STDOUT_FILENO, "\t", 1);
        i = 0;
        while (ptr + i < end && i < step) {
            write(STDOUT_FILENO, uint8_hex_str(*(uint8_t *)(ptr + i)), 2);
            write(STDOUT_FILENO, " ", 1);
            i++;
        }
        write(STDOUT_FILENO, "\n", 1);
        vm_addr += step;
        ptr += step;
    }
    write(STDOUT_FILENO, "\n", 1);
}

static void read_segment(void *ptr, struct segment_command *cmd) {

    struct section *sect;
    size_t i;

    sect = (void *)cmd + sizeof(*cmd);
    i = 0;
    while (i < cmd->nsects) {
        if (!ft_strcmp(sect[i].segname, SEG_TEXT) && \
            !ft_strcmp(sect[i].sectname, SECT_TEXT))
            print_text_sect(ptr + sect[i].offset, sect[i].size, sect[i].addr);
        i++;
    }
}

void get_text_sect32(void *ptr) {

    struct load_command *lc;
    uint32_t ncmds;

    lc = ptr + sizeof(struct mach_header);
    ncmds = ((struct mach_header *)ptr)->ncmds;

    while (ncmds--) {
        if (lc->cmd == LC_SEGMENT) {
            read_segment(ptr, (void *)lc);
        }
        lc = (void *)lc + lc->cmdsize;
    }
}
