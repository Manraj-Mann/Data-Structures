// Find node: Given a singly linked list, write a function to find the
// element, where n is the number of elements in the list. Assume the value of n is not known in advance


#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

node * root_node(node * head  , int k ){

    if (k<= 0)
    {
        return NULL;
    }

    int i = 1;
    int j = 1;
    node * ptr = head;
    node* root_node = NULL;

    while (ptr != NULL)
    {
        if ( i == j*j)
        {
            if (root_node == NULL)
            {
                root_node = head;
            }
            else{

                root_node = root_node->next;
            }
            j++;
            
        }
        i++;
        ptr = ptr->next;
    }

    return root_node;
    
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

    node1->data = 2;  //1
    node1->next = node2;

    node2->data = 3; // 2
    node2->next = node3;

    node3->data = 6; // 3
    node3->next = node4;

    node4->data = 86; // 4
    node4->next = node5;

    node5->data = 24; // 5
    node5->next = node6;

    node6->data = 8; // 6
    node6->next = node7;

    node7->data = 134; // 7
    node7->next = NULL;

    head = node1;


    std::cout<<"Fractional node = "<<root_node(head , 3)->data;    // root(7) = 2.64575131

    node4->next = NULL;
    std::cout<<"\nFractional node = "<<root_node(head , 3)->data;    // root(4) = 2

    return 0;
}