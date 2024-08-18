class Solution {
public:
    int nthUglyNumber(int n) {
        //very good question--optimal soln(O(N))
        vector<int>t(n+1);//take a large size vector for nth==index
        int i2=1,i3=1,i5=1;//to keep count 
        t[1]=1;//start with base
        for(int i=2;i<=n;i++){
           int ui2=t[i2]*2;
           int ui3=t[i3]*3;
           int ui5=t[i5]*5;
            int minu = min({ui3,ui2,ui5});//take min of 3 and move to arr
            t[i]=minu;
            //move pointer of added one and other remain  same
            if(minu==ui2)
            i2++;
            // no else if because for same we should move both
            if(minu==ui3)
            i3++;
            if(minu==ui5)
            i5++;
        }
        return t[n];
    }
};
