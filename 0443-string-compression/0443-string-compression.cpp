class Solution {
public:
    int compress(vector<char>& chars) {
       int index = 0;
        int n = chars.size();

        int i = 0 ;
        while(i<n){
            char currchar = chars[i];
            int count =0;

            while(i<n && currchar == chars[i]){
                count++;
                i++;
            }
            chars[index] = currchar;
            index++;

            if(count>1){
                string count_str = to_string(count);
                
                for(char &ch : count_str){
                    chars[index] = ch;

                    index++;
                }
            }
        }
        return index;
    }
};