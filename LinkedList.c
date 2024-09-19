#include "LinkedList.h"

int main() {
    printf("Create a Linked List.");
    // Create a linked list by call Init() function
    node head = Init();

    int key, value;
    printf("**************************************************************\n");
    printf("**                  LINKED LIST OPTIONS                     **\n");
    printf("** 0. Exit                                                  **\n");
    printf("** 1. Print out all currently available Linked list nodes.  **\n");
    printf("** 2. Print out the current length of Linked List.          **\n");
    printf("** 3. Delete node at the entered position. (Remove At Index)**\n");
    printf("** 4. Delete all notes in Linked List                       **\n");
    printf("** 5. Delete Head note in Linked List                       **\n");
    printf("** 6. Delete Tail note in Linked List                       **\n");
    printf("** 7. Add node at the entered position. (Add At Index)      **\n");
    printf("** 8. Add Head node into Linked List                        **\n");
    printf("** 9. Add Tail node into Linked List                        **\n");
    printf("** 10. Search Value and Return position                     **\n");
    printf("**************************************************************\n");
    printf("**Enter your choose by entering a number between 0 and 10   **\n");
    while (true) {
        scanf_s("%d", &key);
        switch (key) {
        case 0:
            printf("\nExit Successfully\n");
            getchar();
            return 0;
        case 1:
            PrintAll(head);
            getchar();
            break;
        case 2:
            GetSize(head);
            getchar();
            break;
        case 3:
            head = RemoveAtIndex(head);
            getchar();
            break;
        case 4:
            head = DeleteAll(head);
            getchar();
            break;
        case 5:
            head = DelHead(head);
            printf("\nEnter a number between 0 and 10 to select !\n");
            getchar();
            break;
        case 6:
            head = DelTail(head);
            printf("\nEnter a number between 0 and 10 to select !\n");
            getchar();
            break;
        case 7:
            head = AddAtIndex(head);
            getchar();
            break;
        case 8:
            printf("\nEnter value of node that you want to add Head : ");
            scanf_s("%d", &value);
            head = AddHead(head, value);
            printf("\nAdd Successfully !");
            printf("\nEnter a number between 0 and 10 to select !\n");
            getchar();
            break;
        case 9:
            printf("\nEnter value of node that you want to add Head : ");
            scanf_s("%d", &value);
            head = AddTail(head, value);
            printf("\nAdd Successfully !");
            printf("\nEnter a number between 0 and 10 to select !\n");
            getchar();
            break;
        case 10:
            SearchValueAndReturnIndex(head);
            getchar();
            break;
        default:
            printf("\nError!");
            printf("\nEnter a number between 0 and 10 to select !\n");
            getchar();
            break;
        }
    }
    return 0;

}