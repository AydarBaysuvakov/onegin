#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

size_t file_size(FILE *fp)
    {
    assert(fp != NULL);

    struct stat sb;
    int fd = fileno(fp);

    if (fstat(fd, &sb) == -1)
        {
        return 0;
        }

    return sb.st_size;
    }

size_t lines_count(char *buf)
    {
    assert(buf != 0);

    size_t count = 0;

    for (; *buf != '\0'; buf++)
        {
        if (*buf == '\n')
            {
            count++;
            }
        }

    return count + 1;
    }

size_t strlen( const char *str )
    {
    assert(str != NULL);

    size_t size = 0;
    for (; *str; ++str, ++size)
        {
        /* Do nothing */
        }

    return size;
    }
