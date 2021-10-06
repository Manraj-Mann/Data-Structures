#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

int blocksize; // max number of nodes in a block
struct ListNode
{
    ListNode *next;
    int value;
};
struct LinkedBlock
{
    LinkedBlock *next;
    ListNode *head;
    int nodecount;
};

LinkedBlock *blockhead;

// create an empty block

LinkedBlock *newLinkedBlock()
{

    LinkedBlock *block = new LinkedBlock;
    block->next = NULL;
    block->head = NULL;
    block->nodecount = 0;
    return block;
}
// create a node

ListNode *newListNode(int value)
{

    ListNode *temp = new ListNode;
    temp->next = NULL;
    temp->value = value;
    return temp;
}
// Print list

void printlist()
{

    LinkedBlock *bh = blockhead;
    ListNode *ls = blockhead->head;
    int i = 0;
    cout << "elements in " << i << " th block : ";
    for (int i = 0; i < bh->nodecount; i++)
    {
        cout << ls->value << " ";
        ls = ls->next;
        if (i == bh->nodecount - 1)
        {
            if (bh->next == NULL)
            {
                return;
            }
            else
            {
                i++;
                bh = bh->next;
                cout << "\nelements in " << i << " th block : ";
            }
        }
    }
}

// search element

void searchElement(int k, LinkedBlock **flinkedBlock, ListNode **flistNode)
{
    // find the block

    int j = (k + blocksize - 1) / blocksize; // kth node in jth block
    LinkedBlock *p = blockhead;
    while (--j)
    {
        p = p->next;
    }
    *flinkedBlock = p;

    // find node

    ListNode *q = p->head;

    k = k % blocksize;
    if (k == 0)
    {
        k = blocksize;
    }
    k = p->nodecount + 1 - k;
    while (k--)
    {
        q = q->next;
    }

    *flistNode = q;
}
// start shift operation from block * p

void shift(LinkedBlock *A)
{

    LinkedBlock *B;
    ListNode *temp;

    while (A->nodecount > blocksize) // if this block still have to shift
    {
        if (A->next == NULL) // reached end A little different
        {
            A->next = newLinkedBlock();
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            B->head = temp;
            temp->next = temp;
            A->nodecount--;
            B->nodecount++;
        }
        else
        {
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            temp->next = B->head->next;
            B->head->next = temp;
            B->head = temp;
            A->nodecount--;
            B->nodecount++;
        }

        A = B;
    }
}

// add
void addElement(int k, int x)
{
    ListNode *p, *q;
    LinkedBlock *r;
    if (!blockhead) // initial , first node and block
    {
        blockhead = newLinkedBlock();
        blockhead->head = newListNode(x);
        blockhead->head->next = blockhead->head;
        blockhead->nodecount++;
        shift(blockhead);
    }
    else
    {

        if (k == 0) // special case
        {
            p = blockhead->head;
            q = p->next;
            p->next = newListNode(x);
            p->next->next = q;
            blockhead->head = p->next;
            blockhead->nodecount++;
            shift(blockhead);
        }
        else
        {

            searchElement(k, &r, &p);
            q = p;
            while (q->next != p)
            {
                q = p->next;
            }
            q->next = newListNode(x);
            q->next->next = p;
            r->nodecount++;
            shift(r);
        }
    }
}

int searchElement(int k)
{

    ListNode *p;
    LinkedBlock *q;
    searchElement(k, &q, &p);
    return p->value;
}

int main()
{

    int tt = clock();
    int m, i, k, x;
    char cmd[10];
    cin >> m;
    blocksize = (int)(sqrt(m - 0.001)) + 1;

    while (1)
    {
        cin >> cmd;
        if (strcmp(cmd, "add") == 0)
        {
            cin >> k >> x;
            addElement(k, x);
            cout << "Added element " << x << " at " << k << endl;
            cout << "List is : " << endl;
            printlist();
            cout << endl;
        }
        else if (strcmp(cmd, "search") == 0)
        {
            cin >> k;
            cout << "The element is : " << searchElement(k) << endl;
        }
        else if (strcmp(cmd, "exit") == 0)
        {

            return 0;
        }
        else
        {

            fprintf(stderr, "wrong input\n");
        }
    }

    return 0;
}