#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

using namespace chrono;

template<class T>
void check_input(int &left, int &right, unsigned int size);

template<class T>
void bubble_sort(vector<T> &vec, int left = 0, int right = -1);

template<class T>
void cocktail_sort(vector<T> &vec, int left = 0, int right = -1);

template<class T>
void insertion_sort(vector<T> &vec, int left = 0, int right = -1);

template<class T>
void count_sort(vector<T> &vec, int left = 0, int right = -1);

template<class T>
void quick_sort(vector<T> &vec, int left = 0, int right = -1);

template<class T>
void TestSortFunc(string sortName, void (*sortFunc)(vector<T> &, int, int), vector<T> &a, int l, int r);

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
