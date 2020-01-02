/*
	Time: 24ms
	Memory: 10.6MB
*/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s;
        int n=fronts.size();
        for(int i=0;i<n;++i)
        {
            if(fronts[i]==backs[i])
                s.insert(fronts[i]);
        }

        int res=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(fronts[i]==backs[i])
                continue;
            if(backs[i]<res)
            {
                if(s.find(backs[i])==s.end())
                {
                    res=min(res,backs[i]);
                }
            }
            if(fronts[i]<res)
            {
                if(s.find(fronts[i])==s.end())
                {
                    res=min(res,fronts[i]);
                }
            }
        }
        return res==INT_MAX?0:res;
    }
