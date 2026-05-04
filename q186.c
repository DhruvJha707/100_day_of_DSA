/*Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000*/

#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to print list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insertion Sort on Linked List
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    struct ListNode* dummy = createNode(0); // dummy node
    dummy->next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;

        // find correct position
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // insert node
        curr->next = prev->next;
        prev->next = curr;

        curr = nextNode;
    }

    return dummy->next;
}

// Main function
int main() {
    struct ListNode* head = NULL;

    // Example: [4,2,1,3]
    head = insertEnd(head, 4);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);
    head = insertEnd(head, 3);

    printf("Original List:\n");
    printList(head);

    head = insertionSortList(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}