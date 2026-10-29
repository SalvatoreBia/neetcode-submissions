class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        std::unordered_map<int, int> m;
        for( int n : nums )
        {
            if( auto p=m.insert({n, 1}); !p.second )
                p.first->second++;
        }

        std::vector<int> sol; sol.reserve( k );
        std::vector<std::vector<int>> v( size + 1, std::vector<int>() );
        for( auto kv : m )
            v[kv.second].push_back( kv.first );

        for( int i{ size }; i >= 0 && k > 0 ; --i )
        {
            for( int j{ 0 }; j < v[i].size() && k > 0; ++j )
            {
                sol.push_back( v[i][j] );
                --k;
            }
        }

        return sol;
    }
};
