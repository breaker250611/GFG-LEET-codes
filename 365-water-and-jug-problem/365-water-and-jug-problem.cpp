class Solution {
public:
 bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity,y=jug2Capacity,z=targetCapacity;
        queue<int> q;
        vector<int> dir={x,-x,y,-y};
        unordered_map<int,int> vis;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int flag=q.front();q.pop();
            for(auto &p:dir){
                int a=p+flag;
                if(a<0 || a>(x+y)) continue;
                if(a==z) return 1;
                if(!vis.count(a)){
                    q.push(a);
                    vis[a]=1;
                }
            }
        }
        return 0;
    }
};