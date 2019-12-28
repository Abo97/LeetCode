/*
	Time: 20ms
	Memory: 9.7MB
*/
class Solution {
public:
    //求最大公约数
    int help(int num1, int num2)
    {
        int max_num = max(num1, num2);
        int min_num = min(num1, num2);

        while(1)
        {
            int key = max_num % min_num;
            if(key == 0)
                return min_num;
            else
            {
                max_num = min_num;
                min_num = key;
            }
        }
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        //排序(用数组代替更高效)
        //求得每一个数的个数
        //求最大公约数，看是否大于1
        if(deck.size() <= 1)
            return false;

        sort(deck.begin(), deck.end());

        vector<int> vec;
        int num = 1;
        for(int i = 1; i < deck.size(); i++)
        {
            if(deck[i] != deck[i - 1])
            {
                vec.push_back(num);
                num = 1;
            }
            else
                num++;

            if(i == deck.size() - 1)
                vec.push_back(num);
        }

        //求vec的最大公约数
        int last = vec[0];
        for(int i = 0; i < vec.size(); i++)
        {
            last = help(last, vec[i]);
            if(last < 2)
                return false;
        }

        return true;
    }
};
