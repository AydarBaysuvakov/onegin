/// @brief Структура элементов текста.
struct text
    {
    char * buf;         //!< Указатель на буфер.
    size_t buf_size;    //!< Размер буфера.
    char ** lines;      //!< Массив указателей на начала строк.
    size_t line_count;  //!< Количество строк в тексте.
    };

/// @brief Вычисляет размер файла и кладет его в buf_size, выделяет память под буфер buf и заполняет его символами из файла.
/// @param text_p указатель на структуру text.
/// @param file_name Название файла.
/// @return Указатель на буфер.
char *make_buf(text *text_p, const char *file_name);

/// @brief Заполняет буфер символами из файла.
/// @param buf_p Указатель на буфер символов.
/// @param fp Указатель на файл.
/// @return Указатель на буфер.
char *fill_buf(char *buf_p, FILE *fp);

char **make_lines_ptr(text *text_p);

char **fill_line_buf(text *text_p);

size_t print_text(text* text_p);

size_t text_to_file(text* text_p, const char* file_name);
