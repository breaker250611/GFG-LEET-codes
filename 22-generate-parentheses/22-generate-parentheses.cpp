class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        aaega(n,2*n,ans,"",0,0,0);
        return ans;
    }
    void aaega(int n, int totalsize,vector<string>&ans,string psf,int kn,int i,int kc){
        
        if(i==totalsize){
            ans.push_back(psf);
            return;
        }
        if(kn==0||psf.size()==0) {
            aaega(n,totalsize,ans,psf+'(',kn+1,i+1,kc);
        }
        else if(kn==n){
            aaega(n,totalsize,ans,psf+')',kn,i+1,kc+1);
        }
        else{
            aaega(n,totalsize,ans,psf+'(',kn+1,i+1,kc);
            if(kn>kc){
                aaega(n,totalsize,ans,psf+')',kn,i+1,kc+1);
            }

        }
    }
};