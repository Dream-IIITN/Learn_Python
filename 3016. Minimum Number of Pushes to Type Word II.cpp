class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int sum=0;
        map<char,int>mp;
        vector<int>freq;
        for(auto &ch : word){
           mp[ch]++;  
        }
        for(auto it:mp){
            freq.push_back(it.second);
        }
        sort(freq.rbegin(),freq.rend()); 
        int asg=0;
        for(int i=0;i<freq.size();i++){
            asg+=freq[i]*(i/8+1);
        }
        return asg;
    }
};
