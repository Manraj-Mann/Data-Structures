// Problem-50 Given two lists List 1 = {A1 , A2, . . . , An
// ) and List2 = {B1, B2, . . . , Bm} with data (both lists) in ascending order. Merge them into the third list in ascending order

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traverse(node *head)
{

    node *ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }

    std::cout << std::endl;
}
void join(node *&newlist, node *&head, node *&newlisto)
{

    if (newlist == NULL)
    {
        newlisto = head;
        newlist = newlisto;
        head = head->next;
        newlisto->next = NULL;
    }
    else
    {

        newlisto->next = head;
        head = head->next;
        newlisto = newlisto->next;
        newlisto->next = NULL;
    }
}
node *merge(node *&head1, node *&head2)
{

    node *newlist = NULL;
    node *newlisto;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {

            join(newlist, head1, newlisto);
        }
        else
        {
            join(newlist, head2, newlisto);
        }

       // traverse(newlist);
    }

    if (head1 != NULL)
    {
        newlisto->next = head1;
    }
    else
    {

        newlisto->next = head2;
    }

    return newlist;
}
int main()
{

    node *head;
    node *head2;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;

    node *node11 = new node;
    node *node22 = new node;
    node *node33 = new node;

    node1->data = 1;
    node1->next = node2;

    node2->data = 59;
    node2->next = node3;

    node3->data = 79;
    node3->next = NULL;

    node11->data = 33;
    node11->next = node22;
    node22->data = 44;
    node22->next = node33;
    node33->data = 1000;
    node33->next = NULL;

    head = node1;
    head2 = node11;

    traverse(head);
    traverse(head2);

    node *newlist = merge(head, head2);

    traverse(newlist);

    return 0;
}