#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "iotext.h"
#include "count.h"
//reading
//linecount
//qsort

char *make_buf(text *text_p, const char *file_name)
    {
    assert(text_p != NULL);
    assert(file_name != NULL);

    // Открываем файл.
    FILE *fp = fopen(file_name, "r");
    //assert(fp != nullptr);
    if (fp == nullptr)
        {
        printf("ERROR: cannot open file");
        return nullptr;
        }

    // Количество символов в файле.
    if (!(text_p->buf_size = file_size(fp)))
        {
        printf("ERROR: cannot open file");
        return nullptr;
        }

    // Освобождаем буффер, если он занят, выделяем под него память.
    if (text_p->buf != nullptr)
        {
        free(text_p->buf);
        }
    text_p->buf = (char*) malloc((text_p->buf_size + 1) * sizeof(char));
    if (text_p->buf == nullptr)
        {
        printf("ERROR: cannot allocate memory");
        free(text_p->buf);
        return nullptr;
        }

    // Заполняем буфер символами.
    text_p->buf = fill_buf(text_p->buf, fp);

    // Закрываем файл.
    fclose(fp);

    return text_p->buf;
    }

char *fill_buf(char *buf_p, FILE *fp)
    {
    assert(fp != NULL);

    char *buf_copy = buf_p;
    char c = fgetc(fp);

    while (c != EOF)
        {
        *buf_p++ = c;
        c = fgetc(fp);
        }

    return buf_copy;
    }

char **make_lines_ptr(text *text_p)
    {
    assert(text_p != NULL);

    text_p->line_count = lines_count(text_p->buf);

    // Освобождаем буффер, если он занят, выделяем под него память.
    if (text_p->lines != nullptr)
        {
        free(text_p->lines);
        }
    text_p->lines = (char**) malloc((text_p->line_count + 1) * sizeof(char*));
    if (text_p->lines == nullptr)
        {
        printf("ERROR: cannot allocate memory");
        free(text_p->lines);
        return nullptr;
        }

    // Заполняем буфер символами.
    text_p->lines = fill_line_buf(text_p);

    return text_p->lines;
    }

char **fill_line_buf(text *text_p)
    {
    assert(text_p != NULL);

    char **line = text_p->lines;
    char *buf = text_p->buf;
    *line++ = buf;
    size_t sym = 0;

    for (; *buf != '\0'; buf++, sym++)
        {
        if (*buf == '\n')
            {
            *buf = '\0';
            *line++ = buf + 1;
            }
        }
    *line = nullptr;

    return text_p->lines;
    }


size_t print_text(text* text_p)
    {
    assert(text_p != NULL);

    char** line = text_p->lines;
    size_t count = 0;

    for (;*line != nullptr; line++, count++)
        {
        printf("%s \n", *line);
        }

    return count;
    }

size_t text_to_file(text* text_p, const char* file_name)
    {
    assert(text_p != NULL);

    FILE *fp = fopen(file_name, "w");

    char** line = text_p->lines;
    size_t count = 0;

    for (;*line != nullptr; line++, count++)
        {
        fprintf(fp, "%s \n", *line);
        }

    fclose(fp);

    return count;
    }
