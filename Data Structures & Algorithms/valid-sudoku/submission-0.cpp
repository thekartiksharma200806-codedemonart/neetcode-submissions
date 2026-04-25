class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
                for(int i=0;i<9;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    mp[board[i][j]]++;
                    if(mp[board[i][j]]>1) return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    mp[board[j][i]]++;
                    if(mp[board[j][i]]>1) return false;
                }
            }
        }

        for(int block = 0; block < 9; block++) {
            unordered_map<char, int> mp;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    int row = (block / 3) * 3 + i;
                    int col = (block % 3) * 3 + j;

                    if(board[row][col] != '.') {
                        mp[board[row][col]]++;
                        if(mp[board[row][col]] > 1) return false;
                    }
                }
            }
        }

        return true;


        
    }
};
