#include <iostream>
using namespace std;

class queue
{

    int front = -1;
    int rear = -1;
    int *arr;
    int size;
    int count = 0;

public:
    queue(int cap)
    {
        arr = new int[cap];
        size = cap;
    }

    void enqueue(int data)
    {
        front++;
        if (isFull())
        {
            cout << "Full Queue Exception\n";
            front--;
            return;
        }

        arr[front] = data;
        count++;
    }

    int dequeue()
    {
        
        if (isEmpty())
        {
            cout << "Empty Queue Exception\n";
            return -1000000000;
        }

        rear++;
        int data = arr[rear];
        count--;
        return data;
    }

    int front_()
    {

        return arr[front];
    }

    int queueSize()
    {

        return count;
    }

    bool isEmpty()
    {

        if ( (rear == front))
        {
            return true;
        }

        return false;
    }

    bool isFull()
    {

        if (front == size)
        {

            return true;
        }

        return false;
    }
};

int main()
{

    queue q(4);

    cout<<q.dequeue()<<endl;

    q.enqueue(1);
    q.enqueue(2);
    cout<<q.front_()<<endl;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.front_()<<endl;

    cout<<"--------------------------------\n";

    cout<<q.dequeue()<<endl;
    cout<<q.front_()<<endl;

    cout<<"--------------------------------\n";
    cout<<q.dequeue()<<endl;
    cout<<q.front_()<<endl;

    cout<<"--------------------------------\n";
    cout<<q.dequeue()<<endl;
    cout<<q.front_()<<endl;

    cout<<"--------------------------------\n";
    cout<<q.dequeue()<<endl;
    cout<<q.front_()<<endl;

    cout<<"--------------------------------\n";

    cout<<q.dequeue()<<endl;
    q.enqueue(5);

    cout<<"--------------------------------\n";

    



    return 0;
}