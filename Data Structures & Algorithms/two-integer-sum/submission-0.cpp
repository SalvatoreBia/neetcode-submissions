class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto size = nums.size();
        if( size == 2 ) return {0, 1};

        std::unordered_map<int, int> m;
        for( auto i{ 0 }; i < size; ++i )
        {
            int diff = target - nums[i];
            if( auto p=m.insert({nums[i], i}); !p.second )
                return {p.first->second, i};
            else
                m.insert({diff, i});
        }

        return {-1, -1};
    }
};
