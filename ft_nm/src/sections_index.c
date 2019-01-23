/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void read_segment32(struct load_command *lc) {

    struct segment_command *segment;
    struct section         *section;
    index_t                *index;
    uint32_t               i;

    segment = (struct segment_command *)lc;
    section = (struct section *)((void*)segment + sizeof(*segment));
    index = get_sect_index();

    i = 0;
    while (i < segment->nsects) {
        if (!ft_strcmp(section->segname, SEG_TEXT) && \
            !ft_strcmp(section->sectname, SECT_TEXT))
            index->text = index->nsects + 1;
        else if (!ft_strcmp(section->segname, SEG_DATA) && \
                 !ft_strcmp(section->sectname, SECT_DATA))
            index->data = index->nsects + 1;
        else if (!ft_strcmp(section->segname, SEG_DATA) && \
                 !ft_strcmp(section->sectname, SECT_BSS))
            index->bss = index->nsects + 1;
        index->nsects++;
        section++;
        i++;
    }
}

static void read_segment64(struct load_command *lc) {

    struct segment_command_64 *segment;
    struct section_64         *section;
    index_t                   *index;
    uint32_t                  i;

    segment = (struct segment_command_64 *)lc;
    section = (struct section_64 *)((void*)segment + sizeof(*segment));
    index = get_sect_index();

    i = 0;
    while (i < segment->nsects) {
        if (!ft_strcmp(section->segname, SEG_TEXT) && \
            !ft_strcmp(section->sectname, SECT_TEXT))
            index->text = index->nsects + 1;
        else if (!ft_strcmp(section->segname, SEG_DATA) && \
                 !ft_strcmp(section->sectname, SECT_DATA))
            index->data = index->nsects + 1;
        else if (!ft_strcmp(section->segname, SEG_DATA) && \
                 !ft_strcmp(section->sectname, SECT_BSS))
            index->bss = index->nsects + 1;
        index->nsects++;
        section++;
        i++;
    }
}

void index_sections(uint32_t ncmds, void *lc_start) {

    struct load_command *lc;
    uint32_t i;

    ft_memset(get_sect_index(), 0, sizeof(index_t));
    lc = lc_start;

    i = 0;
    while (i < ncmds) {
        if (lc->cmd == LC_SEGMENT)
            read_segment32(lc);
        else if (lc->cmd == LC_SEGMENT_64)
            read_segment64(lc);
        lc = (void *)lc + lc->cmdsize;
        i++;
    }
}

index_t *get_sect_index(void) {
    static index_t index = {0, 0, 0, 0};

    return (&index);
}
