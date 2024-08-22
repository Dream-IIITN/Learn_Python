// class Solution {
// public:
//     int findComplement(int num) {
//         int n=0; 
//         vector<int>v;
//         while(num>0){
//             v.push_back(num%2);
//             num=num/2;
//         }
//         for(int i=v.size()-1;i>=0;i--){
//             if(v[i]==0)
//             n+=pow(2,v.size()-i-1);
//         }
//         return n;
//     }
// };
class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;  // Edge case for 0
        
        int mask = 0;
        int temp = num;
        
        // Create a mask with all bits set to 1 that are the same length as num
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        // XOR num with mask to get the complement
        return num ^ mask;
    }
};
