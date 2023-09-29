// Question 1

/*
    Program to implement polynomial expression using a singly linked list.
    time complexity is O(n)
    space complexity is O(n)
*/
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(struct Term **poly, int coefficient, int exponent)
{
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        struct Term *current = *poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL)
        {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    struct Term *polynomial = NULL;

    // Adding terms to the polynomial
    addTerm(&polynomial, 3, 2);
    addTerm(&polynomial, -4, 1);
    addTerm(&polynomial, 1, 0);

    // Displaying the polynomial
    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}

// Question 2

/*
    program to add two polynomial expressions that are represented using a singly linked list.
    time complexity is O(m + n)
    space complexity is O(m + n + p).
*/
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(struct Term **poly, int coefficient, int exponent)
{
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        struct Term *current = *poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;

    while (poly1 != NULL || poly2 != NULL)
    {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sum_coeff = coeff1 + coeff2;

        addTerm(&result, sum_coeff, exp1);

        if (poly1 != NULL)
            poly1 = poly1->next;
        if (poly2 != NULL)
            poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL)
        {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

void freePolynomial(struct Term *poly)
{
    struct Term *current = poly;
    while (current != NULL)
    {
        struct Term *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Term *polynomial1 = NULL;
    struct Term *polynomial2 = NULL;

    addTerm(&polynomial1, 3, 2);
    addTerm(&polynomial1, -4, 1);
    addTerm(&polynomial1, 1, 0);

    addTerm(&polynomial2, 2, 3);
    addTerm(&polynomial2, 5, 1);
    addTerm(&polynomial2, -2, 0);

    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);

    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    struct Term *result = addPolynomials(polynomial1, polynomial2);

    printf("Result: ");
    displayPolynomial(result);

    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(result);

    return 0;
}


// Question 3



/*
   program to multiply two polynomial expressions that are represented using a singly linked list.
   time complexity is O(m * n).
   space complexity is O(m + n + p).
*/
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(struct Term **poly, int coefficient, int exponent)
{
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        struct Term *current = *poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    while (poly1 != NULL)
    {
        struct Term *temp2 = poly2;
        while (temp2 != NULL)
        {
            int coeff = poly1->coefficient * temp2->coefficient;
            int exp = poly1->exponent + temp2->exponent;
            addTerm(&result, coeff, exp);
            temp2 = temp2->next;
        }
        poly1 = poly1->next;
    }
    return result;
}

void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL)
        {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

void freePolynomial(struct Term *poly)
{
    struct Term *current = poly;
    while (current != NULL)
    {
        struct Term *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Term *polynomial1 = NULL;
    struct Term *polynomial2 = NULL;
    addTerm(&polynomial1, 3, 2);
    addTerm(&polynomial1, -4, 1);
    addTerm(&polynomial1, 1, 0);
    addTerm(&polynomial2, 2, 3);
    addTerm(&polynomial2, 5, 1);
    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);
    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);
    struct Term *result = multiplyPolynomials(polynomial1, polynomial2);
    printf("Result: ");
    displayPolynomial(result);
    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(result);
    return 0;
}

// Question 4

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtLast(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertAfterNode(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL.");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

void insertBeforeNode(struct Node **head, struct Node *nextNode, int data)
{
    if (nextNode == NULL)
    {
        printf("Next node cannot be NULL.");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    if (newNode->prev != NULL)
    {
        newNode->prev->next = newNode;
    }
    else
    {
        *head = newNode;
    }
    nextNode->prev = newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtFront(&head, 1);
    insertAtFront(&head, 2);
    insertAtFront(&head, 3);

    insertAtLast(&head, 4);
    insertAtLast(&head, 5);

    struct Node *nodeToInsertAfter = head->next;
    insertAfterNode(nodeToInsertAfter, 6);

    struct Node *nodeToInsertBefore = head->next->next->next;
    insertBeforeNode(&head, nodeToInsertBefore, 7);

    printList(head);

    return 0;
}


// Question 5

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtLast(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    newNode->prev = current;
}
void deleteFromFront(struct Node **head){
    if (*head == NULL) return;
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) (*head)->prev = NULL;
    free(temp);
}
void deleteFromLast(struct Node **head){
    if (*head == NULL) return;
    struct Node *current = *head;
    while (current->next != NULL) current = current->next;
    if (current->prev != NULL) current->prev->next = NULL;
    else *head = NULL;
    free(current);
}
void deleteGivenNumber(struct Node **head, int data){
    struct Node *current = *head;
    while (current != NULL){
        if (current->data == data){
            if (current->prev != NULL) current->prev->next = current->next;
            else  *head = current->next;
            if (current->next != NULL) current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
}
void printList(struct Node *head){
    struct Node *current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(){
    struct Node *head = NULL;
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);
    printf("Original List: ");
    printList(head);
    deleteFromFront(&head);
    printf("After Deleting from Front: ");
    printList(head);
    deleteFromLast(&head);
    printf("After Deleting from Last: ");
    printList(head);
    int numberToDelete = 2;
    deleteGivenNumber(&head, numberToDelete);
    printf("After Deleting %d: ", numberToDelete);
    printList(head);
    return 0;
}

// Question 6

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtLast(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverseDoublyLinkedList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
    struct Node *head = NULL;

    insertAtLast(&head, 1);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);

    printf("Original List: ");
    printList(head);

    reverseDoublyLinkedList(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}

/*-------End------*/
