#include <iostream>
using namespace std;

class dqueue
{

private:
    int rear, front;
    int size;
    int *arr;

public:
    dqueue(int capacity)
    {

        size = capacity;
        rear = front = 0;
        arr = new int[capacity];
    }

    void print()
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void push_front(int data)
    {
        if (full())
        {
            return;
        }

        arr[front] = data;
        front--;

        if (front == -1)
        {
            front = size - 1;
        }
    }

    void push_back(int data)
    {
        if (full())
        {
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = data;
    }

    int pop_front()
    {
        if (empty())
        {
            return -1;
        }

        front = (front + 1) % size;
        int data = arr[front];
        arr[front]= 0;

        return data;
    }

    int pop_back()
    {
        if (empty())
        {
            return -1;
        }

        int data = arr[rear];
        arr[rear]= 0;

        rear = (rear - 1) % size;

        if (rear == -1)
        {
            rear = size - 1;
        }

        return data;
        
    }

    bool empty()
    {
        if (rear == front)
        {
            cout << "Empty\n";
            return true;
        }

        return false;
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
    int front_()
    {
        return arr[(front + 1) % size];
    }
    int back_()
    {

        return arr[rear];
    }
};

int main()
{
    dqueue q(10);

    q.empty();

    q.push_back(2);

    cout << q.front_() << endl;

    q.push_front(1);

    cout << q.front_() << endl;

    q.push_front(0);

    cout << q.front_() << endl;
    q.push_front(100);

    cout << q.front_() << endl;

    q.push_front(300);

    cout << q.front_() << endl;

    q.push_back(3);

    cout << q.back_() << endl;

    q.push_back(4);

    cout << q.back_() << endl;

    q.pop_back();

    cout << q.back_() << endl;

    q.pop_front();

    cout << q.front_() << endl;

    cout << q.back_() << endl;

    cout << "---------------------\n";
    // cout << q.pop_front() << endl;
    // cout << q.pop_front() << endl;
    // cout << q.pop_front() << endl;
    // cout << q.pop_front() << endl;
    // cout << q.pop_front() << endl;
    // cout << q.pop_front() << endl;


    cout << "poped : "<<q.pop_back() << endl;
    cout << "poped : "<<q.pop_back() << endl;
    cout << "poped : "<<q.pop_back() << endl;
    cout << "poped : "<<q.pop_back() << endl;
    cout << "poped : "<<q.pop_back() << endl;
    cout << "poped : "<<q.pop_back() << endl;

    return 0;
}