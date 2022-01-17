// Give an algorithm for reversing a queue Q. To access the queue, we are only
// allowed to use the methods of queue ADT

#include <iostream>
#include <stack>

using namespace std;
class queue
{
private:
    int front;
    int rear;
    int *arr;
    int size;

public:
    queue(int capacity)
    {

        arr = new int[capacity];
        size = capacity;
        rear = front = 0;
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
            cout << "Full\n";
            return true;
        }

        return false;
    }
    bool empty()
    {

        if (front == rear)
        {
           // cout << "Empty\n";
            return true;
        }

        return false;
    }
    int dequeue()
    {

        if (empty())
        {

            return -1;
        }
        front = (front + 1) % size;
        int data = arr[front];

        return data;
    }

    int front_()
    {
        if (!empty())
        {
            return arr[(front + 1) % size];
        }
        else
        {

            return -1;
        }
    }
};

void reverse(queue * q){

    stack<int> stk;

    while (!q->empty())
    {
        stk.push(q->dequeue());
    }

    while (!stk.empty())
    {
        q->enqueue(stk.top());
        stk.pop();
    }
    

}
int main()
{
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.front_()<<endl;

    reverse(&q);

    cout<<q.front_()<<endl;
    q.dequeue();
    cout<<q.front_()<<endl;


    return 0;
}