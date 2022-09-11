#include "dp.hpp"





//Dynamic Programming
//leetcode problem 70
//https://leetcode.com/problems/climbing-stairs/


int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


//leetcode problem 303
//https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp=nums;
        for(int i=1;i<nums.size();i++){
            dp[i]+=dp[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return dp[right];
        return dp[right]-dp[left-1];
    }
};







//leetcode problem 338
//https://leetcode.com/problems/counting-bits/
vector<int> countBits(int n) {
    vector<int> dp(n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i/2]+i%2;
    }
    return dp;
}





//leetcode problem 494
//https://leetcode.com/problems/target-sum/
int findTargetSumWays(vector<int>& nums, int target) {
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    if(sum<target) return 0;
    if((sum+target)%2!=0) return 0;
    int s=(sum+target)/2;
    int dp[s+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<nums.size();i++){
        for(int j=s;j>=nums[i];j--){
            dp[j]+=dp[j-nums[i]];
        }
    }
    return dp[s];
}





//leetcode problem 198
//https://leetcode.com/problems/house-robber/
int rob(vector<int>& nums) {
    if(nums.size()==0) return 0;
    if(nums.size()==1) return nums[0];
    int dp[nums.size()];
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[nums.size()-1];
}







///leetcode problem 53
//https://leetcode.com/problems/maximum-subarray/

/**
Given an integer array nums, find the contiguous subarray (containing at least one number)
 which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 * 
 */


int maxSubArray(vector<int>& nums) {
    int dp[nums.size()];
    dp[0]=nums[0];
    int ans=dp[0];
    for(int i=1;i<nums.size();i++){
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        ans=max(ans,dp[i]);
    }
    return ans;
}



//leetcode problem 213
//https://leetcode.com/problems/house-robber-ii/

/*

You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed. 
 All houses at this place are arranged in a circle. 
 That means the first house is the neighbor of the last one. 
 Meanwhile, adjacent houses have a security system connected, 
 and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3


*/

int rob2(vector<int>& nums) {
    if(nums.size()==0) return 0;
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0],nums[1]);
    int dp[nums.size()];
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<nums.size()-1;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    int ans=dp[nums.size()-2];
    dp[0]=0;
    dp[1]=nums[1];
    for(int i=2;i<nums.size();i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    ans=max(ans,dp[nums.size()-1]);
    return ans;
}




//leetcode problem 322
//https://leetcode.com/problems/coin-change/
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount.
 If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

int coinChange(vector<int>& coins, int amount) {
    int dp[amount+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=amount;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[amount]==INT_MAX) return -1;
    return dp[amount];
}





//leetcode problem 152
//https://leetcode.com/problems/maximum-product-subarray/
/*


Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/


int maxProduct(vector<int>& nums) {
    int dp[nums.size()];
    int dp2[nums.size()];
    dp[0]=nums[0];
    dp2[0]=nums[0];
    int ans=dp[0];
    for(int i=1;i<nums.size();i++){
        dp[i]=max(nums[i],max(dp[i-1]*nums[i],dp2[i-1]*nums[i]));
        dp2[i]=min(nums[i],min(dp[i-1]*nums[i],dp2[i-1]*nums[i]));
        ans=max(ans,dp[i]);
    }
    return ans;
}



//leetcode problem 300
//https://leetcode.com/problems/longest-increasing-subsequence/
/*


Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/


int lengthOfLIS(vector<int>& nums) {
    int dp[nums.size()];
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=0;i<nums.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}



//5. Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/

/*
5. Longest Palindromic Substring
Medium

21362

1227

Add to List

Share
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
Accepted
2,086,000
Submissions
6,448,375

*/


string longestPalindrome(string s) {
    int dp[s.size()][s.size()];
    memset(dp,0,sizeof(dp));
    int ans=0;
    int start=0;
    int end=0;
    for(int i=0;i<s.size();i++){
        dp[i][i]=1;
        ans=1;
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            ans=2;
            start=i;
            end=i+1;
        }
    }
    for(int i=3;i<=s.size();i++){
        for(int j=0;j<s.size()-i+1;j++){
            int k=j+i-1;
            if(dp[j+1][k-1]==1 && s[j]==s[k]){
                dp[j][k]=1;
                if(i>ans){
                    ans=i;
                    start=j;
                    end=k;
                }
            }
        }
    }
    return s.substr(start,end-start+1);
}




///leetcode problem 139
//https://leetcode.com/problems/word-break/
/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

*/


bool wordBreak(string s, vector<string>& wordDict) {
    int dp[s.size()+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=s.size();i++){
        for(int j=0;j<i;j++){
            if(dp[j]==1){
                string temp=s.substr(j,i-j);
                if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end()){
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}


//leetcode problem 377
//https://leetcode.com/problems/combination-sum-iv/


/*


Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
 

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?


*/


    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; ++i){
            for(int j=0; j<n; ++j){
                if(i >= nums[j])
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }


//leetcode problem 91
//https://leetcode.com/problems/decode-ways/
/*

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

*/

int numDecodings(string s) {
    int n=s.size();//length of string
    int dp[n+1];//dp array
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=s[0]=='0'?0:1;
    for(int i=2;i<=n;i++){
        if(s[i-1]!='0'){
            dp[i]=dp[i-1];
        }
        if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')){
            dp[i]+=dp[i-2];
        }
    }
    return dp[n];
}


//leetcode problem 62
//https://leetcode.com/problems/unique-paths/
/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.

*/


int uniquePaths(int m, int n) {
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}











