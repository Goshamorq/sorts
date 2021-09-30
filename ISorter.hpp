#pragma once

#include "sorts.hpp"

template<typename T, class data>
concept is_sortable =
requires(data &seq){
    seq.getLength();
    swappable<data>;
    equality_comparable<T>;
};

template<typename T, class data>
requires is_sortable<T, data>
class ISorter
{
public:
    void bubble_sort(data &vec, int left = 0, int right = -1)
    {
        check_input(left, right, vec.getLength());

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
    };

    void cocktail_sort(data &vec, int left = 0, int right = -1)
    {
        check_input(left, right, vec.getLength());

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
    };

    void insertion_sort(data &vec, int left = 0, int right = -1)
    {
        check_input(left, right, vec.getLength());

        for (int i = left + 1; i <= right; i++)
        {
            int l = left, r = i - 1, middle = (l + r) / 2;
            while (l < r)
            {
                if (vec[middle] >= vec[i])
                {
                    if (vec[middle] == vec[i])
                        break;
                    r = middle;
                } else
                    l = middle + 1;
                middle = (l + r) / 2;
            }
            // 1 3 4 4 4 5  |7
            while(vec[middle] < vec[i])
                middle++;

            for (int j = i; j > middle; j--)
            {
                swap(vec[j], vec[j - 1]);
            }
        }
    };

    void count_sort(data &vec, int left = 0, int right = -1)
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
            counts[vec[i]-min]++;
        }

        int cur_index = 0;
        for (int i = 0; i < counts.size(); i++)
        {
            if (counts[i] != 0)
            {
                for (int j = 0; j < counts[i]; j++)
                    vec[cur_index++] = i + min;
            }
        }
    };

    void quick_sort(data &vec, int first = 0, int last = -1)
    {
        check_input(first, last, vec.getLength());

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
    };

};