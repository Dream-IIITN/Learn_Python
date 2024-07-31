The Approaches I learnt:

class Solution {
public:
int n,w;//global variables
    int t[1001][1001];//2-d global array
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //given:books->thick,width and shelfwidth
        // case height = max height of each shelf
        // follow the same order
        // return min possible height of whole shelf
        // thought process: 
        // dp --cant with greedy 
        // constraint-- shelf width remaining
        // --make tree-- recur+memo
        // calcualte sum of optimum path==soln
        memset(t,-1,sizeof(t));//filling value -1
        n=books.size();
        w=shelfwidth;
        int remain = shelfwidth;
        return solve(books,0,remain,0);
    }
    int solve(vector<vector<int>>&books,int i,int remain,int mxheight){
        if(i>=n)//no books
        return mxheight;
        if(t[i][remain]!=-1)//condition
        return t[i][remain];

        int bw = books[i][0];
        int bh = books[i][1];
        int keep =INT_MAX,skip=INT_MAX;//because of max fn!
        if(bw<remain)
        keep = solve(books,i+1,remain-bw,max(mxheight,bh));
        skip = mxheight+solve(books,i+1,w-bw,bh);//skip current shelf and keep in next one
        return t[i][remain]=min(keep,skip);//pick min one!
    }
};
