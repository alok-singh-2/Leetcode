class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //brute force approach
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<vector<int>> ans(n, vector<int>(m, 0));
        // for(int i = 0 ; i<m ; i++){
        //     for(int j = 0 ; j<n ; j++){
        //         ans[j][n-1-i] = matrix[i][j];
        //     }
        // }
        // matrix = ans;


        //optimal approach
        int n = matrix.size();
        for(int i = 0 ; i<n-1; i++){
            for(int j = i+1; j<n ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i = 0 ; i<n ; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }


    }
};