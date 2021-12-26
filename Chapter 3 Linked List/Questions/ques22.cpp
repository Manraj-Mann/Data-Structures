// Problem-52 Given a linked list, how do you modify it such that all the even numbers appear
// before all the odd numbers in the modified linked list?

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
node *even_odd(node *&head1)
{

    node *newlisteven = NULL;
    node *newlistodd = NULL;

    node *newlisto;
    node *newliste;

    while (head1 != NULL)
    {
        if (head1->data % 2 == 0)
        {

            join(newlisteven, head1, newliste);
        }
        else
        {
            join(newlistodd, head1, newlisto);
        }

        // traverse(newlisteven);
        // traverse(newlistodd);
    }

    if (newliste != NULL)
    {
        newliste->next = newlistodd;
        newliste->next = newlistodd;
    }
    else
    {

        newlisteven = newlistodd;
    }

    return newlisteven;
}
int main()
{

    node * head;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;
    node *node5 = new node;
    node *node6 = new node;
    node *node7 = new node;

    node1->data = 2; 
    node1->next = node2;

    node2->data = 3; 
    node2->next = node3;

    node3->data = 6; 
    node3->next = node4;

    node4->data = 86; 
    node4->next = node5;

    node5->data = 25; 
    node5->next = node6;

    node6->data = 8; 
    node6->next = node7;

    node7->data = 133; 
    node7->next = NULL;

    head = node1;

    traverse(head);

    node *newlist = even_odd(head);

    traverse(newlist);

    return 0;
}