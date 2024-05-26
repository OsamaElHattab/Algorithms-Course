
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <climits>
using namespace std;

void GridJumps(int** mat, bool** isused,int n, int i, int j,
    int& maxSum, int currSum)
{
    isused[i][j] = true;
    currSum += mat[i][j];

    if (i == 2 && j == 0)
    {
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
    }
    else
    {
        if (i - 1 >= 0 && !isused[i - 1][j])     //up
            GridJumps(mat, isused,n, i - 1, j, maxSum, currSum);
        if (i - 1 >= 0 && j - 1 >= 0 && !isused[i - 1][j - 1]) //up left
            GridJumps(mat, isused,n, i - 1, j - 1, maxSum, currSum);
        if (i - 1 >= 0 && j + 1 < 3 && !isused[i - 1][j + 1])  //up right
            GridJumps(mat, isused,n, i - 1, j + 1, maxSum, currSum);
        if (i + 1 < 3 && !isused[i + 1][j])  //down
            GridJumps(mat, isused,n, i + 1, j, maxSum, currSum);
        if (i + 1 < 3 && j - 1 >= 0 && !isused[i + 1][j - 1])  //down left
            GridJumps(mat, isused,n, i + 1, j - 1, maxSum, currSum);
        if (i + 1 < 3 && j + 1 < 3 && !isused[i + 1][j + 1])   //down right
            GridJumps(mat, isused,n, i + 1, j + 1, maxSum, currSum);
        isused[i][j] = false;
        currSum -= mat[i][j];
    }
}

int main()
{
    int** mat = new int* [3];
    mat[0] = new int[3] ;
    mat[1] = new int[3] ;
    mat[2] = new int[3] ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            cin >> mat[i][j];
        }
    }

    bool** visited = new bool* [3];
    for (int i = 0; i < 3; i++)
    {
        visited[i] = new bool[3] {};
    }

    int maxCoins = INT_MIN;
    int currSum = 0;
    GridJumps(mat, visited,3 , 0, 0, maxCoins, currSum);
    cout << maxCoins << endl;
    return 0;
}
