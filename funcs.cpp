#include <stdio.h>
//reading
//linecount
//sort

char *make_buf(char **buf_p, size_t *buf_size_p, const char *file_name)
    {
    assert(buf_size != NULL);
    assert(file_name != NULL);
    assert(buf_size != buf);
    assert(file_name != buf);
    assert(buf_size != file_name);

    // Открываем файл.
    FILE *fp = fopen(file_name, "r");
    //assert(fp != nullptr);
    if (fp == nullptr)
        {
        printf("ERROR: cannot open file");
        return nullptr;
        }

    // Количество символов в файле.
    *buf_size_p = file_size(fp);

    // Освобождаем буффер, если он занят, выделяем под него память.
    if (buf_p != nullptr)
        {
        free(buf_p);
        }
    buf_p = (char*) malloc((*buf_size_p + 1) * sizeof(char));
    if (buf_p == nullptr)
        {
        printf("ERROR: cannot allocate memory");
        free(buf_p);
        return nullptr;
        }

    // Заполняем буфер символами.
    buf_p = fill_buf(buf_p, fp);

    // Закрываем файл.
    fclose(fp);

    return buf_p;
    }

size_t file_size(FILE *fp)
    {
    size_t size = 0;

    for (; *fp != EOF; size++, fp++)

    return size;
    }

char *fill_buf(char *buf_p, FILE *fp)
    {
    char *buf_copy = buf_p;
    while (*fp != EOF)
        {
        *buf_p++ = *fp++
        }
    return buf_copy;
    }

char **make_lines_ptr(text *text_p)
    {

    }
