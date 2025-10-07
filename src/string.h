#pragma once

#include <stdint.h>
#include <stdlib.h>
typedef struct {
    char    *content;
    uint16_t size;
    uint16_t capacity;
} String;

String str_newWithCapacity(uint16_t capacity); 
String str_new(); 
