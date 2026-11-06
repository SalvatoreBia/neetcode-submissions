class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;

        auto isexp = []( const std::string& sv ){
            return sv == "+" || sv == "*" || sv == "/" || sv == "-";
        };

        for( std::string sv : tokens )
        {
            if( isexp(sv) )
            {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if( sv == "+" ) stk.push(a + b);
                else if( sv == "-" ) stk.push(a - b);
                else if( sv == "*" ) stk.push(a * b);
                else if( sv == "/" ) stk.push(a / b);
            }
            else stk.push( std::stoi(sv) );
        }

        return stk.top();
    }
};
