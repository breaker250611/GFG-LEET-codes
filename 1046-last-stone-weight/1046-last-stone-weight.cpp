class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int y = stones[stones.size()-1];
                stones.pop_back();
            int x = stones[stones.size()-1];
                stones.pop_back();
            if(y>x){
                    stones.push_back(y-x);

            }            
        }
        if(stones.size()==0) return 0;
        else return stones[0];
    }
};