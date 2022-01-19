/*Problem-4 Maximum sum in sliding window: Given array A[] with sliding window of size
w which is moving from the very left of the array to the very right. Assume that we can
only see the w numbers in the window. Each time the sliding window moves rightwards by
one position. For example: The array is [1 3 -1 -3 5 3 6 7], and w is 3.*/ 

/*Window position      Max
[1 3 -1] -3 5 3 6 7     3
1 [3 -1 -3] 5 3 6 7     3
1 3 [-1 -3 5] 3 6 7     5
1 3 -1 [-3 5 3] 6 7     5
1 3 -1 -3 [5 3 6] 7     6
1 3 -1 -3 5 [3 6 7]     7
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> sliding_window(vector<int> &vec , int k){

    int i = 0;
    deque<int> window;
    vector<int> results;
    while (i < vec.size())
    {

        while (!window.empty() && window.back() < vec[i])
        {
            window.pop_back();
        }

        window.push_back(vec[i]);
    
        if (i >= k-1)
        {
            results.push_back(window.front());
        }
        
        
        i++;
        
    }


    return results;
    


}

int main(){

    vector<int> vec = {1, 3, -1, -3, 5 ,3 ,6 ,7};

    vector<int> res = sliding_window(vec , 3);

    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    
    

return 0;
}