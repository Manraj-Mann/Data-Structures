// Reverse the linked list in pairs. If you have a linked list that holds 1 → 2 → 3 → 4 → X,
// then after the function has been called the linked list would hold 2 → 1 → 4 → 3 → X.

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void traverse(node *head)
{

    while (head != NULL)
    {
        std::cout << head->data << ", ";
        head = head->next;
    }
}
node *reverse_in_pairs(node *head)
{

    node *temp = NULL, *temp2 = NULL, *current = head;
    node *start = current->next;

    while (current != NULL && current->next != NULL)
    {
        if (temp2 != NULL)
        {
            temp2->next = current->next;
        }

        temp = current->next;
        current->next = current->next->next;
        temp->next = current;

        temp2 = current;

        current = current->next;

        if (current != NULL)
        {
            temp = current->next;
        }
    }

    return start;
}
int main()
{

    node *head;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;
    node *node5 = new node;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = NULL;

    head = node1;

    // traverse(head);

    node *rev = reverse_in_pairs(head);

    traverse(rev);

    return 0;
}