// How can you implement a queue using two stacks?

#include <iostream>
#include <stack>

class queue
{
private:
    stack<int> enqueue_;
    stack<int> dequeue_;
public:
    queue();

    void enqueue(int data){

        enqueue_.push(data);
    }

    int dequeue(){
        int data;
        if (!dequeue_.empty())
        {
            data = dequeue_.top();
            return data;
        }
        else{

            while (!enqueue_.empty())
            {
                dequeue_.push(enqueue_.top());
                enqueue_.pop();

            }

            data = dequeue_.top();
            return data;
            
        }
        
    }
   
};




using namespace std;

int main(){
    

return 0;
}