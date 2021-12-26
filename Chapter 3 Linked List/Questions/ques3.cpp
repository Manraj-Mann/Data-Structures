// Check whether the given linked list is NULL-terminated or not. If there is a cycle find the start node of the loop - Q 11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *Floyd_cycle(node *head)
{

    node *sptr = head, *fptr = head;
    bool loop = 0;

    while (sptr != NULL && fptr != NULL && fptr->next != NULL)
    {
        fptr = fptr->next->next;
        sptr = sptr->next;
        if (sptr == fptr)
        {
            loop = 1;
            break;
        }
    }

    //   cout<<"sptr = "<<sptr->data<<" , fptr = "<<fptr->data<<"\n";
    sptr = head;

    if (loop == 1)
    {

        while (sptr != fptr)
        {

            sptr = sptr->next;
            fptr = fptr->next;
        }

        return sptr;
    }
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

    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;
    node *node4 = new node;
    node *node5 = new node;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = node4;

    node4->data = 4;
    node4->next = node5;

    node5->data = 5;
    node5->next = node1;

    head = node1;

    // Proof :

    //  Say there are l elements before the loop starts and n elements in the loop. And el is the first element of the loop which is seen when we traverse the linked-list. When we will say "an element x steps ahead of e", that will mean, we can reach that element taking x steps from e.

    // Now, when Tr (tortoise) reaches el, after l iterations, say, Hr (Hare) is x steps ahead of el. Since Hr has taken total 2l steps by then (l steps prior to the loop), so:

    // x=lmodn.

    // In each future iteration, Tr and Hr will progress by 1 and 2 steps respectively, and so each iteration will increase their "gap" by 1. So they will meet after n−x further iterations, when their gap will become x+(n−x)=n.

    // So, till that meeting, Tr has taken total steps = (steps till el) + (further steps after el)

    // = l+(n−x)

    // = l+n−lmodn

    // = n+(l−lmodn)

    // = a multiple of n

    // Since Hr takes 2 steps in each iteration, so, till the meeting it must have taken double of the Tr's steps, again a multiple of n.

    // Book Proof :

    // This problem is at the heart of number theory. In the Floyd cycle finding algorithm,
    // notice that the tortoise and the hare will meet when they are n × L, where L is the loop length.
    // Furthermore, the tortoise is at the midpoint between the hare and the beginning of the sequence
    // because of the way they move. Therefore the tortoise is n × L away from the beginning of the
    // sequence as well. If we move both one step at a time, from the position of the tortoise and from
    // the start of the sequence, we know that they will meet as soon as both are in the loop, since they
    // are n × L, a multiple of the loop length, apart. One of them is already in the loop, so we just move
    // the other one in single step until it enters the loop, keeping the other n × L away from it at all
    // times.

    // code:

    cout << "loop head = " << (Floyd_cycle(head))->data;

    return 0;
}