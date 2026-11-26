class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10 ; 
        int step = 0 ;
        while(n >= take){
            n -= take ; 
            take -= 1;
            step++;
        }
        if(step%2 != 0 ){
            return true;
        }else{
            return false;
        }
    }
};