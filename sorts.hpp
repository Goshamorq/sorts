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
        throw out_of_range("Zadal hyinu");

}

template<class T>
void bubble_sort(vector<T> &vec, int left = 0, int right = -1)
{
    check_input(left, right, vec.size());

    for (int i = left; i < right; i++)
    {
        for (int j = right; j > i; j--)
        {
            if (vec[j] < vec[j - 1])
            {
                swap(vec[j], vec[j - 1]);
            }
        }
    }
}

template<class T>
void cocktail_sort(vector<T> &vec, int left = 0, int right = -1)
{
    check_input(left, right, vec.size());

    int last_swap;

    while (left < right)
    {
        last_swap = 0;

        for (int i = left; i < right; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                swap(vec[i], vec[i + 1]);
                last_swap = i;
            }
        }
        right = last_swap;

        for (int i = right; i > left; i--)
        {
            if (vec[i] < vec[i - 1])
            {
                swap(vec[i], vec[i - 1]);
                last_swap = i;
            }
        }
        left = last_swap;
    }
}

template<class T>
void insertion_sort(vector<T> &vec, int left = 0, int right = -1)
{
    check_input(left, right, vec.size());

    for (int i = left + 1; i <= right; i++)
    {
        auto it = upper_bound(vec.begin() + left, vec.begin() + i, vec[i]);
        for (int j = i; j > distance(vec.begin(), it); j--)
        {
            swap(vec[j], vec[j - 1]);
        }
    }
}

template<class T>
void count_sort(vector<T> &vec, int left = 0, int right = -1)
{
    check_input(left, right, vec.size());

    // нахождение интервала чисел
    int max = vec[0], min = vec[0];
    for (int i = left + 1; i <= right; i++)
    {
        if (vec[i] > max)
            max = vec[i];
        else if (vec[i] < min)
            min = vec[i];
    }

    vector<T> counts(max - min + 1, 0);

    for (int i: vec)
        counts[i - min]++;

    int cur_index = 0;
    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] != 0)
        {
            for (int j = 0; j < counts[i]; j++)
                vec[cur_index++] = i + min;
        }
    }
}

template<class T>
void quick_sort(vector<T> &vec, int first = 0, int last = -1)
{
    check_input(first, last, vec.size());

    int f = first, l = last;
    int mid = vec[(f + l) / 2];
    do
    {
        while (vec[f] < mid) f++;
        while (vec[l] > mid) l--;
        if (f <= l)
        {
            swap(vec[f], vec[l]);
            l--;
            f++;
        }
    } while (f < l);

    if (first < l) quick_sort(vec, first, l);
    if (f < last) quick_sort(vec, f, last);
}

template<class T>
void Bench(vector<T> &a, int n)
{
    BenchSortFunc("Bubble Sort", bubble_sort, a, n);
    BenchSortFunc("Insertion Sort", insertion_sort, a, n);
    BenchSortFunc("Cocktail Sort", cocktail_sort, a, n);
    BenchSortFunc("Quick Sort", quick_sort, a, n);
    BenchSortFunc("Count Sort", count_sort, a, n);
}
