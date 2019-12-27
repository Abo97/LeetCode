class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T){
        int len = T.size();
        vector<int> result(len,0);
        result[len-1]=0;//最后一个节点绝对是0；
        for(int i=len-2;i>=0;i--){
            for(int j=i+1;j<len;j+=result[j]){
                if(T[j]>T[i]){
                    result[i] = j-i;
                    break;
                }
                else if(result[j]==0){//判断条件是T[i]<=T[j]并且result[j]==0,所以相当于没有找到比T[i]数更大的数，result[i]=0即可；
                    result[i]=0;
                    break;
                }
            }
        }
        return result;
    }
};
