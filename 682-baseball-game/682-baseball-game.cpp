class Solution {
public:
    int calPoints(vector<string>& ops) {
     vector<int>vp;
        for(int i = 0 ;i<ops.size();i++){
            string str = ops[i];
            if(str=="C"){
              vp.pop_back();  
            }
            else if(str=="D"){
                int temp = vp[vp.size()-1];
                vp.push_back(temp*2);
            }
            else if(str=="+"){
                int size = vp.size();
                int temp1 = vp[size-1];
                int temp2 = vp[size-2];
                vp.push_back(temp1+temp2);
            }
            else{
                int temp = stoi(str);
                vp.push_back(temp);
            }
        }
        int sum = accumulate(vp.begin(),vp.end(),0);
        return sum;
    }
};