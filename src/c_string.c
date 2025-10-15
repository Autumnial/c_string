#include "c_string.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const uint16_t DEFAULT_CAPACITY = 64;

// static void grow(String s) { str_reserve(s, s.capacity * 2); }

String str_newWithCapacity(uint16_t capacity) {
    char *content = malloc(sizeof(char) * capacity);

    return (String){.content = content, .size = 0, .capacity = capacity};
};

String str_new() { return str_newWithCapacity(DEFAULT_CAPACITY); };

String str_fromCstr(char *str) {
    uint16_t size = strlen(str);

    char *content = malloc(sizeof(char) * size * 2);

    for (int i = 0; i < size; i++) {
        content[i] = str[i];
    }

    return (String){content, size, size * 2};
}

void str_destroy(String *str) { free(str->content); }

String str_copy(String *str) {
    char *content = malloc(sizeof(char) * str->size);
    memcpy(content, str->content, str->size);

    return (String){
        .size = str->size, .content = content, .capacity = str->capacity};
}

void str_reserve(String *str, uint16_t cap) {
    char *new_content = malloc(sizeof(char) * cap);
    memcpy(new_content, str->content, cap);
    free(str->content);
    str->content = new_content;
    str->size = strlen(str->content);
    str->capacity = cap;
}

void str_shrink_to_fit(String *str) { str_reserve(str, str->size); }

bool str_is_empty(String *str) { return str->size == 0; }

void str_clear(String *str) {
    free(str->content);
    str->content = malloc(sizeof(char) * DEFAULT_CAPACITY);
    str->size = 0;
}

// takes contents stored in string and returns it as a c_str
const char *str_c_str(String *str) {

    if (str->size + 1 >= str->capacity) {
        char *new_content = malloc(sizeof(char) * str->capacity * 2);
        memcpy(new_content, str->content, sizeof(char) * str->size);
        free(str->content);
        str->content = new_content;
    }

    str->content[str->size] = '\0';
    return str->content;
}
