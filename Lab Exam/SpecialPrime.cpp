#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <climits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <numeric> 
#include <vector>
#include <unordered_map>
#include <stdio.h>  
#include <string.h> 
#include <math.h>

using namespace std;
#define ll long long

ll N, K;

bool check_prime(ll i)
{
    bool prime = 1;
    for (ll j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            prime = 0;
        }
    }
    return prime;
}

vector <int> primes;
int main()
{
    cin >> N >> K;
    ll sum = 0;
    primes.push_back(2);
    for (ll i = 3; i < N+1; i++)
    {
        bool prime = 1;
        for (int j = 2; j < i; j++)
        {
            if (i%j == 0)
            {
                prime = 0;
            }
        }
        if (prime)
        {
            primes.push_back(i);
        }
    }
    /*for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }*/
    bool find = 0;
    if (K <= N)
    {
        for (int i = 0; i < primes.size(); i++)
        {
            /*for (int j = (i+1); j < primes.size(); j++)
            {
                cout << primes[i] << " ";
            }*/
            if (N == 2)
                break;
            ll special = 1 + primes[i] + primes[i + 1];
            if (special >= 2 && special <= N)
            {
                if (check_prime(special))
                {
                    sum++;
                    if (sum >= K)
                    {
                        find = 1;
                        break;
                    }
                }
            }
        }
    }
    
    
    cout << find;


    return 0;
}