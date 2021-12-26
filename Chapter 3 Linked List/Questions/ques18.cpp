// Problem-46 Find modular node: Given a singly linked list, write a function to find the last
// element from the beginning whose n%k == 0, where n is the number of elements in the list
// and k is an integer constant. For example, if n = 19 and k = 3 then we should return 18th node.

// Hint [ We have to find the last node in the list where n % k = 0 ]


// Problem-47 Find modular node from the end: Given a singly linked list, write a function to
// find the first from the end whose n%k == 0, where n is the number of elements in the list
// and k is an integer constant. If n = 19 and k = 3 then we should return 16th node.



#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node * last_element_from_the_beginning(node * head , int k ){

    int i = 0;
    node * ptr = head;
    node * modulo;
    if (k <= 0 )
    {
        return NULL;
    }
    while (ptr != NULL)
    {
        if (i % k ==  0)
        {
            modulo = ptr;
        }
        i++;
        
        ptr = ptr->next;
    }
    
    return modulo;

}
void traverse(node *head)
{
    node *ptr = head;

    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << std::endl;
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

    node1->data = 2;
    node1->next = node2;

    node2->data = 3;
    node2->next = node3;

    node3->data = 6;
    node3->next = node4;

    node4->data = 86;
    node4->next = node5;

    node5->data = 24;
    node5->next = node6;

    node6->data = 8;
    node6->next = node7;

    node7->data = 134;
    node7->next = NULL;

    head = node1;

    // traverse(head);

    // // Problem 46
     std::cout<<"last element from the beginning  = "<<last_element_from_the_beginning(head , 2)->data;





    


    

    return 0;
}
