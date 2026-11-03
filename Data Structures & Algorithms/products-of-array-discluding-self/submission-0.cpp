class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> prods( size, 1 );

        for( int i{ 1 }; i < size; ++i )
            prods[i] *= nums[i-1] * prods[i-1];

        int r = 1;
        for( int i{ size - 2 }; i >= 0; --i )
        {
            r *= nums[i+1];
            prods[i] *= r;
        }
        return prods;
    }
};
