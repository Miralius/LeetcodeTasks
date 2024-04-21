//
// Created by F-Mir on 4/21/2024.
//

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    static int singleNumber(vector<int>& nums)
    {
        int result{};
        for (int num: nums)
        {
            result ^= num;
        }
        return result;
    }
};

int main()
{
    {
        auto vec = vector{2, 2, 1};
        assert(Solution::singleNumber(vec) == 1);
    }
    {
        auto vec = vector{4, 1, 2, 1, 2};
        assert(Solution::singleNumber(vec) == 4);
    }
    {
        auto vec = vector{1};
        assert(Solution::singleNumber(vec) == 1);
    }
    return 0;
}