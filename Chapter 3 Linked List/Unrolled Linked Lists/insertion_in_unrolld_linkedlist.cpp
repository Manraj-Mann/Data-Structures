#include <iostream>
#include <math.h>
using namespace std;

int nodesperb;

struct node
{
    int data;
    node *next;
};

struct block
{
    int nodecount;
    block *next;
    node *head;
};

void traverse(block *head)
{

    block *p = head;
    if (p == NULL)
    {
        cout << "Empty list \n";
        return;
    }

    node *q = p->head->next;
    cout << "The elements are : ";
    for (int i = 0; i < p->nodecount; i++)
    {
        std::cout << q->data << " ";
        q = q->next;
        // cout<<" i = "<<i<<endl;

        if (i == p->nodecount - 1)
        {

            if (p->next != NULL)
            {

                i = -1;
                p = p->next;
                q = p->head->next;
            }
            else
            {

                break;
            }
        }
    }
    cout << endl;
}
node *newnode(int data)
{

    node *newnode = new node[sizeof(node)];
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
block *newblock()
{

    block *newblock = new block[sizeof(node)];
    newblock->head = NULL;
    newblock->next = NULL;
    newblock->nodecount = 0;
    return newblock;
}
void searchElement(int k, block **head, block **flinkedBlock, node **flistNode)
{
    // find the block
    *flinkedBlock = NULL;
    int j = (k + nodesperb - 1) / nodesperb; // kth node in jth block
    cout << " k = " << k << " and j = " << j << endl;
    block *p = *head;
    while (--j)
    {
        p = p->next;
    }
    *flinkedBlock = p;
    cout << "found block\n";

    if (*flinkedBlock == NULL)
    {
        return;
    }

    // find node

    node *q = p->head;

    k = k % nodesperb;
    if (k == 0)
    {
        k = nodesperb;
    }
    k = p->nodecount + 1 - k;
    while (k--)
    {
        q = q->next;
    }

    *flistNode = q;
    cout << "found node\n";
    return;
}
void shift(block *A)
{

    block *B;
    node *temp;

    while (A->nodecount > nodesperb) // if this block still have to shift
    {
        if (A->next == NULL) // reached end A little different
        {
            A->next = newblock();
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
void insert(block **head, int data, int k)
{

    if (*head == NULL)
    {
        std::cout << "Inside head NULL\n";
        *head = newblock();
        node *newn = newnode(data);
        (*head)->head = newn;
        (*head)->head->next = newn;
        (*head)->nodecount++;
        return;
    }
    else
    {

        node *p, *q;
        block *r;
        if (k == 0)
        {
            std::cout << "Inside k =  NULL\n";
            p = (*head)->head;
            q = p->next;
            p->next = newnode(data);
            p->next->next = q;
            (*head)->head = p->next;
            (*head)->nodecount++;

            // Apply shift here
            shift(r);
        }
        else
        {
            std::cout << "Inside k = " << k << "\n";
            searchElement(k, head, &r, &p);
            cout << "returned\n";
            if (r == NULL)
            {

                std::cout << "inside r = NULL"
                          << "\n";
                r = *head;
                while (r->next != NULL)
                {
                    r = r->next;
                }
                r->next = newblock();
                node *newn = newnode(data);

                r->next->head = newn;
                r->next->head->next = newn;
                r->next->nodecount++;
                std::cout << "Done r = NULL"
                          << "\n";
            }
            else
            {
                std::cout << "inside q = p "
                          << "\n";
                q = p;
                while (q->next != p)
                {
                    q = q->next;
                    cout << q->data << endl;
                }
                q->next = newnode(data);
                q->next->next = p;
                r->nodecount++;
                shift(r);
                std::cout << "Done q = p "
                          << "\n";
            }
        }
    }
}

int main()
{

    int m = 9;

    nodesperb = (int)(sqrt(m - 0.001)) + 1;

    block *head = NULL;

    traverse(head);

    insert(&head, 10, 0);
    insert(&head, 11, 1);
    insert(&head, 12, 2);
    insert(&head, 13, 3);
    insert(&head, 14, 4);
    insert(&head, 15, 5);
    insert(&head, 16, 6);
    insert(&head, -1, 0);
    insert(&head, -2, 0);
  

    traverse(head);

    node *temp = head->head;
    block *tempb = head;
    for (int j = 0; tempb != NULL; j++)
    {
        cout<<"Block "<<j+1<<" : ";

        for (int i = 0; i < nodesperb; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;

        tempb = tempb->next;
        temp = tempb->head;
    }

    return 0;
}