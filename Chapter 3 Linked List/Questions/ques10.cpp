// Problem-30 If the head of a Linked List is pointing to kth element, then how will you get the elements before kth element?

// Answer - Use XOR List

// Problem-31 Given two sorted Linked Lists, how to merge them into the third list in sorted order?

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

void merge(node *l1, node *l2, node **newlist)
{

    node *ptr = new node;
    node *start = ptr;
    ptr->next = NULL;

    while (l1 != NULL && l2 != NULL)
    {

        if (l1->data < l2->data)
        {

            ptr->data = l1->data;
            ptr->next = NULL;
            l1 = l1->next;
        }
        else
        {

            ptr->data = l2->data;
            ptr->next = NULL;
            l2 = l2->next;
        }

        ptr->next = new node;
        ptr = ptr->next;
    }

    while (l1)
    {
        ptr->data = l1->data;
        ptr->next = NULL;
        l1 = l1->next;
        if (l1 != NULL)
        {

            ptr->next = new node;
            ptr = ptr->next;
        }
    }

    while (l2)
    {
        ptr->data = l1->data;
        ptr->next = NULL;
        l2 = l2->next;
        if (l2 != NULL)
        {

            ptr->next = new node;
            ptr = ptr->next;
        }
    }

    //  ptr->next = NULL;

    // traverse(start->next);

    *newlist = start;
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

    node *head2;

    node *node12 = new node;
    node *node22 = new node;
    node *node32 = new node;
    node *node42 = new node;
    node *node52 = new node;
    node *node62 = new node;
    node *node72 = new node;

    node12->data = 1;
    node12->next = node2;

    node22->data = 2;
    node22->next = node3;

    node32->data = 3;
    node32->next = node4;

    node42->data = 11;
    node42->next = node5;

    node52->data = 22;
    node52->next = node6;

    node62->data = 33;
    node62->next = node7;

    node72->data = 44;
    node72->next = NULL;

    head2 = node12;

    node *newlist = NULL;

    merge(head, head2, &newlist);

    traverse(newlist);


    // Time Complexity: O(n + m), where n and m are lengths of two lists

    return 0;
}