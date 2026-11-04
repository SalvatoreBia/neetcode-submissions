class Solution {
public:
    bool isValid(string s) {
        if( s.length() == 1 ) return false;

        auto is_closing = []( char c ){ 
            return c == ')' || c == ']' || c == '}';
        };
        auto is_opening = []( char c ){ 
            return c == '(' || c == '[' || c == '{';
        };
        if( is_closing(s[0]) ) return false;

        auto is_matching = []( char a, char b ){
            return (a == '(' && b == ')') ||
                   (a == '[' && b == ']') ||
                   (a == '{' && b == '}');
        };

        std::stack<char> stk;
        stk.push(s[0]);
        int i = 1;
        while( i < s.length() )
        {
            char c = s[i++];
            if( is_opening(c) ) stk.push(c);
            else
            {
                if( stk.empty() || !is_matching(stk.top(), c) )
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
