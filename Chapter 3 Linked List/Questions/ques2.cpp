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
        sptr = sptr->next;
        fptr = fptr->next->next;
        if (sptr == fptr)
        {
            return 1;
        }
        
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

    vector<node *> hashtable;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;

    head = node1;

    node1->data = 1;
    node1->next = node2;
    hashtable.push_back(node1->next);

    node2->data = 2;
    node2->next = node3;
    hashtable.push_back(node2->next);

    node3->data = 3;
    node3->next = node4;
    hashtable.push_back(node3->next);

    node4->data = 4;
    node4->next = node1;
    hashtable.push_back(node4->next);

    //  ----------  Hashtable approach -------------------- //


    sort(hashtable.begin(), hashtable.end());

    // if (isCircular(hashtable))
    // {

    //     cout << "Yes - Circular\n";
    // }
    // else
    // {

    //     cout << "No - Not Circular\n";
    // }
    /// Time Complexity; O(nlogn) for sorting the next pointers array.
    /// Space Complexity; O(n) for the next pointers array

// • Traverse the linked list nodes one by one.
// • Check if the address of the node is available in the hash table or not.
// • If it is already available in the hash table, that indicates that we are visiting the node
// that was already visited. This is possible only if the given linked list has a loop in
// it.
// • If the address of the node is not available in the hash table, insert that node’s address
// into the hash table.
// • Continue this process until we reach the end of the linked list or we find the loop.


//      Problem with the above algorithm: The above algorithm works only if we can find the length of
//      the list. But if the list has a loop then we may end up in an infinite loop. Due to this reason the
//      algorithm fails.


// ------------------------Floyd cycle finding algorithm ------------------------------//


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