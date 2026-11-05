class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int result = 0 ;

        for(int i = 0 ; i<n ; i++){
            int flag = 1 ;
            int sum = 0;
            for(int j = 0 ; j<m ; j++){
                 sum = abs(arr1[i] - arr2[j]);
                if(sum <= d){
                    flag = 0;
                }
               
            }
            if(flag == 1) result++;
            
            
        }
        
        return result;
    }
    
};