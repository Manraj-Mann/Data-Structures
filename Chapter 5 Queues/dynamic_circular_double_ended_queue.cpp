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
    void resize()
    {

        int *old_arr = arr;
        arr = new int[2 * size];
        size = size * 2;

        for (int i = 0; i <= rear; i++)
        {
            arr[i] = old_arr[i];
        }

        if (front != 0)
        {
            int k = size - 1;
            for (int i = size / 2 - 1; i > front; i--, k--)
            {
                arr[k] = old_arr[i];
            }

            front = k;
        }

    }

    void push_front(int data)
    {

        if (full())
        {
            resize();
        }
        arr[front] = data;
        front--;

        if (front == -1)
        {
            front = size -1;
        }
        print();
    }

    void push_back(int data)
    {

        if (full())
        {

            resize();
        }

        rear = (rear + 1) % size;
        arr[rear] = data;
        print();
    }

    int pop_front()
    {
        if (empty())
        {
            return -1;
        }

        front = (front + 1) % size;
        int data = arr[front];

        return data;
    }

    int pop_back()
    {
        if (empty())
        {
            return -1;
        }

        int data = arr[rear];

        rear = (rear - 1) % size;

        if(rear == -1){

            rear = size -1;

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
           // cout << "Full\n";
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
    dqueue q(2);

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

    cout << q.back_() << endl; //4

    q.pop_back(); //4

    cout << q.back_() << endl; //3

    q.pop_front(); //300

    cout << q.front_() << endl; // 100



    cout << "---------------------\n";
    cout << q.pop_front() << endl; //100
    cout << q.pop_front() << endl;
    cout << q.pop_front() << endl;
    cout << q.pop_front() << endl;
    cout << q.pop_front() << endl;
    cout << q.pop_front() << endl;

    return 0;
}