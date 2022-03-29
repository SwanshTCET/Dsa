#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

void bubble(vi &ar)
{
    for(int i=1;i<ar.size();i++)
	{
		for(int j=0;j<ar.size()-i;j++)
		{
			if(ar[j]>ar[j+1])
			{
				swap(ar[j],ar[j+1]);
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
    bubble(arr);
    return 0;
}