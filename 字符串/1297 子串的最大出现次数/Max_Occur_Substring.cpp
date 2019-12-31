/*
	Time: 304ms
	Memory: 74MB
*/
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> occ;
        int ans = 0;
        for (int i = 0; i < n - minSize + 1; ++i) {
            string cur = s.substr(i, minSize);
            unordered_set<char> exist(cur.begin(), cur.end());
            if (exist.size() <= maxLetters) {
                ++occ[cur];
                ans = max(ans, occ[cur]);
            }
        }
        return ans;
    }
};
