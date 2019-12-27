/*
	Time: 228ms
	Memory: 14.8MB
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> ans (T.size(), 0);
        stack <int> res;
        for(int i = T.size()-1; i >= 0; --i)
        {
            while(!res.empty() && T[i] >= T[res.top()]) res.pop();
            if(res.empty())
                ans[i] = 0;
            else
                ans[i] = res.top() - i;
            res.push(i);
        }
        return ans;
    }
};
