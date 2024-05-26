#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int main()
{
    int N, D, M, pages, collections = 0;
    cin >> N >> D >> M;
    unordered_map <int, int> books, books2;
    for (int i = 0; i < N; i++)
    {
        cin >> pages;
        if (books.find(pages) == books.end())  // not exist
            books.insert({ pages,1 });
        else                                   // exist
            books[pages] += 1;


        if (books.find(pages - D) == books.end())  // -D not exist
            continue;
        // -D exist
        if (M == 2)
        {
            collections += books[pages - D];
            continue;
        }


        if (books2.find(pages) == books2.end())  // not exist
            books2.insert({ pages,books[pages - D] });
        else                                     // exist
            books2[pages] += books[pages - D];

        if (books2.find(pages-D) == books2.end())  // not exist
            continue;
        else                                     // exist
            collections += books2[pages - D];
    }

    cout << collections;

    return 0;
}