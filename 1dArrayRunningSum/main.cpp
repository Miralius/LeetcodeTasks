//
// Created by F-Mir on 4/14/2024.
//
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
public:
    static vector<int> runningSum(vector<int>& nums)
    {
        std::vector<int> result;
        result.reserve(1000);
        int sum(0);
        transform(nums.cbegin(), nums.cend(), back_inserter(result),
                  [&sum](auto number)
                  {
                      sum += number;
                      return sum;
                  });
        return result;
    }
};

int main()
{
    {
        auto vec = vector{1, 2, 3, 4};
        assert(Solution::runningSum(vec) == vector({1, 3, 6, 10}));
    }
    {
        auto vec = vector{1, 1, 1, 1, 1};
        assert(Solution::runningSum(vec) == vector({1, 2, 3, 4, 5}));
    }
    {
        auto vec = vector{3, 1, 2, 10, 1};
        assert(Solution::runningSum(vec) == vector({3, 4, 6, 16, 17}));
    }
    return 0;
}