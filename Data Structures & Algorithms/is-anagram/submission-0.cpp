class Solution {
public:
    bool isAnagram(string s, string t) {
        auto size{ s.size() };
        if( size != t.size() ) return false;

        constexpr std::array<uint8_t, 26> zero = { 0 };
        std::array<uint8_t, 26> freqs = { 0 };
        for( auto i{ 0 }; i < size; ++i )
        {
            freqs[s[i] - 97]++;
            freqs[t[i] - 97]--;
        }

        return zero == freqs;
    }
};
