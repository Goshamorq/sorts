#pragma once
#include <random>
#include "sorts.hpp"

struct ArrayGenerator
{
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
            a[i] = int(mersenne())%1000000;
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

    [[nodiscard]] vector<int> GenerateRealArray() const
    {
        vector<int> a = GenerateRandomArray();
        for (int i = 0; i < n; i++)
        {
            int k = min(i + (rand() % n) / 10, n);
            sort(a.begin() + i, a.begin() + k);
            if (k % 2 == 0)
                reverse(a.begin() + i, a.begin() + k);
            i += k - 1 + rand() % k;
        }

        return a;
    }
};
