#ifndef __IOTEXT__
#define __IOTEXT__

/// @brief Структура элементов текста.
struct Text
    {
    char * buf;         //!< Указатель на буфер.
    size_t buf_size;    //!< Размер буфера.
    char ** lines;      //!< Массив указателей на начала строк.
    size_t n_lines;     //!< Количество строк в тексте.
    };

enum error_t
    {
    OK                    = 0,
    FILE_ERROR            = 1,
    ALLOCATION_ERROR      = 2,
    BUFFER_OVERFLOW_ERROR = 3,
    CALCULATION_ERROR     = 4
    };

const int EMPTY = 0;

error_t text_ctor(Text *text, const char *file_name);

error_t text_dtor(Text *text);

/// @brief Вычисляет размер файла и кладет его в buf_size, выделяет память под буфер buf и заполняет его символами из файла.
/// @param text указатель на структуру text.
/// @param file_name Название файла.
/// @return Код ошибки.
error_t make_buf(Text *text, const char *file_name);

/// @brief Заполняет буфер символами из файла.
/// @param buf Указатель на буфер символов.
/// @param fp Указатель на файл.
/// @return Код ошибки.
error_t fill_buf(char *buf, size_t buf_size, FILE *fp);

error_t lines_partition(Text *text);

error_t fill_lines(Text *text);

error_t text_to_file(Text* text, FILE* fp = stdout);

error_t print_text(Text* text, const char* file_name = NULL);

#endif //__IOTEXT__
