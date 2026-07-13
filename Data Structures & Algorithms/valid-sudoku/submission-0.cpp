class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]={};
        bool columns[9][9]={};
        bool boxes[9][9]={};
        static const int box_index[9][9]={{0,0,0,1,1,1,2,2,2},{0,0,0,1,1,1,2,2,2},{0,0,0,1,1,1,2,2,2},{3,3,3,4,4,4,5,5,5},{3,3,3,4,4,4,5,5,5},{3,3,3,4,4,4,5,5,5},{6,6,6,7,7,7,8,8,8},{6,6,6,7,7,7,8,8,8},{6,6,6,7,7,7,8,8,8}};
        for(int r=0;r<9;r++){
            for (int c=0; c<9;c++){
                char value=board[r][c];
                if (value=='.'){
                    continue;
                }
                int num=value-'1';
                int box=box_index[r][c];
                if (rows[r][num] || columns[c][num] || boxes[box][num]){
                    return false;
                }
                rows[r][num]=true;
                columns[c][num]=true;
                boxes[box][num]=true;

            }
        }
        return true;
    }
};
