#ifndef __SORT__
#define __SORT__

int linecmp(const void *lhs, const void *rhs);

int lencmp(const void *lhs, const void *rhs);

int epigraph_cmp(const void *lhs, const void *rhs);

void sort_lines(void **lines, size_t count, size_t size, int (*comp)(const void *, const void *));

void bubblesort(void **lines, size_t count, size_t size, int (*comp)(const void *, const void *));

void swap(void *a, void *b, size_t size);

#endif //__SORT__
