#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

void BenchSortFunc(string sortName, void (*sortFunc)(vector<int> &, int, int), vector<int> &a, int n)
{
    string path = "D:\\python_mephi";
    path.append(sortName.begin(), sortName.end());
    path.append(".txt");
    ofstream file(path, ios_base::trunc);

    for (int i = n / 100; i <= n; i += n / 100)
    {
        vector<int> b(a.begin(), a.begin() + i);
        auto begin = steady_clock::now();
        sortFunc(b, 0, i - 1);
        auto end = steady_clock::now();
        auto time = duration_cast<microseconds>(end - begin);

        for (int j = 0; j < i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                cout << sortName << " Error\n";
                file.close();
                return;
            }
        }

        file << i << " " << time.count() / 1e3 << "\n";
    }
    file.close();
}


template<class T>
void TestSortFunc(string sortName, void (*sortFunc)(vector<T> &, int, int), vector<T> &a, int l, int r)
{
    vector<T> b = a;
    auto begin = steady_clock::now();
    sortFunc(b, l, r);
    auto end = steady_clock::now();
    auto time = duration_cast<microseconds>(end - begin);
    for (int i = l; i < r; i++)
    {
        if (b[i] > b[i + 1])
        {
            cout << sortName << " Error";
            return;
        }
    }
    cout << sortName << "\n--- " << time.count() / 1e3 << " microseconds ---\n";
}

inline void check_input(int &left, int &right, int size)
{
    if (right == -1)
        right = size - 1;
    if (left < 0 || left > right || right >= size)
        throw out_of_range("Error with start conditions.\n");

}
