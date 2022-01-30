#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

// for this searching technique array should be in sorted mannner
// This function will take vector and key which we have to find as an argrument
// Position are 0 based index
int binarySearch(vi arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int pos = -1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == x)
        {
            pos = mid;
            break;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return pos;
}

int main()
{

    return 0;
}