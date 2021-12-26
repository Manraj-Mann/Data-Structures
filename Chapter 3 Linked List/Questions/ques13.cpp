/*Problem-35 Split a Circular Linked List into two equal parts.
 If the number of nodes in the list are odd then make first list one node extra than second list.*/

#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *next;
};
bool is_palin(node *head)
{
    stack<node *> str;
    node * mid = NULL;
    node *fptr = head;
    node *sptr = head;
    str.push(sptr);

    while (1)
    {
        // mid = sptr;

        sptr = sptr->next;
        str.push(sptr);
        fptr = fptr->next->next;

        if (fptr->next->next == head)
        {
            //mid = sptr;
          
        
            fptr = fptr->next;
            break;
        }
        if (fptr->next == head)
        {
          
            str.pop();
            break;
        }
    }

    //  std::cout<<"\nfptr = "<<fptr->data;
    //  std::cout<<"\nsptr = "<<sptr->next->data;

    sptr = sptr->next;
    //  std::cout<<"\nmid = "<<mid->data;


   
    while (!str.empty())
    {
       
       if (sptr->data != str.top()->data)
       {
           return 0;
       }
       
        str.pop();
        sptr = sptr->next;
    }

   
    return 1;
    

    

    

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

    node4->data = 1;
    node4->next = node5;

    node5->data = 3;
    node5->next = node6;

    node6->data = 2;
    node6->next = node7;

    node7->data = 1;
    node7->next = node1;

    head = node1;

    if (is_palin(head))
    {
        std::cout << "list is palindrome\n";
    }
    else
    {

        std::cout << "list is not palindrome\n";
    }

    return 0;
}