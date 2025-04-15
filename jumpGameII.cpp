/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1]. 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> nums={9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5};

	int jumps=0;
	int near=0, far=0;
	while(far<nums.size()-1)
	{
		int maxJump=0;
		for(int i=near;i<=far;i++)
			maxJump=std::max(maxJump, i+nums[i]);
		near=far+1;
		far=maxJump;
		jumps++;
	}
	std::cout<<jumps<<std::endl;
	return 0;
}
