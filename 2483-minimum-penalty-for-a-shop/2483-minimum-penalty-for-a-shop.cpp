class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int>ans(customers.size(),0);
        int count = 0;
        
        for(int i = customers.size()-1;i>=0;i--){
            ans[i] = count;
            if(customers[i]=='Y')count++;
        }
        
        
        int finalans = INT_MAX;
        int temp = 0;
            int ind  = 0;
        for(int i = 0;i<customers.size();i++){
            int res = temp;
            res += ans[i];
            if(customers[i]=='Y'){
                res++;
            }
            else{
                temp++;
            }
            
           if(res<finalans){
               ind = i;
               finalans = res;
           }
        }
        
        if(temp<finalans){
            ind = customers.size();
        }
            // cout<<finalans<<endl;
        return ind;
    }
};