// Problem-56 Given two sorted linked lists, given an algorithm for the printing common elements of them.

#include <iostream>
using namespace std;

struct node
{
    node *next;
    int data;
};

void traverse(node *head)
{
    node *ptr = head;

    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }

    std::cout << "\n";
}

void print_common(node *head1, node *head2)
{

    std::cout << "Common = ";

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            std::cout << head1->data << " ";
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {

            head1 = head1->next;
        }
        else
        {

            head2 = head2->next;
        }
    }
}
int main()
{

    node *head1;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;
    node *node5 = new node;
    node *node6 = new node;
    node *node7 = new node;

    node1->data = 0;
    node1->next = node2;

    node2->data = 29;
    node2->next = node3;

    node3->data = 39;
    node3->next = node4;

    node4->data = 59;
    node4->next = node5;

    node5->data = 400;
    node5->next = node6;

    node6->data = 1000;
    node6->next = node7;

    node7->data = 1002;
    node7->next = NULL;

    head1 = node1;

    node *head2;

    node *node12 = new node;
    node *node22 = new node;
    node *node32 = new node;
    node *node42 = new node;
    node *node52 = new node;
    node *node62 = new node;
    node *node72 = new node;

    node12->data = 1;
    node12->next = node22;

    node22->data = 39;
    node22->next = node32;

    node32->data = 333;
    node32->next = node42;

    node42->data = 344;
    node42->next = node52;

    node52->data = 400;
    node52->next = node62;

    node62->data = 936;
    node62->next = node72;

    node72->data = 1000;
    node72->next = NULL;

    head2 = node12;

    traverse(head1);
    traverse(head2);

    print_common(head1, head2);

    return 0;
}