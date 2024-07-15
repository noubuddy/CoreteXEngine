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
    for (int i = 0; i < table->m_size; i++)
    {
        if (hash_map_item* hm_item = table->m_items[i])
        {
            FreeItem(hm_item);
        }
    }

    free(table->m_items);
    free(table);
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
    free(item->key);
    free(item->value);
    free(item);
}

template <typename K, typename V>
bool HashMap<K, V>::Insert(K* key, V* value)
{
    hash_map_item* item = CreateItem(key, value);
    if (item == nullptr)
    {
        // TODO: add check
        return false;
    }

    int index = HashFunction(value);
    if (index >= this->m_size)
    {
        return false;
    }
    
    hash_map_item* current_item = this->m_items[index];
    if (current_item == nullptr)
    {
        return false;
    }

    if (current_item == NULL)
    {
        if (this->m_count == this->m_size)
        {
            FreeItem(item);
            return false;
        }
    }
    else
    {
        if (current_item->value == value)
        {
            memcpy(this->m_items[index]->value, value);
            return true;
        }
        else
        {
            HandleCollision(item);
            return true;
        }
    }

    this->m_items[index] = item;
    ++this->m_count;
}

template <typename K, typename V>
V* HashMap<K, V>::Search(K* key)
{
    int index = HashFunction(key);
    hash_map_item* item = this->m_items[index];

    if (item != nullptr)
    {
        if (item->key == key)
            return item->value;
    }

    return nullptr;
}

template <typename K, typename V>
int HashMap<K, V>::HashFunction(K* key)
{
    // TODO: finish hash function
    return 0;
}
