#include <sorts.h>


template<class T>
void check_input(int &left, int &right, unsigned int size)
{
    if (right == -1)
        right = size - 1;
    if (left < 0 || left > right || right >= size)
        throw out_of_range("Zadal hyinu");

}

template<class T>
void bubble_sort(vector<T> &vec, int left, int right)
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
void cocktail_sort(vector<T> &vec, int left, int right)
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
void insertion_sort(vector<T> &vec, int left, int right)
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
void count_sort(vector<T> &vec, int left, int right)
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
void quick_sort(vector<T> &vec, int first, int last)
{
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

