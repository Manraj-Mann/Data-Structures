// Ques 28 How will you display a Linked List from the end?

#include <iostream>
using namespace std;
struct node
{
    node *next;
    int data;
};
void print_from_last(node *head)
{

    if (head == NULL)
    {
        return;
    }
    print_from_last(head->next);
    cout << head->data << " ";
}
int main()
{
    node *head;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;

    node *node4 = new node;
    node *node5 = new node;
    node *node6 = new node;
    node *node7 = new node;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 11;
    node4->next = node5;

    node5->data = 22;
    node5->next = node6;

    node6->data = 33;
    node6->next = node7;

    node7->data = 44;
    node7->next = NULL;

    head = node1;

    print_from_last(head);

    // Time Complexity: O(n). Space Complexity: O(n)→ for Stack.


    return 0;
}