/*Given a queue of integers, rearrange the elements by interleaving the first half of
the list with the second half of the list. For example, suppose a queue stores the following
sequence of values: [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]. Consider the two halves of
this list: first half: [11, 12, 13, 14, 15] second half: [16, 17, 18, 19, 20]. These are
combined in an alternating fashion to form a sequence of interleave pairs: the first values
from each half (11 and 16), then the second values from each half (12 and 17), then the
third values from each half (13 and 18), and so on. In each pair, the value from the first
half appears before the value from the second half. Thus, after the call, the queue stores the
following values: [11, 16, 12, 17, 13, 18, 14, 19, 15, 20].*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void interLeaving(queue<int> &q)
{

    if (q.size() % 2 != 0)
    {
        return;
    }

    queue<int> part1;

    int n = q.size() / 2;

    for (int i = 0; i < n; i++)
    {
        part1.push(q.front());
        q.pop();
    }

    queue<int> result;

    while (!q.empty())
    {
        result.push(part1.front());
        result.push(q.front());

        part1.pop();
        q.pop();
    }

    while (!result.empty())
    {
        cout << result.front() << " ";
        result.pop();
    }


}

int main()
{

    vector<int> input = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    queue<int> imput_;

    for (int i = 0; i < input.size(); i++)
    {
        imput_.push(input[i]);
    }

    interLeaving(imput_);
    
    return 0;
}
