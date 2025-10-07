#pragma once

#include <stdint.h>
#include <stdlib.h>
typedef struct {
    char    *content;
    uint16_t size;
    uint16_t capacity;
} String;

String str_newWithCapacity(uint16_t capacity) {
    char *content = malloc(sizeof(char) * capacity);

    return (String){.content = content, .size = 0, .capacity = capacity};
};

String str_new() { return str_newWithCapacity(64); }
