#include <stdlib.h>
#include <stdio.h>
#include "iotext.h"
#include "sort.h"

int main()
    {
    Text onegin = {nullptr, 0, nullptr, 0};
    const char *file_name = "Onegin.txt";
    text_ctor(&onegin, file_name);

    sort_lines((void **) onegin.lines, onegin.n_lines, sizeof(onegin.lines), linecmp);
    print_text(&onegin);
    print_text(&onegin, "out.txt");

    text_dtor(&onegin);
    }
