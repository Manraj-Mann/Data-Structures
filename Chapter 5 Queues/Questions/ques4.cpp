/*Given a stack of integers, how do you check whether each successive pair of
numbers in the stack is consecutive or not. The pairs can be increasing or decreasing, and
if the stack has an odd number of elements, the element at the top is left out of a pair. For
example, if the stack of elements are [4, 5, -2, -3, 11, 10, 5, 6, 20], then the output should
be true because each of the pairs (4, 5), (-2, -3), (11, 10), and (5, 6) consists of
consecutive numbers.*/

#include <iostream>
#include <vector>
#include <stack>

bool successive_pair(std::vector<int> &vec)
{

    std::stack<int> input;

    for (int i = 0; i < vec.size(); i++)
    {
        input.push(vec[i]);
    }

    std::stack<int> even_stack;

    while (!input.empty())
    {
        even_stack.push(input.top());
        input.pop();
    }

    while (even_stack.size() > 1)
    {
        int n = even_stack.top();
        even_stack.pop();
        int m = even_stack.top();
        even_stack.pop();

        input.push(n);
        input.push(m);

        if (std::abs(n - m) != 1)
        {
            return false;
        }

    }

    // storing back again and see the order

    while (!even_stack.empty())
    {
        input.push(even_stack.top());
        even_stack.pop();
    }



    return true;
}

int main()
{
    std::vector<int> vec = {4, 5, -2, -3, 11, 10, 5, 6, 20 };

    if (successive_pair(vec))   
    {
        std::cout<<"Ordered Pairwise";
    }
    else{

        std::cout<<"Not Ordered Pairwise";

    }
    

    return 0;
}