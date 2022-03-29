#include <bits/stdc++.h>
#define ll long long int
#define nl "\n"
#define vi vector<ll>
#define pb emplace_back
#define mod 1000000007
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// This function will check that number is prime or not
bool checkPrime(ll n)
{
    bool a = 1;                      // a is true we are assuming number is prime
    for (int i = 2; i * i <= n; i++) // this is an explicit function
    {
        if (n % i == 0)
        {
            a = false;
            break;
        }
    }
    return a; // if number is prime it will return true else falses
}

// Print prime factor
void primeFactor(ll n)
{
    bool a = 1; // true
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            cout << i << "^" << count << " ";
        }
    }
    if (n > 1)
    {
        cout << n << "^" << 1;
    }
    cout<<nl;
}

// Print prime till n (Sieve of Eratosthenes)
void printPrime(ll n)
{
    vector<bool> prime(n, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    cout << "The prime number are in range of 0 to " << n << ":" << endl;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    cout<<nl;
}

int main()
{
    file_i_o();
    return 0;
}
