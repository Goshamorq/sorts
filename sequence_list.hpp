#pragma once

#include "linked_list.hpp"
#include "sequence.hpp"

template<class T>
class Linked_List_Sequence : public Sequence<T>
{
    List<T> data;

public:
    /// Копирование элементов из переданного массива
    Linked_List_Sequence(T *items, int count) : data(items, count)
    {}

    Linked_List_Sequence(vector<T> &items, int count) : data(items, count)
    {}

    /// Создание пустого связного списка
    Linked_List_Sequence() : data()
    {};

    /// Копирующий конструктор
    explicit Linked_List_Sequence(const List<T> &list) : data(new List<T>(list))
    {};

    T operator[](int i) const override
    {
        return data[i];
    }

    T &operator[](int i) override
    {
        return data[i];
    }

    [[nodiscard]]int getLength() const override
    {
        return data.getLength();
    }

    void print() override
    {
        data.print();
    }

    void isSorted() override
    {
        data.isSorted();
    }

    virtual ~Linked_List_Sequence() = default;
};
