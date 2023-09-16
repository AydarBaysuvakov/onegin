#include <stdio.h>
#include <assert.h>
#include "sort.h"
#include "count.h"

int linecmp(const char *lhs, const char *rhs)
    {
    assert(lhs != NULL);
    assert(rhs != NULL);

    while ((*lhs - 'A' < 0) || (*lhs - 'Z' > 0))
        {
        lhs++;
        }

    while ((*rhs - 'A' < 0) || (*rhs - 'Z' > 0))
        {
        rhs++;
        }

    while (*lhs && *rhs && *lhs == *rhs)
        {
        lhs++;
        rhs++;
        }

    return *lhs - *rhs;

    }

int lencmp(const char *lhs, const char *rhs)
    {
    assert(lhs != NULL);
    assert(rhs != NULL);

    return strlen(lhs) - strlen(rhs);

    }

int epicmp(const char *lhs, const char *rhs)
    {
    assert(lhs != NULL);
    assert(rhs != NULL);

    const char *le = lhs + strlen(lhs), *re = rhs + strlen(rhs);

    while (le != lhs && re != rhs && *lhs == *rhs)
        {
        lhs--;
        rhs--;
        }

    return *lhs - *rhs;

    }

void linesort(char **lines, size_t count, int (*comp)(const char *, const char *))
    {
    if (count < 2)
        {
        return;
        }

    if (count == 2)
        {
        if (*lines && *(lines + 1) && comp(*lines, *(lines + 1)) > 0)
            {
            swap(lines, lines + 1);
            }
        return;
        }

    char *del = *(lines + count / 2);
    char **left = lines, **right = lines + count;

    while (left != right && left != nullptr)
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

        swap(left, right);
        }

    if (left - lines > 1)
        {
        linesort(lines, left - lines, comp);
        }

    if (count - (left + 1 - lines) > 1)
        {
        linesort(left + 1, count - (left + 1 - lines), comp);
        }
    }


void bubblesort(char **lines, size_t count, int (*comp)(const char *, const char *))
    {
    if (count < 2)
        {
        return;
        }

    if (count == 2)
        {
        if (*lines && *(lines + 1) && comp(*lines, *(lines + 1)) > 0)
            {
            swap(lines, lines + 1);
            }
        return;
        }

    int iter = 0;
    for (; iter < count; iter++)
        {
        char **line = lines;
        for (; line < lines + count - iter - 1; line++)
            {
            if (*line && *(line + 1) && comp(*lines, *(lines + 1)) > 0)
                {
                swap(lines, lines + 1);
                }
            }
        }
    }

void swap(char **a, char **b)
    {
    char *c = *a;
    *a = *b;
    *b = c;
    }
