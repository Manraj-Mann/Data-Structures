// Problem-55 Given a list, List1 = {A1 , A2 , . . . An–1; An) with data, reorder it to {A1,An ,A2 ,An–1} without using any extra space.

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void traverse(node *head)
{

    node *ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }

    std::cout << std::endl;
}
node *find_middle(node *head)
{

    node *sptr = head;
    node *fptr = head;

    while (fptr->next->next != NULL)
    {
        fptr = fptr->next->next;
        sptr = sptr->next;

        if (fptr->next == NULL)
        {

            break;
        }
    }
    return sptr;
}
node *reverse(node *head)
{

    node *next = head->next;
    node *ptr = head;
    node *prev = NULL;

    while (next != NULL)
    {
        ptr->next = prev;
        prev = ptr;
        ptr = next;
        next = next->next;
    }

    ptr->next = prev;

    return ptr;
}
node *merge_inplace(node *list1, node *list2)
{

    node *mergedlist = list1;
    node *head = list1;
    list1 = list1->next;
    while (list1 != NULL)
    {
        mergedlist->next = list2;
        list2 = list2->next;
        mergedlist->next->next = list1;
        list1 = list1->next;
        mergedlist = mergedlist->next->next;
    }
    if (list2 != NULL)
    {

        mergedlist->next = list2;
    }
    else
    {

        mergedlist->next = NULL;
    }

    return head;
}
node *reorder(node *head)
{

    // Found the middle 
    node *middle = find_middle(head);

    //std::cout << "\nMiddle = " << middle->data << std::endl;

    // Splittd list form middle and revered right part 
    node *reversed = reverse(middle->next);
    middle->next = NULL;

    //traverse(reversed);

    // joined the lists
    node *reordered = merge_inplace(head, reversed);

    //traverse(reordered);

    return reordered;
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

    node1->data = 2;
    node1->next = node2;

    node2->data = 3;
    node2->next = node3;

    node3->data = 6;
    node3->next = node4;

    node4->data = 86;
    node4->next = node5;

    node5->data = 25;
    node5->next = node6;

    node6->data = 8;
    node6->next = NULL;

    node7->data = 133;
    node7->next = NULL;

    head = node1;

    traverse(head);

    node * reordered = reorder(head);
    
    traverse(reordered);

    return 0;
}