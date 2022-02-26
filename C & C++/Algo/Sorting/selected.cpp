#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

void selected(vi &ar)
{
    for (int i = 0; i < ar.size(); i++)
    {
        for (int j = i+1; j < ar.size(); j++)
        {
            if(ar[i]>ar[j])
            {
                swap(ar[i],ar[j]);
            }
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selected(arr);
    return 0;
}