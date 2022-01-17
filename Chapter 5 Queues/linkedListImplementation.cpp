#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class queue
{
private:
    node *front = NULL;
    node *rear = NULL;

public:
    bool empty()
    {

        if (front == NULL && rear == NULL)
        {
            cout<<"Empty\n";
            return true;
        }

        return NULL;
    }

    void equeue(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->next = NULL;

        if (rear == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = rear->next;
        }
    }

    int dequeue()
    {
        if (empty())
        {
            return -1;
        }

        node *todel = front;
        if (todel == rear)
        {
            rear = NULL;
        }
        
        front = front->next;
        int data = todel->data;
        delete todel;

        return data;
    }

    int front_()
    {
        if (empty())
        {
           return -1;
        }
        

        return front->data;
    }
};

int main()
{

    queue q;

    q.dequeue();

    q.equeue(1);
    q.equeue(2);
    q.equeue(3);
    q.equeue(4);
    q.equeue(5);

    cout<<q.front_()<<endl;

    cout<<q.front_()<<endl;
    q.dequeue(); //1
    cout<<q.front_()<<endl;
    q.dequeue();//2
    cout<<q.front_()<<endl;
    q.dequeue();//3
    cout<<q.front_()<<endl;
    q.dequeue();//4
    cout<<q.front_()<<endl;
    q.dequeue();//5

    q.dequeue();


    q.equeue(6);
    cout<<q.front_()<<endl;



 

    return 0;
}