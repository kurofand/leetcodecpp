/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
	std::vector<int> nums={-1,1,1,1,2,1};
	int n=nums.size();

/*
Easiest solution - sort and get element from middle. O(nlogn)

	std::sort(nums.begin(), nums.end());
	std::cout<<nums[n/2]<<std::endl;
*/

/*
Solution by map. O(n)
*/
	std::map<int, int> map;
	for(unsigned int i=0;i<n;i++)
		map[nums[i]]++;

	n=n/2;
	for(auto &[key, val]:map)
		if(val>n)
		{
			std::cout<<key<<std::endl;
			break;
		}
	return 0;
}
