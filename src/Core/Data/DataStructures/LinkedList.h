// #ifndef LINKED_LIST_CLASS_H
// #define LINKED_LIST_CLASS_H
//
// template <typename T>
// class LinkedList
// {
//     
// private:
//     typedef struct LinkedListNode
//     {
//         T* data;
//         LinkedListNode* next;
//
//         LinkedListNode()
//         {
//             this->data = nullptr;
//             this->next = nullptr;
//         }
//         
//         LinkedListNode(T* t_data)
//         {
//             this->data = t_data;
//             this->next = nullptr;
//         }
//     } LinkedListNode;
//     
//     LinkedListNode* m_head;
//
// public:
//
//     LinkedList() : m_head(nullptr) {}
//
//     void InsertNode(T* t_data);
//
//     void DeleteNode(int t_node_offset);
// };
//
// #endif
