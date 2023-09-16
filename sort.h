int linecmp(const char *lhs, const char *rhs);

int lencmp(const char *lhs, const char *rhs);

int epicmp(const char *lhs, const char *rhs);

void linesort(char **lines, size_t count, int (*comp)(const char *, const char *));

void bubblesort(char **lines, size_t count, int (*comp)(const char *, const char *));

void swap(char **a, char **b);

