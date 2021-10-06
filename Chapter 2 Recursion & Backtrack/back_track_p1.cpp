#include <iostream>
using namespace std;


/*Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n.*/

int A[2];

void binary(int n)
{

    if (n < 1)
    {
     
     for (int i = 0; i < 2; i++)
     {
         cout<<A[i];
     }
     cout<<endl;
     
    }
    else{

   // cout<<"Set A["<<n-1<<"] to "<<"0"<<endl;
    A[n - 1] = 0;
    binary(n - 1);
   // cout<<"Set A["<<n-1<<"] to "<<"1"<<endl;
    A[n - 1] = 1;
    binary(n - 1);
    }

}
int main()
{

    binary(2);

    return 0;
}