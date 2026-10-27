class Solution {
public:
    struct ArrayHash
    {
        std::size_t operator()(const std::array<int, 26>& arr) const noexcept
        {
            std::size_t seed = 0;
            for( int i : arr )
                seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    std::array<int, 26> getFreq(const std::string& sv)
    {
        std::array<int, 26> freq = { 0 };
        for( char c : sv )
            freq[c - 97]++;
        return freq;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto size = strs.size();

        std::vector<std::vector<std::string>> sol;
        sol.reserve(size);

        std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHash> m;
        for( std::string s : strs )
        {
            if( auto p=m.insert({ getFreq(s), {s} }); !p.second )
                p.first->second.push_back( s );
        }

        for( auto& kv : m )
            sol.push_back( std::move(kv.second) );

        return sol;
    }
};
