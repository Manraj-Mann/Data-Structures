// Can we evaluate the infix expression with stacks in one pass?



#include <iostream>
#include <climits>
using namespace std;
class Stack
{
private:
    int m_top = -1;
    int capacity;
    char *arr;

public:
    Stack() {}

    void resize()
    {

        char *arr_old = arr;
        arr = new char[2 * capacity];

        for (int i = 0; i <= capacity; i++)
        {
            arr[i] = arr_old[i];
        }

        capacity *= 2;

        delete[] arr_old;
    }
    Stack(int cap)
    {
        capacity = cap;
        arr = new char[cap];
    }

    Stack *create(int cap)
    {
        capacity = cap;
        arr = new char[cap];
    }

    void push(char data)
    {
        m_top++;
        if (isfull())
        {
            // cout<<"Resized\n";
            resize();
        }

        // cout<<"Pushed "<<data<<endl;
        arr[m_top] = data;
    }
    char pop()
    {

        if (isempty())
        {
            std::cout << "Stack Underflow";
            return CHAR_MAX;
        }

        return arr[m_top--];
    }

    bool isfull()
    {

        if (m_top == capacity)
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {

        if (m_top == -1)
        {
            return true;
        }
        return false;
    }

    void delete_stack()
    {

        delete[] arr;
    }

    char top()
    {

        return arr[m_top];
    }

    void print()
    {

        for (int i = 0; i <= m_top; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

bool isoperator(char c)
{

    if (c == '*' || c == '-' || c == '+' || c == '/' || c == '(' || c == ')')
    {
        return 1;
    }
    return 0;
}

// for binary operators

int evaluate_infix(string &str){


    Stack oprand(str.size());
    Stack operator_(str.size());

    for (int i = 0; i < str.size(); i++)
    {
        
    }
    






}


int main()
{

// Using 2 stacks we can evaluate an infix expression in 1 pass without converting to
// postfix.
    string str = "123*+5-";

 
    return 0;
}