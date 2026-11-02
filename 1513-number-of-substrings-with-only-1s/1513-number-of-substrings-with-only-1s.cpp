class Solution {
public:
        long long M = 1e9 + 7;

    int numSub(string s) {
        long long result = 0 ;
       long long count = 0 ;
        int n = s.size();
        
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '1'){
                count++;
            }else{
                result = (result + count*(count+1)/2)%M;
                count = 0;
            }
        }
//agar last for me bhi koei 1s ka count badh gya or last etring khatam 1 se hoga to else condition chalega nhi to iske liye yk baar aur result me count add kr diye.

      result = (result + count*(count+1)/2)%M;
       return (int)result;
    }
};