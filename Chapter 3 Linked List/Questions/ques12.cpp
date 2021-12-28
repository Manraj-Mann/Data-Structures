/*Problem-35 Split a Circular Linked List into two equal parts.
 If the number of nodes in the list are odd then make first list one node extra than second list.*/

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

void spit_list(node * head  , node * & list1 ,  node * & list2){

    node * fptr = head;
    node * sptr = head;

    while (1)
    {
        sptr = sptr->next;
        fptr = fptr->next->next;

        if (fptr->next->next == head)
        {
            fptr = fptr->next;
            break;
        }
        if ( fptr->next == head)
        {
            break;
            
        }
            
    }

    // std::cout<<"fptr = "<<fptr->data;
    // std::cout<<"sptr = "<<sptr->data;

    fptr->next = sptr->next;
    sptr->next = head;


    list1 = sptr->next;

    list2 = fptr->next;

}
void traverse(node * head){
    node * ptr = head;

    while (1)
    {
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
        if (ptr == head)
        {
            break;
        }
        
    }
    std::cout<<std::endl;
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
    node6->next = node1;

    node7->data = 44;
    node7->next = node1;

    head = node1;

    node * new1 = NULL, * new2 = NULL;

    spit_list(head , new1 , new2);

    std::cout<<"List 1 = ";traverse(new1);
    std::cout<<"List 2 = ";traverse(new2);



    return 0;
}