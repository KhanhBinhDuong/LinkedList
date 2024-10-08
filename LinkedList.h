#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct LinkedList {
    int data;
    struct LinkedList* next;
};

typedef struct LinkedList* node; // Use "node" instead of Linked list data type.

node CreateNode(int value) {
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->data = value;
    return temp; // Return new node with value
}

node AddTail(node head, int value) {
    node temp, p;
    temp = CreateNode(value); //Create a node with entered value
    if (head == NULL) {
        head = temp;     //If Linked list is Empty temp is head
    }
    else {
        p = head;
        // Loop to Tail position
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}


node AddHead(node head, int value) {
    node temp = CreateNode(value);
    if (head == NULL) {
        head = temp; // If Linked list is Empty. Node temp is head.
    }
    else {
        temp->next = head;
        head = temp;
    }
    return head;
}

node AddAtIndex(node head) {
    int value, position;
    printf("\nEnter position of node that you want to add : ");
    scanf_s("%d", &position);
    printf("\nEnter value of node that you want to add : ");
    scanf_s("%d", &value);
    if (position == 0 || head == NULL) {
        head = AddHead(head, value); // Add Head if position is 0.
        printf("\nAdd Successfully !");
    }
    else {
        // Start find the position 
        int k = 1;
        node p = head;
        while (p != NULL && k != position) {
            p = p->next;
            ++k;
        }

        if (k != position) {
            //The position does not exist
            printf("\nThe entered position does not exist on the linked list !");
        }
        else {
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
            printf("\nAdd Successfully !");
        }
    }
    printf("\nEnter a number between 0 and 10 to select !\n");
    return head;
}

node DelHead(node head) {
    if (head == NULL) {
        printf("\nNothing to Delete. Linked list is Empty !");
    }
    else {
        head = head->next;
        printf("\nThe head node has been deleted !");
    }
    return head;
}

node DelTail(node head) {
    if (head == NULL || head->next == NULL) {
        return DelHead(head);
    }
    node p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    p->next = p->next->next; // next = NULL ||| p->next = NULL as the same
    return head;
}

node RemoveAtIndex(node head) {
    int position;
    printf("\nEnter position of node that you want to delete : ");
    scanf_s("%d", &position);
    if (position == 0 || head == NULL || head->next == NULL) {
        head = DelHead(head); // Delete head if position is 0
        printf("\nDelete Successfully !");
    }
    else {
        // Find the position
        int k = 1;
        node p = head;
        while (p->next->next != NULL && k != position) {
            p = p->next;
            ++k;
        }

        if (k != position) {
            //The position does not exist
            printf("\nThe entered position does not exist on the linked list !");
        }
        else {
            p->next = p->next->next;
            printf("\nDelete Successfully !");
        }
    }
    printf("\nEnter a number between 0 and 10 to select !\n");
    return head;
}

void SearchValueAndReturnIndex(node head) {
    int value, position;
    printf("\nEnter value you want to find its position : ");
    scanf_s("%d", &value);
    int k = 0, check = 0;
    for (node p = head; p != NULL; p = p->next) {
        if (p->data == value) {
            position = k;
            check = 1;
        }
        k++;
    }
    if (check == 1)
        printf("\nPosition in Linked list : %d", position);
    else
        printf("\nThe entered value does not exist in Linked list !");
    printf("\nEnter a number between 0 and 10 to select !\n");
}

void PrintAll(node head) {
    if (head != NULL) {
        printf("\n");
        printf("\nAll Nodes are currently in Linked List: ");
        for (node p = head; p != NULL; p = p->next) {
            printf("\t%d", p->data);
        }
        printf("\nPrint out Successfully !");
    }
    else
        printf("\nLinked list is Empty !");
    printf("\nEnter a number between 0 and 10 to select !\n");
}

node InitHead() {
    node head;
    head = NULL;
    return head;
}


void GetSize(node head) {
    int length = 0;
    for (node p = head; p != NULL; p = p->next) {
        ++length;
    }
    printf("\nThe current length of Linked List = %d", length);
    printf("\nPrint out Successfully !");
    printf("\nEnter a number between 0 and 10 to select !\n");
}

node Init() {
    // Init head
    node head = InitHead();
    int n, value;
    do {
        printf("\nEnter the number of Nodes = ");
        scanf_s("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; ++i) {
        printf("\nEnter the node's value at index %d = ", i);
        scanf_s("%d", &value);
        // Add node at Tail position
        head = AddTail(head, value);
    }
    return head;
}


node DeleteAll(node head) {
    head = NULL;
    printf("\nDelete Successfully !");
    printf("\nEnter a number between 0 and 10 to select !\n");
    return head;
}