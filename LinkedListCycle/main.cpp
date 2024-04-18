//
// Created by F-Mir on 4/15/2024.
//
//Definition for singly-linked list.

#include <set>
#include <vector>
#include <iostream>
#include "../LinkedList/LinkedList.h"

using namespace Leetcode;

class Solution
{
public:
    static bool hasCycle(ListNode* head)
    {
        ListNode* slow;
        ListNode* fast;
        slow = fast = head;
        while (slow and fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    static bool hasCycleSlow(ListNode* head)
    {
        std::set<ListNode*> allNodes;
        ListNode* currentNode = head;
        while (currentNode)
        {
            if (allNodes.find(currentNode) != allNodes.cend())
            {
                return true;
            }
            allNodes.insert(currentNode);
            currentNode = currentNode->next;
        }
        return false;
    }
};

int main()
{
    {
        List list(std::vector{3, 2, 0, -4}, 1);
        std::cout << std::boolalpha << "Solution::hasCycle for {3, 2, 0, -4} and pos = 1: "
                  << Solution::hasCycle(list.head) << std::endl;
        std::cout << std::boolalpha << "Solution::hasCycle (slow solution) for {3, 2, 0, -4} and pos = 1: "
                  << Solution::hasCycleSlow(list.head) << std::endl;
    }
    {
        List list(std::vector{1, 2}, 0);
        std::cout << std::boolalpha << "Solution::hasCycle for {1, 2} and pos = 0: "
                  << Solution::hasCycle(list.head) << std::endl;
        std::cout << std::boolalpha << "Solution::hasCycle (slow solution) for {1, 2} and pos = 0: "
                  << Solution::hasCycleSlow(list.head) << std::endl;
    }
    {
        List list(std::vector{1});
        std::cout << std::boolalpha << "Solution::hasCycle for {1} and pos = -1: "
                  << Solution::hasCycle(list.head) << std::endl;
        std::cout << std::boolalpha << "Solution::hasCycle (slow solution) for {1} and pos = -1: "
                  << Solution::hasCycleSlow(list.head) << std::endl;
    }
    return 0;
}