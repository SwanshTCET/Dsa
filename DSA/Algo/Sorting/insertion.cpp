#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

void insertion(vi &ar)
{
    for (int i = 1; i < ar.size(); i++)
    {
        ll temp = ar[i];
        int j=i-1;
        while(j>=0&&ar[j]>temp)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
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
    insertion(arr);
    return 0;
}