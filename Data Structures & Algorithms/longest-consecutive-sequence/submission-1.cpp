class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        std::unordered_set<int> s(nums.begin(), nums.end());

        std::vector<int> starts;
        starts.reserve(nums.size());
        for( int n : nums )
            if( !s.contains(n-1) )
                starts.push_back(n);

        int max_len = -1;
        for( int n : starts )
        {
            int len = 1;
            int i = 1;
            while( s.contains(n+(i++)) ) len++;
            max_len = std::max(max_len, len);
        }

        return max_len;
    }
};
