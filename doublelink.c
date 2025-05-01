#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node* next;
};

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    struct Node *temp = NULL, *newnode, *tail;
    int n, i;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter coefficient for term %d of poly1: ", i + 1);
        scanf("%d", &newnode->coeff);
        printf("Enter exponent for term %d of poly1: ", i + 1);
        scanf("%d", &newnode->expo);
        newnode->next = NULL;

        if(poly1 == NULL) {
            poly1 = newnode;
            temp = poly1;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter coefficient for term %d of poly2: ", i + 1);
        scanf("%d", &newnode->coeff);
        printf("Enter exponent for term %d of poly2: ", i + 1);
        scanf("%d", &newnode->expo);
        newnode->next = NULL;

        if(poly2 == NULL) {
            poly2 = newnode;
            temp = poly2;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    struct Node *p1 = poly1, *p2 = poly2;
    while(p1 != NULL && p2 != NULL) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        newnode->next = NULL;

        if(p1->expo == p2->expo) {
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->expo > p2->expo) {
            newnode->coeff = p1->coeff;
            newnode->expo = p1->expo;
            p1 = p1->next;
        } else {
            newnode->coeff = p2->coeff;
            newnode->expo = p2->expo;
            p2 = p2->next;
        }

        if(result == NULL) {
            result = newnode;
            tail = result;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }


    while(p1 != NULL) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode == NULL) return 1;
        newnode->coeff = p1->coeff;
        newnode->expo = p1->expo;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        p1 = p1->next;
    }

    while(p2 != NULL) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode == NULL) return 1;
        newnode->coeff = p2->coeff;
        newnode->expo = p2->expo;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        p2 = p2->next;
    }

    printf("Resultant Polynomial: ");
    temp = result;
    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if(temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
