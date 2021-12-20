/* Question => 17 - 23

Suppose there are two singly linked lists both of which intersect at some point
and become a single linked list. The head or start pointers of both the lists are known, but
the intersecting node is not known. Also, the number of nodes in each of the lists before
they intersect is unknown and may be different in each list. List1 may have n nodes before
it reaches the intersection point, and List2 might have m nodes before it reaches the
intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for
finding the merging point.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *next;
};
int size = 0;
vector<node *> create_table(node *head)
{

    node *ptr = head;
    vector<node *> table;

    while (ptr->next != NULL)
    {
        size++;
        table.push_back(ptr->next);
        ptr = ptr->next;
    }

    return table;
}
node *check_merge(vector<node *> &table, node *head)
{

    node *ptr = head;

    while (ptr->next != NULL)
    {
        node *next = ptr->next;
        for (int i = 0; i < size; i++)
        {
            if (next == table[i])
            {
                return next;
            }
        }
        ptr = ptr->next;
    }

    return NULL;
}

node *find_merge(node *head1, node *head2)
{

    std::stack<node *> stack1, stack2; // stack1 - stores 1st list stack2 another
    node *ptr = head1;
    while (ptr != NULL)
    {
        if (ptr != NULL)
        {
            stack1.push(ptr);
        }
        ptr = ptr->next;
    }
    ptr = head2;
    while (ptr != NULL)
    {
        if (ptr != NULL)
        {
            stack2.push(ptr);
        }
        ptr = ptr->next;
    }

    ptr = NULL;
    while (stack1.top() == stack2.top())
    {

        ptr = stack1.top();
        stack1.pop();
        stack2.pop();
    }
    
    return ptr;


}
int main()
{

    node *head;
    node *head2;

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;

    node *node11 = new node;
    node *node22 = new node;
    node *node33 = new node;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = NULL;

    node11->data = 11;
    node11->next = node22;
    node22->data = 22;
    node22->next = node33;
    node33->data = 33;
    node33->next = node2;

    head = node1;
    head2 = node11;

    // -------------------------- HASH TABLE APPROACH -------------------------------//
    /*
    Algorithm:

    • Select a list which has less number of nodes (If we do not know the lengths
    beforehand then select one list randomly).
    • Now, traverse the other list and for each node pointer of this list check whether the
    same node pointer exists in the hash table.
    • If there is a merge point for the given lists then we will definitely encounter the node
    pointer in the hash table.
    Time Complexity: Time for creating the hash table + Time for scanning the second list = O(m) +
    O(n) (or O(n) + O(m), depending on which list we select for creating the hash table. But in both
    cases the time complexity is the same. Space Complexity: O(n) or O(m).

    */

    vector<node *> hashtable = create_table(head);

    node *merge_point = check_merge(hashtable, head2);
    if (merge_point == NULL)
    {
        cout << "Not merging\n";
    }
    else
    {

        cout << "merging at - " << merge_point->data;
    }

    // ------------------------------------ Using stacks -----------------------------------//

    node *ptr = find_merge(head, head2);

    if (ptr == NULL)
    {
         cout << "\nNot merging\n";
    }
    else{

        cout << "\nmerging at - " << ptr->data;
    }
    
    // Time Complexity: O(m + n), for scanning both the lists.
    // Space Complexity: O(m + n), for creating two stacks for both the lists.


    return 0;
}