#include <iostream>
using namespace std;

class queue
{

private:
    int front, rear;
    int size;
    int *arr;

public:
    queue(int capacity)
    {
        size = capacity;
        front = rear = 0;
        arr = new int[size];
    }

    void enqueue(int data)
    {

        if (full())
        {
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = data;
    }

    bool full()
    {
        if ((rear + 1) % size == front)
        {
            cout << "full\n";
            return 1;
        }
        return 0;
    }

    int dequeue()
    {

        if (empty())
        {
            return -1;
        }
        front = (front + 1) % size;
        int data = arr[front];
    }

    bool empty()
    {

        if (rear == front)
        {
            cout << "Empty\n";
            return 1;
        }

        return 0;
    }
    int front_()
    {
        if (!empty())
        {
            return arr[(front + 1)%size];
        }
        else
        {

            return -1;
        }
    }

    void getpos(){

        cout<<"front = "<<front<<" rear = "<<rear<<endl;
    }
};

int main()
{
    queue q(4);

    q.dequeue(); // empty

    q.enqueue(1); // valid 

    q.enqueue(2); // valid

    q.enqueue(3); // valid

    q.enqueue(4); // full

    cout << q.front_() << endl; // 1

    q.enqueue(5); // full

    q.dequeue(); // valid

    cout << q.front_() << endl; // 2
    q.dequeue();
    cout << q.front_() << endl; //3
    q.dequeue();
    cout << q.front_() << endl; // -1 empty

    q.dequeue(); // empty

    q.getpos();

    q.enqueue(5);

    cout << q.front_() << endl;


/*
Space Complexity (for n EnQueue operations) O(n)
Time Complexity of EnQueue() O(1)
Time Complexity of DeQueue() O(1)
Time Complexity of IsEmptyQueue() O(1)
Time Complexity of IsFullQueue() O(1)
Time Complexity of QueueSize() O(1)
Time Complexity of DeleteQueue() O(1)

*/ 

    return 0;
}