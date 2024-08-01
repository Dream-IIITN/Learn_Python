class Solution {
public:
    int countSeniors(vector<string>& details) {
        //passenger --s.len()=15 
        // (10)ph.no.+(1)gender+(2)age+(2)seat
        // return >60 year old
        int c=0;
        for(string s : details){
            string t = s.substr(11,2);
            int r = stoi(t);
            if(r>60)
            c++;
        }
      return c;  
    }
};
