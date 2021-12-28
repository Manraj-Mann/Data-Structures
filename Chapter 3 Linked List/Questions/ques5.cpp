// Ques covered - 
// ---------------------------------------------------------------------------------
//   1 -> Insert a node in a sorted linked list
//   2 -> Reverse a singly linked list.


#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
// Time Complexity: O(n). Space Complexity: O(1).

node *insert_in_sorted(int data, node *head)
{

    node *temp = head, *ptr = head;

    if (head == NULL)
    {
        head = new node;

        head->data = data;
        head->next = NULL;
    }
    else
    {

        node *newdata = new node;
        newdata->data = data;

        while (ptr != NULL && ptr->data < data)
        {
            temp = ptr;
            ptr = ptr->next;
        }

        // If insertion is at first
        if (ptr == temp)
        {
            newdata->next = head;
            head = newdata;
        }
        // Insertion at last and middle of list
        else
        {

            newdata->next = ptr;
            temp->next = newdata;
        }
    }

    return head;
}

// Time Complexity: O(n). Space Complexity: O(1)

node * reverse(node * head){

    node * temp = NULL , * nextnode = NULL;

    while (head)
    {

        nextnode = head->next;
        head->next = temp;
        temp = head;
        head = nextnode;
        
    }

    return temp;
    


}
void traverse(node *head)
{

    node *ptr = head;
    while (ptr != NULL)
    {

        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{

    node *head = NULL;

    head = insert_in_sorted(10, head);
    head = insert_in_sorted(0, head);
    head = insert_in_sorted(8, head);
    head = insert_in_sorted(5, head);
    head = insert_in_sorted(-1, head);
    head = insert_in_sorted(-10, head);

    traverse(head);

    head = reverse(head);

    cout<<std::endl;
    
    traverse(head);
    return 0;
}