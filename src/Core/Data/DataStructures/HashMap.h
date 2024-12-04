#ifndef HASH_MAP_CLASS_H
#define HASH_MAP_CLASS_H

// K - key, V - value
template <typename K, typename V>
class HashMap
{
public:

    typedef struct HashMapItem
    {
        K* key;
        V* value;
    } HashMapItem;
    
    HashMap(int t_size);

    HashMap* CreateTable(int t_size);
    void FreeTable(HashMap* t_table);

    HashMapItem* CreateItem(K* t_key, V* t_value);
    void FreeItem(HashMapItem* t_item);

    bool Insert(K* t_key, V* t_value);
    V* Search(K* t_key);

private:

    int HashFunction(K* t_key);
    void HandleCollision(HashMapItem* t_item);

    // array of pointers to item
    HashMapItem** m_items;
    // size of the hash table
    int m_size;
    // number of elements
    int m_count;
    
};

#endif
