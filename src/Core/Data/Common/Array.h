#ifndef ARRAY_CLASS_H
#define ARRAY_CLASS_H

#define CORTEX_MINIMAL_ARRAY_SIZE 0
#define CORTEX_DEFAULT_STACK_ARRAY_SIZE 4294967295

#include "vector"
#include "array"

template <typename Type>
class HArray // std::vector (heap)
{
private:

    // size_t m_size;
    // size_t m_capacity;
    // Type* m_data;

    std::vector<Type> m_array;
    
public:

    HArray();
    HArray(size_t t_size);

    void Add(Type& t_element);
};


template <typename Type>
class SArray // std::array (stack)
{
private:

    std::array<Type, CORTEX_DEFAULT_STACK_ARRAY_SIZE> m_array;

    void Set(Type& t_element, unsigned int t_index);
    
public:

    
};


#endif