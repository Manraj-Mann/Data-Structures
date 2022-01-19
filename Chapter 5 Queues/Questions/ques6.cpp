/*Given an integer k and a queue of integers, how do you reverse the order of the
first k elements of the queue, leaving the other elements in the same relative order? For
example, if k=4 and queue has the elements [10, 20, 30, 40, 50, 60, 70, 80, 90]; the output
should be [40, 30, 20, 10, 50, 60, 70, 80, 90].
*/


#include <iostream>
#include <stack>
#include <queue>
using namespace std;


// using queue and stack O(n) & if double eneded queue O(k)

void reverse(queue<int> & q , int k ){

    stack<int> stk;

    for (int i = 0; i < k; i++)
    {
        stk.push(q.front());
        q.pop();
    }

    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }

    int n = q.size()-k;

    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
}

void print(queue<int> q){

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}
int main()
{
    queue<int> q;

    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int k = 4;

    for (int i = 0; i < vec.size(); i++)
    {
       q.push(vec[i]); 
    }
    
    reverse(q , k);
    print(q);
    
    return 0;
}

