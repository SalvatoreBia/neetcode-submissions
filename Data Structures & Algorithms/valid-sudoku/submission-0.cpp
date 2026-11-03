class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<unordered_set<char>, 9> rows;
        std::array<unordered_set<char>, 9> cols;
        std::array<unordered_set<char>, 9> tiles;

        for( auto i{ 0 }; i < 9; ++i )
        {
            for( auto j{ 0 }; j < 9; ++j )
            {
                char elem = board[i][j];
                if( elem == '.') continue;

                if( !rows[i].insert(elem).second ) return false;
                if( !cols[j].insert(elem).second ) return false;

                int idx = (i/3) * 3 + (j/3);
                if( !tiles[idx].insert(elem).second ) return false;
            }
        }

        return true;
    }
};
