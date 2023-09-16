#include <stdio.h>
#include "iotext.h"
#include "sort.h"

int main()
    {
    text onegin = {nullptr, 0, nullptr, 0};
    const char *file_name = "Onegin.txt";
    make_buf(&onegin, file_name);
    make_lines_ptr(&onegin);
    linesort(onegin.lines, onegin.line_count - 1, linecmp);
    print_text(&onegin);
    text_to_file(&onegin, "out.txt");
    }
