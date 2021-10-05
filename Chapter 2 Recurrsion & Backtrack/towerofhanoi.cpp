#include <iostream>
using namespace std;

void towerofhanoi(int n , char frompeg , char topeg , char aux){

    if (n==1)
    {
        cout<<"Move disk 1 from "<<frompeg<<" to "<<topeg<<endl;
        return;
    }

    towerofhanoi(n-1 , frompeg , aux , topeg);
    cout<<"Move disk "<<n<<" from "<<frompeg<<" to "<<topeg<<endl;
    towerofhanoi(n-1 , aux , topeg , frompeg);
    
}
int main(){

    int n ;
    cin>>n;
    towerofhanoi(n , 'A' , 'B' , 'C');
    
return 0;
}