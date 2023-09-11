#include "funcs.h"

int main()
    {
    text onegin = {nullptr, 0, nullptr, 0};
    //FILE *fp = open("Onegin.txt", "r");
    const char *file_name = "Onegin.txt";
    make_buf(&onegin.buf, &onegin.buf_size, file_name);
    make_lines_ptr(&onegin);
    }
