#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

void Recorder(const vector<int>& arr, vector<int>& seq, int index,vector<int>& maxSeq ,int &m , int & maxSum)
{
	int sum = accumulate(seq.begin(), seq.end(), 0);
	int maxSeqSum = accumulate(maxSeq.begin(), maxSeq.end(), 0);
	if (maxSeqSum == m)
	{
		return;
	}
	if (index == arr.size())
	{
		
		
		if (seq.size() >= maxSeq.size() && sum <= m && sum > maxSeqSum)
		{
			maxSeq = seq;
			maxSum = sum;
		}
	}
	else
	{
		if (sum > m)
		{
			return;
		}

		Recorder(arr, seq, index + 1, maxSeq , m , maxSum); // exclude arr[index]
		seq.push_back(arr[index]); // include arr[index]
		Recorder(arr, seq, index + 1, maxSeq, m, maxSum);
		// undo the push_back of the seq.
		seq.pop_back();
	}
}


int main() 
{
    int m, s;
    cin >> m >> s;
	vector<int> songs(s);
    for (int i = 0; i < s; i++)
    {
        int a;
        cin >> a;
        songs.push_back(a);
    }
    vector<int> seq;
    vector<int> maxSeq;
	int maxSum = 0;
    Recorder(songs, seq, 0, maxSeq , m ,maxSum);
	cout << maxSum;

    return 0;
}