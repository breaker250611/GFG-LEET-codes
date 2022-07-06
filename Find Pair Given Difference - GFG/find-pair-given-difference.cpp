// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    map<int,int>mp;
    for(int i = 0;i<size;i++){
        mp[arr[i]]++;
    }
    for(int i = 0;i<size;i++){
        int temp = arr[i];
        int hosakta1 = n + temp;
        int hosakta2 = temp-n;
        mp[temp]--;
        if(mp[temp]==0)mp.erase(temp);
        if(mp.find(hosakta1)!=mp.end()||mp.find(hosakta2)!=mp.end()) return true;
        
    }
    return false;
    
}