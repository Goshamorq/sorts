#pragma once

#include "sorts.hpp"

template<typename T, class data>
concept is_sortable =
requires(data &seq){
    seq.getLength();
    swappable<data>;
    equality_comparable<T>;
};

//компараторы
template<typename T>
bool Less(const T &a, const T &b)
{ return a < b; }

template<class T>
bool Greater(const T &a, const T &b)
{ return a > b; }

template<typename T, class data>
requires is_sortable<T, data>
class ISorter
{
public:
    void bubble_sort(data &vec, int left = 0, int right = -1,
                     bool (*cmp)(const T &, const T &) = [](const T &a, const T &b)
                     { return a < b; })
    {
        check_input(left, right, vec.getLength());

        for (int i = left; i < right; i++)
        {
            for (int j = right; j > i; j--)
            {
                if (cmp(vec[j], vec[j - 1]))
                {
                    swap(vec[j], vec[j - 1]);
                }
            }
        }
    };

    void cocktail_sort(data &vec, int left = 0, int right = -1,
                       bool (*cmp)(const T &, const T &) = [](const T &a, const T &b)
                       { return a < b; })
    {
        check_input(left, right, vec.getLength());

        int last_swap;

        while (left < right)
        {
            last_swap = 0;

            for (int i = left; i < right; i++)
            {
                if (!cmp(vec[i], vec[i + 1]))
                {
                    swap(vec[i], vec[i + 1]);
                    last_swap = i;
                }
            }
            right = last_swap;

            for (int i = right; i > left; i--)
            {
                if (cmp(vec[i], vec[i - 1]))
                {
                    swap(vec[i], vec[i - 1]);
                    last_swap = i;
                }
            }
            left = last_swap;
        }
    };

    void insertion_sort(data &vec, int left = 0, int right = -1,
                        bool (*cmp)(const T &, const T &) = [](const T &a, const T &b)
                        { return a < b; })
    {
        check_input(left, right, vec.getLength());

        for (int i = left + 1; i <= right; i++)
        {
            int l = left, r = i - 1, middle = (l + r) / 2;
            while (l < r)
            {
                if (!cmp(vec[middle], vec[i]) || vec[middle] >= vec[i])
                {
                    if (vec[middle] == vec[i])
                        break;
                    r = middle;
                } else
                    l = middle + 1;
                middle = (l + r) / 2;
            }
            // 1 3 4 4 4 5  |7
            while (cmp(vec[middle], vec[i]))
                middle++;

            for (int j = i; j > middle; j--)
            {
                swap(vec[j], vec[j - 1]);
            }
        }
    };

    void count_sort(data &vec, int left = 0, int right = -1,
                    bool (*cmp)(const T &, const T &) = [](const T &a, const T &b)
                    { return a < b; })
    {
        check_input(left, right, vec.getLength());

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

//        for (int i: vec)
//            counts[i - min]++;
        for (int i = 0; i < vec.getLength(); i++)
        {
            counts[vec[i] - min]++;
        }

        int cur_index = 0;
        if (cmp(1, 2))
        {
            for (int i = 0; i < counts.size(); i++)
            {
                if (counts[i] != 0)
                {
                    for (int j = 0; j < counts[i]; j++)
                        vec[cur_index++] = i + min;
                }
            }
        } else
        {
            for (int i = counts.size() - 1; i > -1; i--)
            {
                if (counts[i] != 0)
                {
                    for (int j = 0; j < counts[i]; j++)
                        vec[cur_index++] = i + min;
                }
            }
        }
    };

    void quick_sort(data &vec, int first = 0, int last = -1,
                    bool (*cmp)(const T &, const T &) = [](const T &a, const T &b)
                    { return a < b; })
    {
        check_input(first, last, vec.getLength());

        int f = first, l = last;
        int mid = vec[(f + l) / 2];
        do
        {
            while (cmp(vec[f], mid) && vec[f] != mid) f++;
            while (!cmp(vec[l], mid) && vec[l] != mid) l--;
            if (f <= l)
            {
                swap(vec[f], vec[l]);
                l--;
                f++;
            }
        } while (f < l);

        if (first < l) quick_sort(vec, first, l, cmp);
        if (f < last) quick_sort(vec, f, last, cmp);
    };

};