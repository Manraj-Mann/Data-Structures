#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <climits>
using namespace std;
#define MAXSKIPLEVEL 5

struct pointer
{
    int data;
    pointer *down;
    pointer *forward;
};
struct skiplist
{

    pointer *header;
    int listlvl; /// current level of list ///
};
skiplist list;

// -----------------------------------------------------------------------------------------------------//
 //      User record and use approrach in deletion which can also be used in insertion easily        //
             //*********** Current - approach and update *********** //
void insertion(int data)
{
    int newlvl;

    for (newlvl = 0; rand() < RAND_MAX / 2 && newlvl < MAXSKIPLEVEL; newlvl++)
        ;

    cout << " new lvl = " << newlvl << endl;
    pointer *newnode = new pointer[newlvl + 1];
    pointer *ptr = list.header;
    int i = MAXSKIPLEVEL;
    while (i != newlvl)
    {
        ptr = ptr->down;

        i--;
    }
    for (int i = newlvl; i >= 0; i--)
    {

        if (i != 0)
        {
            newnode[i].down = &newnode[i - 1];
        }
        else
        {

            newnode[i].down = NULL;
        }
        // cout << "Setting up p[" << i << "].down = " << p[i].down << endl;
    }
    // cout<<"at i = "<<i<<endl;

    for (int i = newlvl; i >= 0; i--)
    {
        newnode[i].data = data;
        //   /  cout<<"newnode["<<i<<"].data = "<<data<<endl;
    }

    int k = newlvl, assigned;
    while (k != -1)
    {

        //  cout<<"at k = "<<k<<endl;

        if (ptr->forward == NULL)
        {
            // cout<<"Inside NULL\n";
            newnode[k].forward = ptr->forward;
            //  cout<<"setting newnode["<<k<<"].forward = NULL \n";
            ptr->forward = &newnode[k];
            ptr = ptr->down;
            k--;
            assigned = 1;
        }
        else if (ptr->forward->data == data)
        {
            while (k != -1)
            {
                newnode[k].forward = ptr->forward;
                ptr->forward = &newnode[k];
                ptr = ptr->down;
                k--;
            }
            assigned = 1;
        }
        else if (ptr->forward->data > data)
        {
            // cout<<"setting newnode["<<k<<"].forward next to " <<ptr->data<<" \n";
            newnode[k].forward = ptr->forward;
            ptr->forward = &newnode[k];
            ptr = ptr->down;
            assigned = 1;
            k--;
        }
        else if (ptr->forward->data < data)
        {
            ptr = ptr->forward;
            assigned = 0;
        }
    }
    //  cout<<"Inserted\n";
}
pointer *search(int key, int type = 0)
{

    pointer *ptr = list.header;
    ptr = ptr->down;
    int k = MAXSKIPLEVEL - 1;
    while (k != -1)
    {

        if (ptr->forward == NULL)
        {
            ptr = ptr->down;
            k--;
        }
        else if (ptr->forward->data == key)
        {
            if (type == 1)
            {
                return ptr;
            }

            return ptr->forward;
        }
        else if (ptr->forward->data > key)
        {

            ptr = ptr->down;
            k--;
        }
        else if (ptr->forward->data < key)
        {
            ptr = ptr->forward;
        }

        if (k == -1)
        {
            return 0;
        }
    }
}
void traverse()
{
    pointer *ptr = list.header;
    while (ptr->down != NULL)
    {
        ptr = ptr->down;
    }
    ptr = ptr->forward;

    if (ptr == NULL)
    {
        //cout << "List is empty\n";
        return;
    }

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->forward;
    }
    cout << endl;
}
void deletion(int data)
{
   pointer * ptr = list.header->down;
   pointer * to_update[MAXSKIPLEVEL+1];
    int k = MAXSKIPLEVEL - 1;
    while (k != -1)
    {
       // cout<<"k = "<<k<<endl;
        if (ptr->forward == NULL)
        {
            to_update[k] = NULL;
            ptr = ptr->down;
            k--;
        }
        else if (ptr->forward->data == data)
        {
           
           to_update[k] = ptr;
           k--;
           ptr = ptr->down;
            
        }
        else if (ptr->forward->data > data)
        {

            to_update[k] = NULL;
            ptr = ptr->down;
            k--;
        }
        else if (ptr->forward->data < data)
        {
            ptr = ptr->forward;
        }
        if (ptr == NULL)
        {
            break;
        }
        

    }
  //  cout<<"found updation list\n";
    int i = MAXSKIPLEVEL - 1;
    while (i != -1)
    {
       // cout<<" i = "<<i<<endl;
      if(to_update[i] == NULL){
        //  cout<<"inside null\n";

          i--;
      }
      else
      {
       //   cout<<"inside else\n";
        pointer * del = to_update[i]->forward;
          to_update[i]->forward = to_update[i]->forward->forward;
          delete del;
          i--;
      }
     
    }

    
}
void initialize()
{
    pointer *p = new pointer[MAXSKIPLEVEL + 1];
    for (int i = MAXSKIPLEVEL; i >= 0; i--)
    {
        p[i].forward = NULL;
        p[i].data = INT_MIN;
        if (i != 0)
        {

            p[i].down = &p[i - 1];
        }
        else
        {

            p[i].down = NULL;
        }
        // cout << "Setting up p[" << i << "].down = " << p[i].down << endl;
    }

    list.header = &p[MAXSKIPLEVEL];
}
int main()
{
    initialize();

    insertion(10);

    insertion(11);

    insertion(9);

    insertion(14);
 
    insertion(12);
 
    traverse();
    int key;
    cout << "Enter the value you want to search : ";
    cin >> key;
    if (search(key) != 0)
    {
        cout << "Found\n";
    }
    else
    {

        cout << "Not Found\n";
    }
    cout << "Enter the value you want to delete : ";
    cin>>key;
    deletion(key);
    traverse();



    return 0;
}