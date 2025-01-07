#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct List {
    struct Node *head;
} List;

void insert(List *list, int num) {
    Node *new = malloc(sizeof(Node));
    new->val = num;

    if (list->head == NULL) {
        list->head = new;
        new->next = NULL;
        return;
    }
    
    if (list->head->val >= num) {
        new->next = list->head;
        list->head = new;
        return;
    }

    Node *prev = list->head;
    Node *cur = prev->next;
    while (cur != NULL) {
        if (cur->val >= num) {
            prev->next = new;
            new->next = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    prev->next = new;
    new->next = NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) exit(1);
    char path[100] = {'\0'};
    strcat(path, "inputs/"); 
    strcat(path, argv[1]);
    strcat(path, ".txt");

    FILE *file = fopen(path, "r");
    if (file == NULL) exit(1);

    List list = {};
    char buf[16];
    while (fgets(buf, sizeof(buf), file) != NULL) {
        int num;
        sscanf(buf, "%d", &num);
        insert(&list, num);
    }
    fclose(file);

    Node *cur = list.head;
    while (cur->next != NULL) {
        Node *next = cur->next;
        if (next->val < cur->val) {
            printf("list isn't sorted\n");
            exit(1);
        }
        cur = cur->next;
    }

    cur = list.head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }

    printf("success\n");
    return 0;
}
