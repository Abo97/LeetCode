/*
	Time: 8ms
	Memory: 8.6MB
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast;
        int slow = 0;
        for(fast = 0;fast < nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
