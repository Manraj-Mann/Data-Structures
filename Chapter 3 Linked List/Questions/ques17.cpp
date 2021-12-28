// Problem-43 We are given a pointer to a node (not the tail node) in a singly linked list. Delete
// that node from the linked list.

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void del(node * node){


    node->data = node->next->data;
    struct node * todel = node->next;
    node->next = node->next->next;

    delete todel;

}
void traverse(node * head){
    node * ptr = head;

    while (ptr != NULL)
    {
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<std::endl;
    
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

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = node6;

    node6->data = 6;
    node6->next = node7;

    node7->data = 7;
    node7->next = NULL;

    head = node1;

    traverse(head);

    del(node5);

    traverse(head);
    return 0;
}