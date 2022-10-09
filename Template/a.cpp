/*
   _,,
  [|/
   //
 //    _
(_|)   |@@|
 \ \__ \--/ __
  \o_|----|  |   _
      \ }{ /\ )_ / _\
      /\_/\ \O (_
     (--/\--)    \__/
     )(  )(
    `---''---`

    Don't Copy Code Or Plag will kill You
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define nl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define vop vector<pair<ll, ll>>
#define pb emplace_back
#define ppb pop_back
#define pi 3.141592653589793238462
#define mod 1000000007

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class k, class v>
using ordered_map = tree<k, v, less<k>, rb_tree_tag, tree_order_statistics_node_update>;

//#define rapid_killer_9
#ifdef rapid_killer_9
#define erl cerr << endl;
#define debug(x) cerr << #x << " "; _print(x); cerr << nl
#else
#define erl ;
#define debug(x) {};
#endif

void file_i_o(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve()
{
	
}

int main ()
{
	file_i_o();
	int t=1;
	// cin>>t;
	for(int i=1;i<=t;i++)
	{
		// cout<<"Case #"<<i<<": "; 
		solve();
        // cout<<nl;
	}
}
