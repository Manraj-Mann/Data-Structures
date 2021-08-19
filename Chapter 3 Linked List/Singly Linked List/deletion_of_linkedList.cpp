#include <iostream>
using namespace std;

typedef struct LinkedList
{
    int data;
    LinkedList *next;

} List;

int Traverse(LinkedList *head)
{

    cout << "The data is : ";

    int count = 0;
    LinkedList *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
        count++;
    }
    return count;
}
void delete_list(List ** head){
    
    List * iterator ,* auxNode ;

    iterator = *head;
    while (iterator)
    {
        auxNode = iterator->next;
        delete iterator;
        iterator = auxNode;

    }

    *head = NULL;

}

//  Time Complexity: O(n), for scanning the complete list of size n.
//  Space Complexity: O(1), for creating one temporary variable.

int main(){

    List *head;

    List *node1 = new List[sizeof(List)];
    List *node2 = new List[sizeof(List)];
    List *node3 = new List[sizeof(List)];
    List *node4 = new List[sizeof(List)];
    List *node5 = new List[sizeof(List)];

    head = node1;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = NULL;

    Traverse(head);
    cout<<endl;
 
    delete_list(&head);

    Traverse(head);
    cout<<endl;
   

    
return 0;
}