#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>
#include "ISorter.hpp"

using namespace std;
using namespace chrono;

template<class data, typename T>
void BenchArray(string sortName, ISorter<T, data> &instance, auto sortFunc, vector<T> &a, int n)
{
    string path = "D:\\python_mephi\\reversed_array\\";
    path.append(sortName.begin(), sortName.end());
    path.append("_abstract");
    path.append(".txt");
    ofstream file(path, ios_base::trunc);
    cout << "In progress " << sortName << "\n";
    for (int i = n / 100; i <= n; i += n / 100)
    {
        {
            vector<int> b(a.begin(), a.begin() + i);
            vectorSequence<int> vec(a);

            auto begin = steady_clock::now();
            sortFunc(instance, vec, 0, i - 1);
            auto end = steady_clock::now();
            auto time = duration_cast<microseconds>(end - begin);

            file << i << " " << time.count() / 1e3 << "\n";
        }
    }
    file.close();
}

template<class data, typename T>
void BenchList(string sortName, ISorter<T, data> &instance, auto sortFunc, vector<T> &a, int n)
{
    string path = "D:\\python_mephi\\reversed_array\\";
    path.append(sortName.begin(), sortName.end());
    path.append("_abstract");
    path.append(".txt");
    ofstream file(path, ios_base::trunc);
    cout << "In progress " << sortName << "\n";
    for (int i = n / 100; i <= n; i += n / 100)
    {
        {
            vector<int> b(a.begin(), a.begin() + i);
            Linked_List_Sequence<int> lst(b, b.size());

            auto begin = steady_clock::now();
            sortFunc(instance, lst, 0, i - 1);
            auto end = steady_clock::now();
            auto time = duration_cast<microseconds>(end - begin);
            cout << i << " elements\n";
            file << i << " " << time.count() / 1e3 << "\n";
        }
    }
    file.close();
}
//void Bench()
//{
//
//}
