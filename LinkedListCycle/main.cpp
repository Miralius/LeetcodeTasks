//
// Created by F-Mir on 4/15/2024.
//
//Definition for singly-linked list.

#include <set>
#include <vector>
#include <iostream>

struct ListNode
{
    [[maybe_unused]] int val;
    ListNode* next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


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

    ~List()
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

    ListNode* head = nullptr;
    size_t size;
};

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