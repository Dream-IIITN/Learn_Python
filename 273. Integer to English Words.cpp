class Solution {
public:
unordered_map<int, string> belowTen = { {0, ""}, {1, "One"},
{2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},
{7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
//making pairs for below 10 
unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, 
{13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
{17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
//making pairs for below 20
unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, 
{4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, 
{8, "Eighty"}, {9, "Ninety"} };
//making pairs for prefix hundred
    string solve(int num){
        if(num<10){
            return belowTen[num];
//when less than 10
        }
        if(num<20){
            return belowTwenty[num];
//when less than 20
        }
         if(num<100){
            string x="";
            if(num%10!=0)
            x=" "+belowTen[num%10];
            return belowHundred[num/10]+x;
// when less than 100 --> 89   89/10==8 "eighty"  89%10==9 "nine" 
        }
        if(num<1000){
            string x="";
            if(num%100!=0)
            x=" "+solve(num%100);
            return solve(num/100)+ " Hundred" + x;
// 899 < 1000  899/100=8  eight  hundred  899%100=99  call solve(99) 
        }
// main pattern solve(x) + "place" + solve(y)

          if(num < 1000000) {
            return solve(num/1000) + " Thousand" + ((num%1000 != 0) ? " " + solve(num%1000) : "");
        }
        if(num < 1000000000) {
            return solve(num/1000000) + " Million" + ((num%1000000 != 0) ? " " + solve(num%1000000) : "");
        }
        return solve(num/1000000000) + " Billion" + ((num%1000000000 != 0) ? " " + solve(num%1000000000) : "");
  //call again and again so recursion    
}

    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }  
        return solve(num);

    //solve function + proper + solve again  
    }
};
