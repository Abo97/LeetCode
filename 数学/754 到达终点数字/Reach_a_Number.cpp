/*
	Time: 4ms
	Memory: 8.2MB
*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int step = 0;
        while(target>sum||(target-sum)%2!=0)
        {
            step++;
            sum+=step;
        }
        return step;
    }
};
