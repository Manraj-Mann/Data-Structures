// Problem-48 Find fractional node: Given a singly linked list, write a function to find the n/kth
// element, where n is the number of elements in the list.

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

node * fractional_node(node * head  , int k ){

    if (k<= 0)
    {
        return NULL;
    }

    int i = 0;
    node * ptr = head;
    node* fraction = NULL;

    while (ptr != NULL)
    {
        if ( i % k == 0)
        {
            if (fraction == NULL)
            {
                fraction = head;
            }
            else{

                fraction = fraction->next;
            }
            
        }
        i++;
        ptr = ptr->next;
    }

    return fraction;
    
}
int main()
{

    node *head = NULL;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;
    node *node5 = new node;
    node *node6 = new node;
    node *node7 = new node;

    node1->data = 2;  //0
    node1->next = node2;

    node2->data = 3; // 1
    node2->next = node3;

    node3->data = 6; // 2
    node3->next = node4;

    node4->data = 86; // 3
    node4->next = node5;

    node5->data = 24; // 4
    node5->next = node6;

    node6->data = 8; // 5
    node6->next = node7;

    node7->data = 134; // 6
    node7->next = NULL;

    head = node1;


    std::cout<<"Fractional node = "<<fractional_node(head , 3)->data;    // 6/3 = 2

    node6->next = NULL;
    std::cout<<"\nFractional node = "<<fractional_node(head , 3)->data;    // 5/3 = 1

    return 0;
}