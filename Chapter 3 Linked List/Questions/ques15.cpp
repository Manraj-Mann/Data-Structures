/*Problem-40 Josephus Circle: N people have decided to elect a leader by arranging
themselves in a circle and eliminating every Mth person around the circle, closing ranks as
each person drops out. Find which person will be the last one remaining (with rank 1). */

#include <iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};
int Josephus_Circle(node * head , int m){

    node * prev = NULL;
    node * ptr = head;
    node * next = head->next;

    while (ptr->next != ptr)
    {

        for (int i = 0; i < m; i++)
        {
            prev = ptr;
            ptr = next;
            next = ptr->next;

        }
        cout<<"removed = "<<ptr->data<<"\n";
        delete ptr;
        prev->next = next;
        ptr = next;
        next = ptr->next;
    
    }

    return ptr->data;
    

}
void traverse(node *head)
{
    node *ptr = head;

    while (1)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
        if (ptr == head)
        {
            break;
        }
    }
    std::cout << std::endl;
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

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = node6;

    node6->data = 6;
    node6->next = node7;

    node7->data = 7;
    node7->next = node1;

    head = node1;

   // mth node to be removed 

   int m = 3;

   int winner = Josephus_Circle(head , m);
   std::cout<<"Winner - "<<winner<<"\n";

   
    return 0;
}