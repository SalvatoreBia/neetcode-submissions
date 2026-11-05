class MinStack {
public:
    MinStack(){ }
    
    void push(int val) {
        stk.push_back( val );
        if( stk.size() == 1 )
        {
            mins.push_back( 0 );
        }
        else
        {
            int curr_min = stk[mins.back()];
            if( curr_min > val )
                mins.push_back( stk.size()-1 );
        }
    }
    
    void pop() {
        if( int m=mins.back(); m == stk.size()-1 )
            mins.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return stk[mins.back()];
    }

private:
    std::vector<int> stk;
    std::vector<int> mins;
};
