#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc < 2) exit(1);
    char path[100] = {'\0'};
    strcat(path, "inputs/"); 
    strcat(path, argv[1]);
    strcat(path, ".txt");

    FILE *file = fopen(path, "w");
    if (file == NULL) exit(1);

    time_t t;
    srand(time(&t));

    int n;
    sscanf(argv[1], "%d", &n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", rand() % n);
    }

    fclose(file);
    return 0;
}
