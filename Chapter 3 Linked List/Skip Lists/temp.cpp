#include<iostream>
using namespace std;

struct manraj{
    manraj* Ptr[1];
    int data;

};

struct a{
 manraj* header;
};

struct a* list;

int main(){

    
   list->header = (manraj*)malloc(sizeof(manraj)+5*sizeof(manraj*));
   
    cout<<list->header->Ptr[1]<<endl;
   
    
}