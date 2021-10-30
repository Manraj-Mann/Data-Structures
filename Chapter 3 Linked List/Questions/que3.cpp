// Check whether the given linked list is NULL-terminated or not. If there is a cycle find the start node of the loop - Q 11 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *next;
};

bool isCircular(vector<node *> table)
{

    if (table[table.size() - 1] != NULL)
    {
        return 1;
    }
    for (int i = 0; i < table.size() - 1; i++)
    {
        if (table[i] == table[i + 1])
        {
            return 1;
        }
    }

    return 0;
}

bool Floyd_cycle(node * head){

    node * sptr = head , * fptr = head;

    while (sptr != NULL && fptr != NULL && fptr->next != NULL)
    {
        if (sptr == fptr)
        {
            return 1;
        }
        sptr = sptr->next;
        fptr = fptr->next->next;
        
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


   

    if (Floyd_cycle(head))
    {

        cout << "Yes - Circular\n";
    }
    else
    {

        cout << "No - Not Circular\n";
    }

//Time Complexity: O(n). Space Complexity: O(1).





    return 0;
}