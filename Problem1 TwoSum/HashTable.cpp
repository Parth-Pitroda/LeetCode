#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> indices(2);
        unordered_map<int, int> visitedElement;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int currentElement = nums[i];
            int secondElement = target - currentElement;

            if (visitedElement.count(secondElement))
            {
                indices[0] = visitedElement[secondElement];
                indices[1] = i;
                return indices;
            }

            visitedElement[currentElement] = i;
        }

        return {};
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = obj.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    }
    else
    
        cout << "No valid pair found." << endl;
    

    return 0;
}