#include "HashMap.h"

#include <cstdlib>
#include <cstring>

template <typename K, typename V>
HashMap<K, V>::HashMap(int t_size)
{
    CreateTable(t_size);
}

template <typename K, typename V>
HashMap<K, V>* HashMap<K, V>::CreateTable(int t_size)
{
    this->m_size = t_size;
    m_count = 0;
    m_items = (HashMapItem**) calloc(m_size, sizeof(HashMapItem*));
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
void HashMap<K, V>::FreeTable(HashMap* t_table)
{
    for (int i = 0; i < t_table->m_size; i++)
    {
        if (HashMapItem* hm_item = t_table->m_items[i])
        {
            FreeItem(hm_item);
        }
    }

    free(t_table->m_items);
    free(t_table);
}

template <typename K, typename V>
typename HashMap<K, V>::HashMapItem* HashMap<K, V>::CreateItem(K* t_key, V* t_value)
{
    HashMapItem* item = (HashMapItem*) malloc(sizeof(HashMapItem));
    if (item == nullptr)
    {
        // TODO: add check
    }

    item->key = (K*) malloc(sizeof(t_key));
    item->value = (V*) malloc(sizeof(t_value));
    if (!t_key || !t_value)
    {
        // TODO: add check
    }

    memcpy(item->key, t_key, sizeof(t_key));
    memcpy(item->value, t_value, sizeof(t_value));
    
    return item;
}

template <typename K, typename V>
void HashMap<K, V>::FreeItem(HashMapItem* t_item)
{
    free(t_item->key);
    free(t_item->value);
    free(t_item);
}

template <typename K, typename V>
bool HashMap<K, V>::Insert(K* t_key, V* t_value)
{
    HashMapItem* item = CreateItem(t_key, t_value);
    if (item == nullptr)
    {
        // TODO: add check
        return false;
    }

    int index = HashFunction(t_value);
    if (index >= this->m_size)
    {
        return false;
    }
    
    HashMapItem* currentItem = this->m_items[index];
    if (currentItem == nullptr)
    {
        return false;
    }

    if (currentItem == NULL)
    {
        if (this->m_count == this->m_size)
        {
            FreeItem(item);
            return false;
        }
    }
    else
    {
        if (currentItem->value == t_value)
        {
            memcpy(this->m_items[index]->value, t_value);
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
V* HashMap<K, V>::Search(K* t_key)
{
    int index = HashFunction(t_key);
    HashMapItem* item = this->m_items[index];

    if (item != nullptr)
    {
        if (item->key == t_key)
            return item->value;
    }

    return nullptr;
}

template <typename K, typename V>
int HashMap<K, V>::HashFunction(K* t_key)
{
    // TODO: finish hash function
    return 0;
}
