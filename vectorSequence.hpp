#pragma once

#include <vector>

template<typename T>
class vectorSequence : Sequence<T>
{
public:
    std::vector<T> vec;

    explicit vectorSequence(const std::vector<T> &a) : vec(a)
    {};

    /// присвоение значения
    T &operator[](int i) override
    {
        return vec[i];
    }

    /// получение значения
    T operator[](int i) const override
    {
        return vec[i];
    }

    [[nodiscard]] int getLength() const override
    {
        return vec.size();
    }

    void print()
    {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << ' ';
    }

    void isSorted() override
    {
        if (std::is_sorted(vec.begin(), vec.end()))
        {
            cout << "Everything is OK!\n";
        }
        else
            cout << "GG\n";
    }
};