/*
	Time: 28ms（压缩前）12ms（压缩后）
	Memory: 10.7MB
*/
class Solution {
public:
    int parent[210];
    //查找该节点属于哪一朋友圈
    int Find(int x)
    {
        while(x!=parent[x])
        {
			//路径压缩
			parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    //合并节点：设置为同一朋友圈
    void Union(int a,int b)
    {
        int pa = Find(a);
        int pb = Find(b);
        if(pa!=pb)
        {
            parent[pa] = pb;
        }
    }
    //最开始,每个节点各自为一朋友圈
    void init()
    {
        for(int i=0;i<210;i++)
        {
            parent[i] = i;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        init();
        //对N个学生两两做判断
        for(int i = 0;i < M.size();i++)
        {
            for(int j=i+1;j < M.size();j++)
            {
                if(M[i][j]==1)
                {
                    Union(i,j);
                }
            }
        }
        //一次遍历找到所有祖先节点，即为朋友圈的个数
        int circle = 0;
        for(int i = 0;i < M.size();i++)
        {
            if(i == parent[i])
            {
                circle++;
            }
        }
        return circle;
    }
};
