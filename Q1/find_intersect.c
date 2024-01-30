#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
};

int getListLength( Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

 Node* findIntersection(struct Node* list1, struct Node* list2) {
    int len1 = getListLength(list1);
    int len2 = getListLength(list2);

     Node* current1 = list1;
     Node* current2 = list2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            current1 = current1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
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

 Node* createNode(int data) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

 Node* createList(int arr[], int n) {
     Node* head = NULL;
     Node* current = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 9, 8, 7};

Node* list1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
 Node* list2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    list2->next->next->next->next = list1->next->next;

    printf("list 1: ");
    displayList(list1);
    printf("list 2: ");
    displayList(list2);

    struct Node* intersection = findIntersection(list1, list2);

    if (intersection != NULL) {
        printf("noghte taghato: %d\n", intersection->data);
    } else {
        printf("hich noghtei yaft nashod.\n");
    }

    return 0;
}
