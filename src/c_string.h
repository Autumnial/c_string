#ifndef STRING_H
#define STRING_H

#include <stdint.h>
#include <stdbool.h>
typedef struct {
    char    *content;
    uint16_t size;
    uint16_t capacity;
} String;

String str_newWithCapacity(uint16_t capacity);
String str_new();
String str_fromCstr(char *string);
void   str_destroy(String *str);
String str_copy(String *str);

void str_reserve(String *str, uint16_t cap);
void str_shrink_to_fit(String *str);
bool str_is_empty(String *str);
void str_clear(String *str);

const char *str_c_str(String *str); 


#endif
