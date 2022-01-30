#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

// this function will take a vector , and a element which want to search as argrument
// and return a position as argrument if value is -1 then element is not present
int linearSearch(vi arr, int x)
{
    int pos = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{

    return 0;
}