#pragma once

template<typename T>
class Sequence
{
public:

    /// получение значения
    virtual T operator[](int i) const = 0;

    /// присвоение значения
    virtual T &operator[](int i) = 0;

    /// получить длину строки
    [[nodiscard]]virtual int getLength() const = 0;

    /// Деструктор
    virtual ~Sequence() = default;

    virtual void isSorted() = 0;

    virtual void print() = 0;

};
