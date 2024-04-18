//
// Created by F-Mir on 4/17/2024.
//

#include "../LinkedList/LinkedList.h"
#include <cassert>

using namespace Leetcode;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static ListNode* reverseList(ListNode* head) {
        if (!head)
        {
            return head;
        }
        ListNode* prevNode = nullptr;
        ListNode* currentNode = head;
        while (ListNode* nextNode = currentNode->next)
        {
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        currentNode->next = prevNode;
        return currentNode;
    }
};

int main()
{
    {
        List firstInputList(std::vector{1, 2, 3, 4, 5});
        List reversedList = firstInputList;
        reversedList = List(Solution::reverseList(reversedList.head));
        assert(reversedList == List(std::vector{5, 4, 3, 2, 1}));
    }
    {
        List firstInputList(std::vector{1, 2});
        List reversedList = firstInputList;
        reversedList = List(Solution::reverseList(reversedList.head));
        assert(reversedList == List(std::vector{2, 1}));
    }
    {
        List firstInputList(std::vector<int>{});
        List reversedList = firstInputList;
        reversedList = List(Solution::reverseList(reversedList.head));
        assert(reversedList == List(std::vector<int>{}));
    }
    return 0;
}