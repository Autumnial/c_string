#include "c_string.h"
#include <assert.h>
#include <stdio.h>

void printString(String string) {

    printf("size: %u, capacity: %u\n", string.size, string.capacity);
    printf("content: %s\n\n", string.content);
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
