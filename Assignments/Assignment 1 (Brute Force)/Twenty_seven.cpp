#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool possible = 0;

void TwentySeven( vector <int>& numbers , int result ,int index)
{
    if (!possible)
    {
        if (index == 5)
        {
            if (result == 27)
                possible = 1;
        }
        else
        {
            TwentySeven(numbers, (result + numbers[index]), index + 1);
            TwentySeven(numbers, (result - numbers[index]), index + 1);
            TwentySeven(numbers, (result * numbers[index]), index + 1);
        }
    }
}

int main() 
{
    vector<int> numbers;
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    sort(numbers.begin(), numbers.end());

    do {
        TwentySeven(numbers, numbers[0], 1);
    } while (next_permutation(numbers.begin(), numbers.end()) && !possible);

    if (possible)
    {
        cout << "Possible";
    }
    else
    {
        cout << "Impossible";
    }

    return 0;
}