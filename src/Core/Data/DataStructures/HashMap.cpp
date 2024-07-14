#include "HashMap.h"

#include <cstdlib>
#include <cstring>

template <typename K, typename V>
HashMap<K, V>::HashMap(int size)
{
    CreateTable(size);
}

template <typename K, typename V>
HashMap<K, V>* HashMap<K, V>::CreateTable(int size)
{
    this->m_size = size;
    m_count = 0;
    m_items = (hash_map_item**) calloc(m_size, sizeof(hash_map_item*));
    if (m_items == nullptr)
    {
        // TODO: add check
    }

    for (int i = 0; i < m_size; i++)
    {
        m_items[i] = NULL;
    }

    return this;
}

template <typename K, typename V>
void HashMap<K, V>::FreeTable(HashMap* table)
{
    
}

template <typename K, typename V>
typename HashMap<K, V>::hash_map_item* HashMap<K, V>::CreateItem(K* key, V* value)
{
    hash_map_item* item = (hash_map_item*) malloc(sizeof(hash_map_item));
    if (item == nullptr)
    {
        // TODO: add check
    }

    item->key = (K*) malloc(sizeof(key));
    item->value = (V*) malloc(sizeof(value));
    if (!key || !value)
    {
        // TODO: add check
    }

    memcpy(item->key, key, sizeof(key));
    memcpy(item->value, value, sizeof(value));
    
    return item;
}

template <typename K, typename V>
void HashMap<K, V>::FreeItem(hash_map_item* item)
{
    
}
