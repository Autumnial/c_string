#include "string.h"
#include <assert.h>
#include <stdio.h>

void printString(String s) {

    printf("size: %u, capacity: %u\n", s.size, s.capacity);
    printf("content: %s\n\n", s.content);
}

int main(void) {

    char  *test = "uwu owo";
    String test_str = str_fromCstr(test);

    assert(*test == *test_str.content);

    String test_str_2 = str_copy(test_str);

    printString(test_str);
    printString(test_str_2);

    assert(test_str.content != test_str_2.content);

    return 0;
}
