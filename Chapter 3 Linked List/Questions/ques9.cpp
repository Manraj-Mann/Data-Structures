// Ques 29 Check whether the given Linked List length is even or odd?

#include <iostream>
using namespace std;
struct node
{

    int data;
    node *next;
};
bool list_eo(node * head){

    bool even = 0;

    node * ptr = head;
    while (ptr->next != NULL && ptr != NULL)
    {
        if (ptr->next->next == NULL)
        {
            even = 1;
            break;
        }
        
        ptr = ptr->next->next;
    }

    return even;
    
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

    if(list_eo(head)){

        std::cout<<"Even\n";
    }
    else{

        std::cout<<"Odd\n";
    }

    return 0;
}