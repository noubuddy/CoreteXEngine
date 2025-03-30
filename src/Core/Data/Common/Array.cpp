#include "Array.h"

template <typename Type>
HArray<Type>::HArray()
{
    m_array = std::vector<Type>(0);
}

template <typename Type>
HArray<Type>::HArray(size_t t_size)
{
    m_array = std::vector<Type>(t_size);
}

template <typename Type>
void HArray<Type>::Add(Type& t_element)
{
    m_array.push_back(t_element);
}

template <typename Type>
void SArray<Type>::Set(Type& t_element, unsigned int t_index)
{
    m_array[t_index] = t_element;
}
