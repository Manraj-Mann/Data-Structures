// Find nth node from the end of a Linked List.   // Ques 2, 3 , 4 , 5

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *nth_node(node *head, int n){
        node * ptemp = head, * ptr = head;
        for (int i = 0; i < n; i++)
        {
            ptemp = ptemp->next;
            
        }
    
        while (ptemp)
        {
            ptr = ptr->next;
            ptemp = ptemp->next;
        }

        return ptr;
        
        
}

node *nth_node(node *head, int n, int size)
{

    if (n > size || n <= 0)
    {
        cout << "Not corect\n";
        return NULL;
    }
    else
    {
        node * ptr = head;
        for (int i = 0; i < size - n; i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
}

node *nth_node(vector<node *> &table, int position)
{

    int m = table.size();

    if (position > m)
    {
        cout << "Not such big\n";
    }
    else if (position <= 0)
    {

        cout << "Less elements\n";
    }
    else
    {

        return table[m - position];
    }

    return NULL;
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
    hashtable.push_back(node1);

    node2->data = 2;
    node2->next = node3;
    hashtable.push_back(node2);

    node3->data = 3;
    node3->next = node4;
    hashtable.push_back(node3);

    node4->data = 4;
    node4->next = NULL;
    hashtable.push_back(node4);

    //  ---------- Hashtable approach -------------------- //

    //    cout<<"data - "<<(nth_node(hashtable , 2))->data;
    //     Time Complexity: Time for creating the hash table, T(m) = O(m).  m = size of list
    //     Space Complexity: Since we need to create a hash table of size m, O(m).

    // ------------ Two scans , one scan - size , 2nd scan - element -----------//

    // int n = traverse(head);

    // cout << "data - " << (nth_node(head, 2 , n))->data;

    // T(n) = O(n) + O(n) ≈ O(n). Space Complexity: O(1).


    // ================== One scan =======================//

//  concept =                 if list is          1-> 2 -> 3 -> 4 -> NULL
 //                                                   ^
//  2 from last = 3       so move ptemp till 2        | ptemp

//ow move pointer ptr till ptemp->next = NULL              ^ ptr      ^ ptemp
//                                                         |          |       

    cout << "data - " << (nth_node(head, 2 ))->data;












    return 0;
}