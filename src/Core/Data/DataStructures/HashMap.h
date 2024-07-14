#ifndef HASH_MAP_CLASS_H
#define HASH_MAP_CLASS_H

// K - key, V - value
template <typename K, typename V>
class HashMap
{
public:

    typedef struct hash_map_item
    {
        K* key;
        V* value;
    } hash_map_item;
    
    HashMap(int size);

    HashMap* CreateTable(int size);
    void FreeTable(HashMap* table);

    hash_map_item* CreateItem(K* key, V* value);
    void FreeItem(hash_map_item* item);

private:

    // array of pointers to item
    hash_map_item** m_items;
    // size of the hash table
    int m_size;
    // number of elements
    int m_count;
    
};

#endif
