#pragma once
#include <random>
#include "sorts.hpp"

class ArrayGenerator
{
public:
    int n;

    explicit ArrayGenerator(int n) : n(n)
    {};

    [[nodiscard]] vector<int> GenerateRandomArray() const
    {
        random_device rd;
        mt19937 mersenne(rd());

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = int(mersenne());
            if (a[i] % 2 == 0)
                a[i] = -a[i];
        }

        return a;
    }

    [[nodiscard]] vector<int> GenerateArrayForCount() const
    {
        random_device rd;
        mt19937 mersenne(rd());

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = int(mersenne()%100000);
            if (a[i] % 2 == 0)
                a[i] = -a[i];
        }

        return a;
    }

    [[nodiscard]] vector<int> GenerateSortedArray() const
    {
        random_device rd;
        mt19937 mersenne(rd());

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = int(mersenne());
            if (a[i] % 2 == 0)
                a[i] = -a[i];
        }

        sort(a.begin(), a.end());
        return a;
    }
};
