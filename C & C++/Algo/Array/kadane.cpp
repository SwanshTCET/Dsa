#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

ll maxSubarray(vi arr)
{
    ll maxSum = INT_MIN;
    ll currSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];
        if (maxSum < currSum)
        {
            maxSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{

    return 0;
}