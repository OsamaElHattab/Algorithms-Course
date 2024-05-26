#include<iostream>
#include<stdio.h>
#include <sstream>
#include <cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
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
#include<unordered_map>
#include <stdio.h>  
#include <string.h> 
#include <math.h>
using namespace std;

long long B, V;
vector <long long> dp(10050, -1);

int func(vector <long long>& numbers, long long remainder)
{
    if (dp[remainder] < 0)
    {
        if (remainder == 0)
        {
            dp[remainder] = 0;
        }
        else
        {
            int choice2 = 10050;
            int rem = 10050;
            for (int i = 0; i < numbers.size(); i++)
            {
                if (remainder - numbers[i] >= 0)
                {
                    choice2 = 1 + func(numbers, remainder - numbers[i]);
                }
                else
                {
                    choice2 = 10050;
                }
                dp[remainder] = min(rem, choice2);
                rem = dp[remainder];
            }
        }
    }
    return dp[remainder];
}

int main()
{
    int V, B;
    cin >> V >> B;

    vector <long long> numbers(B, 0);
    for (int j = 0; j < B; j++)
    {
        cin >> numbers[j];
    }

    int final = func(numbers, V);
    if (final <= 10000)
    {
        cout << final << endl;
    }
    else
        cout << "no solution" << endl;

    return 0;
}