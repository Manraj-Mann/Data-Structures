#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSKIPLEVEL 5
struct listnode
{
    int data;
    listnode * next[1];
};

struct skiplist{
    
    listnode * header;
    int listlvl;        /// current level of list ///

};

skiplist list;

listnode * insert_element(int data){

    int i , newlvl;
    listnode * update[MAXSKIPLEVEL + 1];
    listnode * temp;

    temp = list.header;
    for ( i = list.listlvl ; i >= 0; i-- )
    {
        while (temp->next[i] != list.header && temp->next[i]->data < data)
        {
            temp = temp->next[i];
        }
        update[i] = temp;

        
    }
    temp = temp->next[0];
    if (temp != list.header && temp->data == data)
    {
        return temp;
    }
    // detemine level
    for (newlvl  = 0; rand() < RAND_MAX/2 && newlvl < MAXSKIPLEVEL ; newlvl++);
    cout<<"\nnew level - "<<newlvl<<endl;
    if (newlvl > list.listlvl)
    {
        for ( i = list.listlvl + 1 ; i <= newlvl ; i++)
        {
            update[i] = list.header;

        }
        list.listlvl = newlvl;
        
    }

    // Make new node 

    if ((temp = new listnode[(sizeof(listnode) + newlvl * sizeof(listnode *) )]) == 0)
    {
        cout<<"Insufficent memory\n";
        exit(1);
    }

    temp->data = data;
    for ( i = 0; i <= newlvl; i++)  // update link links
    {
        temp->next[i] = update[i]->next[i];
        update[i]->next[i] = temp;

    }

    return temp;  
    
}
void delete_element( int data ){

    int i ;
    listnode * update[MAXSKIPLEVEL + 1], * temp;
    temp = list.header;
    for ( i = list.listlvl; i >= 0; i--)
    {
        while (temp->next[i] != list.header && temp->next[i]->data < data )
        {
            temp = temp->next[i];
        }
        
        update[i] = temp;
    }

    temp = temp->next[0];

    if( temp == list.header || !(temp->data == data )){
         return;
    }

     // adjust next pointer

    for (int i = 0; i <= list.listlvl ; i++)
    {
         if (update[i]->next[i] != temp )   
         {
             break;
         }
         update[i]->next[i] = temp->next[i];
        
    }

    delete temp;

    // adjust header file 
    while ((list.listlvl > 0 ) && (list.header->next[list.listlvl] == list.header))
    {
        list.listlvl--;
    }   
}
// find a node containg data
listnode * find_element(int data){

    int i;
    listnode * temp = list.header;
    for ( i = list.listlvl; i>= 0; i-- )
    {
        while (temp->next[i] != list.header && temp->next[i]->data < data)
        {
            temp = temp->next[i];
        }
        
    }

    temp = temp->next[0];
    if (temp != list.header && temp->data == data )
    {
        return temp;
    }

    return 0;   
    
}

// initilize skip list

void initList(){

    int i ;
    if ( ( list.header = new  listnode [sizeof( listnode ) + MAXSKIPLEVEL * sizeof( listnode * )])  == 0 )
    {
        cout<<"Memory Error\n";
        exit(1);


        listnode * o ;
        
    }

    for (int i = 0; i <= MAXSKIPLEVEL; i++)
    {
        cout<<"next["<<i<<"] = "<<list.header->next[i]<<endl;
    }
    

    for ( i = 0; i <= MAXSKIPLEVEL ; i++)
    {
        list.header->next[i] = list.header;
        cout<<"setting list.header->next["<<i<<"] = "<<list.header<<endl;
    }

    list.listlvl = 0;
    
    
}


int main(){


    int i , *a , maxnum ;
    cin>>maxnum; 

    initList();

    if ( (a = new int[maxnum * sizeof(*a)] ) == 0 )
    {
        cout<<"Insuffcient memory\n";
    }

    for (int i = 0; i < maxnum; i++)
    {
        a[i] = rand();
        cout<<" Random item = "<<a[i]<<" index =  "<<i<<endl;

    }

    for (int i = 0; i < maxnum; i++)
    {
        cout<<"Inserted = "<<a[i]<<endl;
        insert_element(a[i]);
    }
    for (int i = 0; i < maxnum; i++)
    {
        cout<<"Tried = "<<a[i]<<"found "<< (find_element(a[i]))->data<<endl;
    }
    for (int i = 0; i < maxnum; i++)
    {
        delete_element(a[i]);
    }
    
    if (find_element(a[0]) == 0)
    {
        cout<<"Notfound\n";
    }

   // initList();

   // insert_element(a[0]);
    
    if (find_element(a[0]) == 0)
    {
        cout<<"Notfound\n";
    }
    
return 0;
}