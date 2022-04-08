class Solution {
public:
    int mxans=0;
    map<char,int>mp;
    int maxLength(vector<string>& arr) {
        mxans = 0;
        // mp.clear();
        calling(arr,0,"");
        return mxans;
    }

    void calling (vector<string>&arr,int i,string psf){
        if(psf.size()>mp.size()) return;
        cout<<psf.size()<<mp.size()<<endl;    
        cout<<psf<<endl;
            
                int temp = mp.size();
                // cout<<psf<<" "<<temp<<endl;
                mxans = max(temp,mxans);
            
        if(i==arr.size())return;
    
        
        calling(arr,i+1,psf);
        
           string temp1 = arr[i];
            for(int j = 0;j<temp1.size();j++){
                mp[temp1[j]]++;
            }
            calling(arr,i+1,psf+temp1);
            for(int j =0;j<temp1.size();j++){
                mp[temp1[j]]--;
                if(mp[temp1[j]]==0) 
                    mp.erase(temp1[j]);
            }
        
    }
};