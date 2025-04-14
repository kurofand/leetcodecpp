/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0

Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

*/

#include <iostream>
#include <vector>

/*
In some reason I though that there should be a reverse loop, but probably inc loop is also fine
So how it works:
Similar to prev. challenge it goes though the vector, finds best price for sell
and first best price to buy. Then it memorises current profit to total and looks
for next best sell price.
*/
int main()
{
	std::vector<int> prices={2,2,5};

	int profit=0, totalProfit=0;
	int sell=prices.back();

	for(int i=prices.size()-2;i>=0;i--)
		if(prices[i]>sell)
			sell=prices[i];
		else if(profit<sell-prices[i])
		{
			profit=sell-prices[i];
			if((i==0&&profit!=0)||(prices[i-1]>=prices[i]))
			{
				totalProfit+=profit;
				sell=i>0?prices[i-1]:0;
				profit=0;
			}
		}

	std::cout<<totalProfit<<std::endl;
	return 0;
}
