#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

void ReadInputArray(vector <string> &A)
{
	string filename = "words20K.txt";
	ifstream fin(filename);
	for (int i = 0; i < A.size(); i++)
	{
		string data;
		fin >> data;
		A[i] = data;
	}
	fin.close();

	return;
}


int hashFunction(string key)
{
    int hs = 0;
    if (key.size() == 1)
    {
        hs = 39 * int(key[0]);
    }
    else if (key.size() == 2) 
    {
        hs = 39 * int(key[0]) + 392 * int(key[1]);
    }
    else if (key.size() == 3)
    {
        hs = 39 * int(key[0]) + 392 * int(key[1]) + 393 * int(key[2]);
    }
    else
    {
        hs = 39 * int(key[0]) + 392 * int(key[1]) + 393 * int(key[2]) + 394 * int(key[3]);
    }
    int h = hs % 24000;
    return h;
}


void insert(vector<string>& H, string Key)
{
    int counter = 0;
    while (counter != H.size())
    {
        int prob = hashFunction(Key);
        counter++;
        if (H[prob] == "" || H[prob] == "-1")  // -1 maens deleted
        {
            H[prob] = Key;
            return;
        }
    }
    return;
}
void InsertAll(vector <string> &H , vector <string> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        insert(H , A[i]);
    } 
    return;
}


void Delete(vector<string> &H, string Key)
{
    int counter = 0;
    while (counter != H.size())
    {
        int prob = hashFunction(Key);
        counter++;
        if (H[prob] == Key)
        {
            H[prob] = "-1";
        }
    }
    return ;
}


void printAverageTime(vector <string> &H, vector <string> &A)
{
    for (int i = 0; i < 40; i++)
    {
        auto start = high_resolution_clock::now();
        for (int j = (i*500); j < (500+(i * 500)); j++)
        {
            insert(H, A[i]);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() / 500 << "micro seconds" << endl;
    }

    return;
}


void min_max_avg(vector<string>& A,int lim_1 , int Lim_2, int& min, int& max, float& avg )
{
    for (int i = lim_1; i < Lim_2; i++)
    {
        if (stoi(A[i]) < min)
        {
            min = stoi(A[i]);
        }
    }

    for (int i = lim_1; i < Lim_2; i++)
    {
        if (stoi(A[i]) > max)
        {
            max = stoi(A[i]);
        }
    }

    int sum = 0;
    for (int i = lim_1; i < Lim_2; i++)
    {
        sum = sum + stoi(A[i]);
    }
    avg = sum / (Lim_2 - lim_1);
}


int main()
{
	vector <string> A(20000);
	vector <string> H(24000 , "");

	ReadInputArray(A);

    /*for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }*/

    InsertAll(H, A);
    printAverageTime(H, A);
    int min, max;
    float avg;
    min_max_avg(A, 1400, 1499, min, max, avg);
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;
    cout << "avg = " << avg << endl;

	return 0;
}