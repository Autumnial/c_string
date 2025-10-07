#pragma once

#include <stdint.h>
typedef struct {
    char    *content;
    uint16_t size;
    uint16_t capacity;
} String;

String str_newWithCapacity(uint16_t capacity); 
String str_new(); 
String str_fromCstr(char* string);
void str_destroy(String s);
String str_copy(String s); 
