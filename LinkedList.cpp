//
// Created by trykr on 21.04.2023.
//

#include "LinkedList.h"
#include <map>
#include <stack>
#include <queue>

void ListRand::Serialize(std::fstream& s)
{
    std::multimap<ListNode*, int> map;
    int i = 0;
    for (ListNode* currentNode = Head; currentNode != nullptr; currentNode = currentNode->Next)
    {
        map.insert(std::make_pair(currentNode, i));
        ++i;
    }

    for (ListNode* currentNode = Head; currentNode != nullptr; currentNode = currentNode->Next)
    {
        s << currentNode->Data << ' ';
        s << map.find(currentNode->Rand).operator*().second << "\n";
    }
}

void ListRand::Deserialize(std::fstream& s)
{
    std::multimap<int, ListNode*> map;
    Head = new ListNode;

    std::queue<int> queue;
    ListNode* currentNode = Head;
    currentNode->Prev = nullptr;
    int number;
    std::string curString;
    int i = 0;
    while(!s.eof())
    {
        map.insert(std::make_pair(i, currentNode));
        s >> currentNode->Data;
        s >> curString;

        number = std::stoi(curString);
        queue.push(number);

        if (s.eof())
        {
            currentNode->Next = nullptr;
            Tail = currentNode;
        }
        else
        {
            currentNode->Next  = new ListNode;
            currentNode->Next->Prev = currentNode;
            currentNode = currentNode->Next;
        }
        ++i;
    }
    Count = i + 1;

    for (currentNode = Head; currentNode != nullptr; currentNode = currentNode->Next)
    {
        currentNode->Rand = map.find(queue.front()).operator*().second;
        queue.pop();
    }

}
