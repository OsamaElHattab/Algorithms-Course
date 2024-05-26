#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void chairs(vector<string> &people,const int &number, int & ways ,int index , vector<bool>& isused , vector<string>& seq)
{
    if (index == number)
    {
        ways++;
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            if (isused[i] == 0)
            {
                seq.push_back(people[i]);
				if (index == 0)
				{
					isused[i] = 1;
					chairs(people, number, ways, index + 1, isused , seq);
					isused[i] = 0;
				}
				else if (seq[index -1].back() != (seq[index])[0])
				{
					isused[i] = 1;
					chairs(people, number, ways, index + 1, isused , seq);
					isused[i] = 0;
				}
                seq.pop_back();
            }
        }
    }
}

int main() 
{
    
    int number;
    cin >> number;
    vector<string> people(number);
    for (int i = 0; i < number; i++)
    {
        string a;
        cin >> a;
        people[i] = a;
    }
    int ways = 0;
    vector<bool> isused(number, 0);
    vector<string> seq ;
    chairs(people, number, ways, 0, isused, seq);
    cout << ways;


    return 0;
}