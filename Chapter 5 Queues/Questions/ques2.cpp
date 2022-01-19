// How can you implement a queue using two stacks?

#include <iostream>
#include <stack>
using namespace std;

class queue_
{
private:
    stack<int> enqueue_;
    stack<int> dequeue_;

public:
    void enqueue(int data)
    {

        enqueue_.push(data);
    }

    int dequeue()
    {

        int data;
        if (enqueue_.empty() && dequeue_.empty())
        {
            cout << "Empty\n";
            return -1;
        }

        if (!dequeue_.empty())
        {
            data = dequeue_.top();
            dequeue_.pop();
            return data;
        }
        else
        {
            while (!enqueue_.empty())
            {
                dequeue_.push(enqueue_.top());
                enqueue_.pop();
            }

            data = dequeue_.top();
            dequeue_.pop();
            return data;
        }
    }
};

int main()
{

    queue_ q;

    q.dequeue();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;

    return 0;
}