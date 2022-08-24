class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int count  = 0;
        int jagah = startFuel;
        for(int i = 0;i<stations.size();i++){
            int idhar = stations[i][0];
            int petrol = stations[i][1];
            while(jagah <idhar){
                if(pq.empty()) return -1; 
                jagah +=pq.top();
                pq.pop();
                count++;
            }
            pq.push(petrol);
            
        }
        
        while(jagah<target){
                if(pq.empty()) return -1; 
                jagah +=pq.top();
                pq.pop();
                count++;
            
        }
        return count;
    }
};