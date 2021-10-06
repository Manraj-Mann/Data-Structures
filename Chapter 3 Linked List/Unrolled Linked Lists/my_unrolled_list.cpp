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
    ListNode *ls = blockhead->head->next;
    int i = 0, j = 1;
    cout << "elements in " << j << " th block : ";
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
                j++;
                i = -1;
                bh = bh->next;
                ls = bh->head->next;
                cout << "\nelements in " << j << " th block : ";
            }
        }
    }
}

// search element

void searchElement(int k, LinkedBlock **flinkedBlock, ListNode **flistNode)
{
    // find the block

    int j = (k + blocksize) / blocksize; // kth node in jth block
    LinkedBlock *p = blockhead;
    *flinkedBlock = NULL;
    while (--j)
    {
        p = p->next;
    }
    *flinkedBlock = p;
    if (*flinkedBlock == NULL)
    {
        return;
    }

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

    //cout<<"In search at block = "<<j<<" node = "<<q->value<<endl;
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
           // cout<<"Inside 2nd shift\n";
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
            if (r == NULL)
            {

              //  std::cout << "inside r = NULL"
                       //   << "\n";
                r = blockhead;
                while (r->next != NULL)
                {
                    r = r->next;
                }
                r->next = newLinkedBlock();
                ListNode *newn = newListNode(x);

                r->next->head = newn;
                r->next->head->next = newn;
                r->next->nodecount++;
               // std::cout << "Done r = NULL"
               //           << "\n";
            }
            else
            {

                q = p;
                while (q->next != p)
                {
                    q = q->next;
                }
              //  cout<<"Inerting after = "<<q->value<<endl;
                q->next = newListNode(x);
                q->next->next = p;
                r->nodecount++;
                shift(r);
            }
        }
    }
}

int searchElement(int k)
{

    ListNode *p;
    LinkedBlock *q;
    searchElement(k, &q, &p);
    for (int  i = 0; i < q->nodecount -1 ; i++)
    {
        p = p->next;
    }
    
    return p->value;
}

int main()
{

    int tt = clock();
    int m, i, k, x;
    char cmd[10];
    int count = 0;
        cin >> m;
    blocksize = (int)(sqrt(m - 0.001)) + 1;

    while (1)
    {
        
        if (count == 0)
        {
            for (int i = 0; i < 9; i++)
            {

                addElement(i, i + 1);
                printlist();
                cout << endl;
                
            }
            count++;
        }

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

            break;
        }
        else
        {

            fprintf(stderr, "wrong input\n");
        }
    }


//   LinkedBlock * b =  blockhead;

//   while (b != NULL)
//   {
//       cout<<b->head->value<<endl;
//       b = b->next;
//   }
  
    

    return 0;
}