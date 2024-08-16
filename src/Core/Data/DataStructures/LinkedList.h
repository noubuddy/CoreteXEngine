// #ifndef LINKED_LIST_CLASS_H
// #define LINKED_LIST_CLASS_H
//
// #include <cstdlib>
// #include <iostream>
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
//         LinkedListNode(T* data)
//         {
//             this->data = data;
//             this->next = nullptr;
//         }
//     } LinkedListNode;
//     
//     LinkedListNode* head;
//
// public:
//
//     LinkedList() : head(nullptr) {}
//
//     void InsertNode(T* data);
//
//     void DeleteNode(int NodeOffset);
// };
//
// #endif
