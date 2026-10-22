class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        auto size = nums.size();
        if( size <= 1 ) return false;

        std::unordered_set<int> s;
        for( auto i{ 0 }; i < size; ++i )
        {
            if( !s.insert(nums[i]).second ) return true;
        }

        return false;
    }
};