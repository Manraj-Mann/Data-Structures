#include <iostream>
using namespace std;

/*
    Generate all the strings of length n drawn from 0... k – 1.
*/

int A[2];

void binary(int n, int k)
{

    if (n < 1)
    {

        for (int i = 0; i < 2; i++)
        {
            cout << A[i];
        }
        cout << endl;
    }
    else
    {
        for (int j = 0; j < k; j++)
        {
            A[n - 1] = j;
            binary(n - 1, k);
        }
    }
}
int main()
{

    binary(2, 10);

    /*
      Let T(n) be the running time of k – string(n).
     Then, Using Subtraction and Conquer Master theorem we get: T(n) = O(k^n).
     
    */

    return 0;
}