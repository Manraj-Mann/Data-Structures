/*
// Ques 24 => 27
// How will you find the middle of the linked list?

*/

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
int length_of_list(node *head)
{

    node *ptr = head;
    int l = 0;
    while (ptr != NULL)
    {
        l++;
        ptr = ptr->next;
    }

    return l;
}
int middel(node * head , int n){

    node * ptr = head;

    for (int i = 0; i < n/2; i++)
    {
        ptr = ptr->next;
    }
    
    return ptr->data;

}
int get_middle(node * head){

    node * sptr = head;
    node * fptr = head;

    while (fptr->next != NULL && fptr != NULL)
    {
        sptr = sptr->next;

        if (fptr->next->next == NULL)
        {
            // sptr = sptr->next;
            break;
        }
        
        fptr = fptr->next->next;

    }

    return sptr->data;
    

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

    int n = length_of_list(head);

    // ------------------------------ Finding the length and the scan toll mid -------------------------//

    cout << "\nmiddle = " << middel(head , n);

    // Time Complexity: Time for finding the length of the list + Time for locating middle node = O(n) + O(n) ≈ O(n).
    // Space Complexity: O(1).

    // ------------------------------ Using 2 pointer approach ---------------------------------------//

    cout<<"\nMiddel = "<<get_middle(head);


    return 0;
}