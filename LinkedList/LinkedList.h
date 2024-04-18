//
// Created by F-Mir on 4/17/2024.
//

#ifndef LEETCODE_LINKED_LIST_H
#define LEETCODE_LINKED_LIST_H

#pragma once

#include <cstdint>
#include <vector>
#include <set>

namespace Leetcode
{

struct ListNode
{
    [[maybe_unused]] int val;
    ListNode* next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

size_t getListSizeFromHead(ListNode* head)
{
    std::set<ListNode*> allNodes;
    ListNode* currentNode = head;
    while (currentNode)
    {
        if (allNodes.find(currentNode) != allNodes.cend())
        {
            break;
        }
        allNodes.insert(currentNode);
        currentNode = currentNode->next;
    }
    return allNodes.size();
}

class List
{
public:
    explicit List(const std::vector<int>& numbers, int pos = -1)
            : size(numbers.size())
    {
        ListNode* prevNode;
        ListNode* nodeForLoop = nullptr;
        for (size_t index = 0; index < numbers.size(); ++index)
        {
            if (!head)
            {
                head = new ListNode(numbers[index]);
                prevNode = head;
            } else
            {
                prevNode->next = new ListNode(numbers[index]);
                prevNode = prevNode->next;
            }
            if (index == pos)
            {
                nodeForLoop = prevNode;
            }
        }
        if (nodeForLoop)
        {
            prevNode->next = nodeForLoop;
        }
    }

    explicit List(ListNode* newHead)
    : head(newHead)
    , size(getListSizeFromHead(head))
    {
    }

    List(const List& rhs) // NOLINT(*-pro-type-member-init)
    {
        copyListImpl(rhs.head);
    }

    List& operator=(const List& rhs)
    {
        if (this != &rhs)
        {
            clear();
            copyListImpl(rhs.head);
        }
        return *this;
    }

    List(List&& rhs) noexcept
    : head(rhs.head)
    , size(rhs.size)
    {
        if (this != &rhs)
        {
            rhs.head = nullptr;
            rhs.size = 0;
        }
    }

    List& operator=(List&& rhs) noexcept
    {
        if (this != &rhs)
        {
            head = rhs.head;
            size = rhs.size;
            rhs.head = nullptr;
            rhs.size = 0;
        }
        return *this;
    }

    void clear()
    {
        ListNode* nextNode = head;
        while (size != 0)
        {
            nextNode = nextNode->next;
            delete head;
            --size;
            head = nextNode;
        }
    }

    ~List()
    {
        clear();
    }

    ListNode* head = nullptr;
    friend bool operator==(const List& lhs, const List& rhs);
private:
    void copyListImpl(ListNode* rhs)
    {
        std::set<ListNode*> allNodes;
        ListNode* prevNode;
        ListNode* nodeForLoop = nullptr;
        while (rhs)
        {
            if (allNodes.find(rhs) != allNodes.cend())
            {
                nodeForLoop = prevNode;
                break;
            }
            if (!head)
            {
                head = new ListNode(rhs->val);
                prevNode = head;
            } else
            {
                prevNode->next = new ListNode(rhs->val);
                prevNode = prevNode->next;
            }
            allNodes.insert(rhs);
            rhs = rhs->next;
        }
        if (nodeForLoop)
        {
            prevNode->next = nodeForLoop;
        }
        size = allNodes.size();
    }

    size_t size;
};

bool operator==(const List& lhs, const List& rhs)
{
    if (lhs.size != rhs.size)
    {
        return false;
    }
    ListNode* lhsNode = lhs.head;
    ListNode* rhsNode = rhs.head;
    for (size_t i = 0; i < lhs.size; ++i)
    {
        if (lhsNode->val != rhsNode->val)
        {
            return false;
        }
        lhsNode = lhsNode->next;
        rhsNode = rhsNode->next;
    }
    return true;
}

} // Leetcode
#endif //LEETCODE_LINKED_LIST_H
