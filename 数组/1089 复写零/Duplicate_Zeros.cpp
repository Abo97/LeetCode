/*
	Time: 36ms
	Memory: 9.2MB
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
      
      int size = arr.size();
      int offset = 0;
      
      // 第一次遍历，计算数组中0的个数
      for (int i=0; i<size; i++) {
        if (!arr[i]) offset++;
      }
      
      // 第二次遍历，从后向前按偏移量移动元素
      for (int i=size-1; i>-1; i--) {
        if (!arr[i]) {
          offset--;
          if (i+offset < size) arr[i+offset] = 0;
          if (i+offset+1 < size) arr[i+offset+1] = 0;
        }
        else if (i+offset < size) arr[i+offset] = arr[i];
      }
    }
};
