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

    void resize(){

        int * old_arr = arr;

        arr = new int[2*size];

        for ( int i = 0; i < size; i++)
        {
            arr[i] = old_arr[i];
        }

        size *= 2;
        
    }

    void enqueue(int data)
    {

        if (full())
        {

            resize();
        }

        rear = (rear + 1) % size;
        arr[rear] = data;
    }

    bool full()
    {
        if ((rear + 1) % size == front)
        {
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
        return data;
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

   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.enqueue(5);
   q.enqueue(6);
   q.enqueue(7);

   cout<<q.front_()<<endl;

   q.getpos();

   q.dequeue(); //1
   cout<<q.front_()<<endl;
   q.dequeue();//2
   cout<<q.front_()<<endl;
   q.dequeue();//3
   cout<<q.front_()<<endl;
   q.dequeue();//4
   cout<<q.front_()<<endl;
   q.dequeue();//5
   cout<<q.front_()<<endl;
   q.dequeue();//6
   cout<<q.front_()<<endl;
   q.dequeue();//7

   cout<<q.front_()<<endl; // empty -1
   q.dequeue(); // empty
   cout<<q.front_()<<endl; //empty -1


   q.enqueue(10);
   q.enqueue(11);
   cout<<q.front_()<<endl; //10
   q.dequeue();//10
   cout<<q.front_()<<endl;//11


    return 0;

}