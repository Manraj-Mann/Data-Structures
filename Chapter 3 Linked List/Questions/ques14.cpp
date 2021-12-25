/*Problem-38 For a given K value (K > 0) reverse blocks of K nodes in a list.
Example: Input: 1 2 3 4 5 6 7 8 9 10. Output for different K values:
For K = 2: 2 1 4 3 6 5 8 7 10 9
For K = 3: 3 2 1 6 5 4 9 8 7 10
For K = 4: 4 3 2 1 8 7 6 5 9 10*/

#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *next;
};
void reverse(node* & head, int k)
{

    node *ptr = head;
    vector<node * > next_pointers;

    node *to_reverse = head ;

    // stores the pointer to the node which are needed to to revesered 
    for ( int i = 0; i < k; i++)
    {
       next_pointers.push_back(to_reverse);
       to_reverse = to_reverse->next;
    }

    // setting the revesed list head and joining revesed list with the remaining
    next_pointers[0]->next = next_pointers[next_pointers.size()-1]->next;
    head = next_pointers[next_pointers.size()-1];

    // revesering the list 
    for (int i = next_pointers.size()-1; i > 0; i--)
    {
         next_pointers[i]->next = next_pointers[i-1];
    }

}

void traverse(node *head)
{
    node *ptr = head;

    while (1)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
        if (ptr == NULL)
        {
            break;
        }
    }
    std::cout << std::endl;
}
int main()
{

    node *head;
    int k = 2;

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
    node7->next = NULL;

    head = node1;

    traverse(head);
    reverse(head, k);
    traverse(head);

    return 0;
}