// #include "LinkedList.h"
//
// template <typename T>
// void LinkedList<T>::InsertNode(T* t_data)
// {
//     LinkedListNode* newNode = new LinkedListNode(t_data);
//
//     if (newNode == nullptr)
//     {
//         // TODO: add check
//     }
//
//     if (m_head == nullptr)
//     {
//         m_head = newNode;
//         return;
//     }
//
//     LinkedListNode* nodeIter = m_head;
//     while (nodeIter->next != nullptr)
//     {
//         nodeIter = nodeIter->next;
//     }
//
//     nodeIter->next = newNode;
// }
//
// template <typename T>
// void LinkedList<T>::DeleteNode(int t_node_offset)
// {
//     LinkedListNode* nodeTemp1 = m_head, *nodeTemp2 = nullptr;
//     int listLength = 0;
//
//     if (m_head == nullptr)
//     {
//         // TODO: add check
//         return;
//     }
//
//     while (nodeTemp1 != nullptr)
//     {
//         nodeTemp1 = nodeTemp1->next;
//         listLength++;
//     }
//
//     if (listLength < t_node_offset)
//     {
//         // TODO: add check
//         return;
//     }
//
//     nodeTemp1 = m_head;
//
//     if (t_node_offset-- > 1)
//     {
//         nodeTemp2 = nodeTemp1;
//         nodeTemp1 = nodeTemp1->next;
//     }
//
//     nodeTemp2->next = nodeTemp1->next;
//
//     delete nodeTemp1;
// }