class KthLargest {
public:
//stream means cont. flow
//dont need unique -- just value at posn
//kth largest-- 2 arg k+arr
//brute force -- initial arr sort--add so sorted -- use binary search
//kth largest--smallest heap-- which heap?? min/max largest--min smallest--max
//logic--konse pehle nikalne h 
priority_queue<int, vector<int>,greater<int>>pq;
int f;
    KthLargest(int k, vector<int>& nums) {
        vector<int>res;
        f=k;
        //make min heap and keep sizeof k
        for(int&n : nums){
            pq.push(n);
            if(pq.size()>k)
            pq.pop();
        }
        //dont need min element

        
    }
    int add(int val) {
        pq.push(val);
        if(pq.size()>f)
        pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
