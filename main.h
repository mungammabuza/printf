#ifndef MAIN_H
#define MAIN_H

print_uToBinary(va_list arg);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int  printf_project(va_list types, char buffer[ ], int flags, int width, int precision, int size);

#endif
