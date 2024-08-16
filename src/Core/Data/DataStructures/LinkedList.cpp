// #include "LinkedList.h"
//
// template <typename T>
// void LinkedList<T>::InsertNode(T* data)
// {
//     LinkedListNode* new_node = new LinkedListNode(data);
//
//     if (new_node == nullptr)
//     {
//         // TODO: add check
//     }
//
//     if (head == nullptr)
//     {
//         head = new_node;
//         return;
//     }
//
//     LinkedListNode* node_iter = head;
//     while (node_iter->next != nullptr)
//     {
//         node_iter = node_iter->next;
//     }
//
//     node_iter->next = new_node;
// }
//
// template <typename T>
// void LinkedList<T>::DeleteNode(int NodeOffset)
// {
//     LinkedListNode* node_temp1 = head, *node_temp2 = nullptr;
//     int list_length = 0;
//
//     if (head == nullptr)
//     {
//         // TODO: add check
//         return;
//     }
//
//     while (node_temp1 != nullptr)
//     {
//         node_temp1 = node_temp1->next;
//         list_length++;
//     }
//
//     if (list_length < NodeOffset)
//     {
//         // TODO: add check
//         return;
//     }
//
//     node_temp1 = head;
//
//     if (NodeOffset-- > 1)
//     {
//         node_temp2 = node_temp1;
//         node_temp1 = node_temp1->next;
//     }
//
//     node_temp2->next = node_temp1->next;
//
//     delete node_temp1;
// }