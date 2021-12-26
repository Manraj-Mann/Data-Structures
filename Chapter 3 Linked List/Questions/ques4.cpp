//Check whether the given linked list is NULL-terminated. If there is a cycle, find
//the length of the loop

// Check whether the given linked list is either NULL-terminated or ends in a cycle  (cyclic). Q 6 , 7 , 8 , 9 , 10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *next;
};

int Floyd_cycle(node * head){

    node * sptr = head , * fptr = head;
    bool loop = 0;

    while (sptr != NULL && fptr != NULL && fptr->next != NULL)
    {
        sptr = sptr->next;
        fptr = fptr->next->next;
        if (sptr == fptr)
        {
            loop = 1;
            break;
        }
        
    }
    int count = 0;
    if (loop == 1)
    {
        fptr = fptr->next;
        while (fptr != sptr)
        {
            count++;
            fptr = fptr->next;
        }

        return count;
        

        
    }
    

    return 0;
    


}

int traverse(node *head)
{

    int i = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }

    return i;
}

int main()
{

    node *head;

   

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;

    head = node1;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node1;

    cout<<"node of nodes in cycle : "<<Floyd_cycle(head);


    return 0;
}