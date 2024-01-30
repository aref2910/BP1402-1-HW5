#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getListLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

Node* findIntersection(int diff, Node* list1, Node* list2) {
    Node* current1 = list1;
    Node* current2 = list2;

    if (diff > 0) {
        for (int i = 0; i < diff; i++) {
            current1 = current1->next;
        }
    } else {
        for (int i = 0; i < -diff; i++) {
            current2 = current2->next;
        }
    }

    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return NULL;
}

int main() {
    Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);
    Node* list2 = createNode(9);
    list2->next = createNode(8);
    list2->next->next = list1->next->next;
    int len1 = getListLength(list1);
    int len2 = getListLength(list2);
    int diff = len1 - len2;
    Node* intersection = findIntersection(diff, list1, list2);

    // نمایش نتایج
    if (intersection != NULL) {
        printf("noghte taghto: %d\n", intersection->data);
    } else {
        printf("noghte taghato yaft nashod\n");
    }

    return 0;
}
