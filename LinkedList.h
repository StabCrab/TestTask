//
// Created by trykr on 21.04.2023.
//

#ifndef TEST_LINKEDLIST_H
#define TEST_LINKEDLIST_H

#include <fstream>

#include <string>
class ListNode
{
public:
    ListNode* Prev;
    ListNode* Next;
    ListNode* Rand; // произвольный элемент внутри списка
    std::string Data;
};


class ListRand
{
public:
    ListNode* Head;
    ListNode* Tail;
    int Count;

public:
    void Serialize(std::fstream& s);

    void Deserialize(std::fstream& s);
};

#endif //TEST_LINKEDLIST_H
