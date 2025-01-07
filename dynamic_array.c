#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Array {
    int *ptr;
    size_t len;
    size_t cap;
} Array;

void insert(Array *array, int num) {
    int idx = 0;

    for (size_t i = 0; i < array->len; i++) {
        if (array->ptr[i] >= num) {
            idx = i;
            goto post;
        }
    }
    idx = array->len;

    post:
    if (array->len == array->cap) {
        array->cap *= 2;
        array->ptr = realloc(array->ptr, array->cap * sizeof(int));
    }

    for (size_t i = array->len; i > idx; i--) {
        array->ptr[i] = array->ptr[i-1];
    }
    array->len++;
    array->ptr[idx] = num;
}

int main(int argc, char **argv) {
    if (argc < 2) exit(1);
    char path[100] = {'\0'};
    strcat(path, "inputs/"); 
    strcat(path, argv[1]);
    strcat(path, ".txt");

    FILE *file = fopen(path, "r");
    if (file == NULL) exit(1);

    Array array = {
        malloc(sizeof(int)),
        0,
        1
    };
    char buf[16];
    while (fgets(buf, sizeof(buf), file) != NULL) {
        int num;
        sscanf(buf, "%d", &num);
        insert(&array, num);
    }
    fclose(file);
    
    for (int i = 0; i < array.len-1; i++) {
        if (array.ptr[i] > array.ptr[i+1]) {
            printf("array isn't sorted\n");
            exit(1);
        }
    }
    printf("success\n");
    return 0;
}
