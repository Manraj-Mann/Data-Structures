#include <iostream>
using namespace std;
int isSorted(int arr[], int n)
{

    if (n == 1)
    {
        return 1;
    }
    return (arr[n - 1] < arr[n - 2]) ? 0 : isSorted(arr, n - 1);
}
int main()
{

    int arr[] = {1, 0, 3, 4, 5};
    cout << isSorted(arr , sizeof(arr)/sizeof(arr[0]));
    
return 0;
}