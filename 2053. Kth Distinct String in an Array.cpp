 class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int res=0;
        
        for(auto &i: arr){
            if(mp[i]==1)
            res++;
        
         if (res==k) 
            return i;
        }
        return ""; 
    }
};
