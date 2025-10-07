#include "string.h"
#include <stdlib.h>
#include <string.h>

String str_newWithCapacity(uint16_t capacity) {
    char *content = malloc(sizeof(char) * capacity);

    return (String){.content = content, .size = 0, .capacity = capacity};
};

String str_new() { return str_newWithCapacity(64); };

String str_fromCstr(char *str) {
    int size = strlen(str);

    char *content = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++) {
        content[i] = str[i];
    }

    return (String){content, size, size};
}

void str_destroy(String s) { free(s.content); }

String str_copy(String s) {
    char *content = malloc(sizeof(char) * s.size);
    memcpy(content, s.content, s.size);

    return (String){.size = s.size, .content = content, .capacity = s.size};
}
