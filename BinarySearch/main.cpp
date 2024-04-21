//
// Created by F-Mir on 4/21/2024.
//
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    static int search(const vector<int>& nums, int target) {
        int begin = 0;
        int end = static_cast<int>(nums.size()) - 1;
        while (begin <= end)
        {
            auto current = begin + (end - begin) / 2;
            if (nums[current] == target)
            {
                return current;
            }
            if (nums[current] < target)
            {
                begin = ++current;
            }
            else
            {
                end = --current;
            }
        }
        return -1;
    }
};

int main()
{
    auto sortedVector = vector{-1, 0, 3, 5, 9, 12};

    assert(Solution::search(sortedVector, 9) == 4);
    assert(Solution::search(sortedVector, 2) == -1);
    assert(Solution::search(vector{5}, 5) == 0);
    assert(Solution::search(vector{5}, -5) == -1);
    return 0;
}