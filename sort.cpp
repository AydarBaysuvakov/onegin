#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "sort.h"
#include "count.h"

int linecmp(const void *lhs, const void *rhs)
    {
    assert(lhs != NULL);
    assert(rhs != NULL);

    if (lhs == rhs)
        {
        return 0;
        }

    const char* leftline  = (const char*) lhs;
    const char* rightline = (const char*) rhs;

    while (*leftline && !isalpha(*leftline))
        {
        leftline++;
        }

    while (*rightline && !isalpha(*rightline))
        {
        rightline++;
        }

    while (*leftline && *rightline && toupper(*leftline) == toupper(*rightline))
        {
        leftline++;
        rightline++;
        }

    return toupper(*leftline) - toupper(*rightline);

    }

int lencmp(const void *lhs, const void *rhs)
    {
    assert(lhs != NULL);
    assert(rhs != NULL);

    return strlen((const char *) lhs) - strlen((const char *) rhs);

    }

int epigraph_cmp(const void *lhs, const void *rhs)
    {
    assert(lhs != NULL);
    assert(rhs != NULL);

    if (lhs == rhs)
        {
        return 0;
        }

    const char* leftline  = (char*) lhs + strlen((const char*) lhs);
    const char* rightline = (char*) rhs + strlen((const char*) rhs);

    while (!isalpha(*leftline))
        {
        leftline--;
        }

    while (!isalpha(*rightline))
        {
        rightline--;
        }

    while (*leftline && *rightline && toupper(*leftline) == toupper(*rightline))
        {
        leftline--;
        rightline--;
        }

    return toupper(*leftline) - toupper(*rightline);

    }


void sort_lines(void **lines, size_t count, size_t size, int (*comp)(const void *, const void *))
    {
    if (count < 2)
        {
        return;
        }

    if (count == 2)
        {
        if (comp(lines[0], lines[1]) > 0)
            {
            swap(lines, lines + 1, size);
            }
        return;
        }

    void *del   = *(lines + count / 2);
    void **left  = lines;
    void **right = lines + count - 1;

    while (left != right && left != NULL && right != NULL)
        {
        while (comp(*left, del) < 0)
            {
            left++;
            if (left == right)
                {
                break;
                }
            }

        while (comp(*right, del) > 0)
            {
            right--;
            if (left == right)
                {
                break;
                }
            }

        swap(left, right, size);
        }

    if (left - lines > 1)
        {
        sort_lines(lines, left - lines, size, comp);
        }

    if (count - (left + 1 - lines) > 1)
        {
        sort_lines(left + 1, count - (left + 1 - lines), size, comp);
        }
    }


void bubblesort(void **lines, size_t count, size_t size, int (*comp)(const void *, const void *))
    {
    for (size_t i = 0; i < count; i++)
        {
        for (size_t j = 0; j < count - i - 1; j++)
            {
            if (comp(lines[j], lines[j + 1]) > 0)
                {
                swap(lines + j, lines + j + 1, size);
                }
            }
        }
    }

void swap(void *a, void *b, size_t size)
    {
    assert(a != NULL);
    assert(b != NULL);
    assert(size > 0);

    size_t i = 0;

    while (size >= sizeof(long long))
        {
        long long c = ((long long*) a)[i];
        ((long long*) a)[i] = ((long long*) b)[i];
        ((long long*) b)[i] = c;
        size -= sizeof(long long);
        i += sizeof(long long);
        }

    while (size >= sizeof(int))
        {
        int c = ((int*) a)[i];
        ((int*) a)[i] = ((int*) b)[i];
        ((int*) b)[i] = c;
        size -= sizeof(int);
        i += sizeof(int);
        }

    while (size >= sizeof(char))
        {
        char c = ((char*) a)[i];
        ((char*) a)[i] = ((char*) b)[i];
        ((char*) b)[i] = c;
        size -= sizeof(char);
        i += sizeof(char);
        }
    }
