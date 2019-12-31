/*
	Time: 12ms
	Memory: 9.6MB
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int INF = 1e8;
        int n = A.size();
        for(int r = n-2; r >= 0; --r){
            for(int c = 0; c < n ; ++c){
                int best = A[r+1][c];
                if(c > 0){
                    best = min(best, A[r+1][c-1]);
                }
                if(c+1 < n){
                    best = min(best, A[r+1][c+1]);
                }
                A[r][c] += best;
            }
        }
        int ans = INF;
        for(int i = 0;i < A[0].size();++i){
            ans = min(ans,A[0][i]);
        }
        return ans;
    }
};
