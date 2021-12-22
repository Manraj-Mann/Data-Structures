/*Problem-35 Split a Circular Linked List into two equal parts.
 If the number of nodes in the list are odd then make first list one node extra than second list.*/

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

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
    node7->next = node1;

    

    head = node1;



    return 0;
}