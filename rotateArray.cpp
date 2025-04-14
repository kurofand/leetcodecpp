/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> nums={1,2,3,4,5,6,7};
	int k=3;
/*
//This solution worked fine in my local machine but in leetcode it failed on nums=[1,2,3], k=1 with [2,1,2] result.
	size_t s=nums.size();
	if(k>s)
		k=s-1;
	nums.insert(nums.begin(), nums.end()-k, nums.end());
	nums.resize(s);
*/

/*
This solution using std::reverse from <algorithm>
1. reverse whole vector - [1,2,3,4,5,6,7]->[7,6,5,4,3,2,1]
2. reverse vector part before k - [7,6,5,4,3,2,1]->[6,7,5,4,3,2,1]
3. reverse rest - [6,7,1,2,3,4,5]
*/
	k=k%nums.size();
	std::reverse(nums.begin(), nums.end());
	std::reverse(nums.begin(), nums.begin()+k);
	std::reverse(nums.begin()+k, nums.end());

	for(unsigned int i=0;i<nums.size();i++)
		std::cout<<nums[i];
	std::cout<<std::endl;
	return 0;
}
