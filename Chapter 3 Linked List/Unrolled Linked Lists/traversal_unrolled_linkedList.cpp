#include <iostream>
#include <math.h>
using namespace std;

int nodesperb;

struct node{
    int data;
    node * next;
};
    
struct block{
    int nodecount;
    block * next;
    node * head;
};


// 
void traverse(block *head)
{

    block *p = head;
    if (p == NULL)
    {
        cout<<" Empty list \n";
    }
    
    node *q = p->head;
     cout << "The elements are : ";
    for (int i = 0; i < p->nodecount; i++)
    {
        std::cout << q->data << " ";
          q = q->next;
         // cout<<" i = "<<i<<endl;

        if (i == p->nodecount-1  )
        {

            if (p->next != NULL)
            {

                i = -1;
                p = p->next;
                q = p->head;
            }
            else 
            {

                break;
            }
        }
      
    }
    cout<<endl;
}

int main(){

    int m = 9 , data;
    // cout<<" How much initial data you want to enter : ";
    // cin>>m;

    nodesperb =  (int )(sqrt(m - 0.001))+1;

    block * b1 = new block;
    block * b2 = new block;
    block * b3 = new block;

    node * n1 = new node;
    node * n2 = new node;
    node * n3 = new node;
    node * n4 = new node;
    node * n5 = new node;
    node * n6 = new node;
    node * n7 = new node;
    node * n8 = new node;
    node * n9 = new node;


    b1->next = b2; 
    b2->next = b3;
    b3->next = NULL;
    b1->nodecount = 3;
    b2->nodecount = 3;
    b3->nodecount = 3;

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n3->next = n2;
    n2->next = n1;
    n1->next = n3;
    n4->data = 4;
    n5->data = 5;
    n6->data = 6;
    n6->next = n5;
    n5->next = n4;
    n4->next = n6;
    n7->data = 7;
    n8->data = 8;
    n9->data = 9;
    n9->next = n8;
    n8->next = n7;
    n7->next = n9;

    block * head = b1;

     b1->head = n1;
     b2->head = n4;
     b3->head = n7;

    //cout<<"The elements are : ";
    traverse(head);

    
    

return 0;
}