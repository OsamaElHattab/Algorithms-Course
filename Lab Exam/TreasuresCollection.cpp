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
ll N , temp;
vector <ll> numbers;


//ll func(ll s, ll e , ll turn)         //start and end
//{
//    if (e == s+1)
//    {
//        return max(numbers[s] , numbers [e]);
//    }
//    if (turn) //friend
//    {
//        ll left = numbers[s] + func(s + 1, e , 0);
//        ll right = numbers[e] + func(s , e - 1 ,0 );
//
//        return max(left, right);
//    }
//    else if (!turn)
//    {
//        ll left = numbers[s] + func(s + 1, e, 1);
//        ll right = numbers[e] + func(s, e - 1, 1);
//
//        return max(left, right);
//    }
//    //return choose;
//}



//ll func(ll s, ll e, ll turn)         //start and end
//{
//    if (e == (s + 1))
//    {
//        return max(numbers[s], numbers[e]);
//    }
//    ll output = 0;
//    if (turn) //friend
//    {
//        ll left = numbers[s] + func(s + 1, e, 0);
//        ll right = numbers[e] + func(s, e - 1, 0);
//
//        output = max(left, right);
//    }
//    else if (!turn)
//    {
//        ll left = numbers[s] + func(s + 1, e, 1);
//        ll right = numbers[e] + func(s, e - 1, 1);
//
//        output = max(left, right);
//    }
//    return output;
//}



//ll func(ll s, ll e)         //start and end
//{
//    if (e == (s + 1))
//    {
//        return max(numbers[s], numbers[e]);
//    }
//    ll output = 0;
//    
//        ll left = numbers[s] + max (func(s + 2, e) , func(s+1, e-1))  ;
//        ll right = numbers[e] + max(func(s , e-2), func(s+1, e - 1));
//
//        output = max(left, right);
//    
//    return output;
//}

ll func(ll s, ll e)         //start and end
{
    if (e<s)
        return 0;
    if (e == s)
        return numbers[s];
    if (e == (s + 1))
        return max(numbers[s], numbers[e]);

    ll output = 0;

    ll leftnext = func(s + 1, e);
    ll rightnext = func(s, e - 1);

    ll next = min(leftnext, rightnext);
    ll left, right;
    if (leftnext >= rightnext)
    {
        left = numbers[s] + next + func(s + 2, e);
        right = numbers[e] + next + func(s + 1, e - 1);
    }
    else
    {
        left = numbers[s] + next + func(s + 1, e - 1);
        right = numbers[e] + next + func(s, e - 2);
    }
    
    output = max(left, right);

    return output;
}


int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        numbers.push_back(i);
    }
    /*int sum = 0;
    for (int i = 0; i < (N / 2); i++)
    {
        if (i%2 == 0)
        {
            sum += max(numbers[i], numbers[N -1- i]);
        }
        else
        {
            sum += min(numbers[i], numbers[N -1- i]);
        }
       
    }*/


   cout << func(0, N - 1);

    return 0;
}