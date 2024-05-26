#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;


void zeroSumCells(int** arr, int i, int j, int n, int m,
    vector<int>& current, vector<int>& maxPath, int& maxCells, long long index)
{

    int elements;
    if (m == 0)
        elements = n;
    else if (n == 0)
        elements = m;
    else
        elements = m * n;

    int sum = accumulate(current.begin(), current.end(), 0);
    if (index == elements && sum == 0)
    {
        if (maxPath.size() < current.size())
        {
            maxPath = current;
            maxCells = maxPath.size();
        }
    }
    else
    {
        j++;
        if (j == m)
        {
            j = 0;
            i++;
            if (i == n)
                return;
        }

        zeroSumCells(arr, i, j, n, m, current, maxPath, maxCells, index + 1);
        //duplicate element
        for (int k = 0; k < current.size(); k++)
        {
            if (current[k] == arr[i][j])
                return;
        }
        current.push_back(arr[i][j]);
        zeroSumCells(arr, i, j, n, m, current, maxPath, maxCells, index + 1);
        current.pop_back();
    }

}


int main() {

    int N, M;
    cin >> N >> M;

    if (N == 0 || M == 0)
    {
        cout << 0;
    }
    else
    {
        int** arr = new int* [N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new int[M];
            for (int j = 0; j < M; j++)
            {
                cin >> arr[i][j];
            }
        }
        vector<int> current;
        vector<int> maxPath;
        vector<int> isUsed;
        int currentCells = 0;
        int maxCells = 0;

        //if (N==0 && M ==0)
        zeroSumCells(arr, 0, -1, N, M, current, maxPath, maxCells, 0);
        cout << maxCells;
        delete[] arr;
    }



    return 0;
}
