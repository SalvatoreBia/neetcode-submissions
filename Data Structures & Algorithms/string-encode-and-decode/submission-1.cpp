class Solution {
public:
    Solution() = default;
    std::string encode(std::vector<std::string>& strs)
    {
        std::string encoding = "";
        for( std::string s : strs )
            encoding += ( std::to_string(s.length()) + "#"  + s );
        return encoding;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> sol;
        bool is_len = true;
        std::string curr = "";
        int curr_len = -1;
        int i = 0;
        for( ; i < s.length(); )
        {
            if( is_len )
            {
                char c = s[i++];
                if( c == '0' ) {
                    sol.push_back( "" );
                    i++;
                }
                else
                {
                    while( c != '#' )
                    {
                        curr += c;
                        c = s[i++];
                    }
                    curr_len = std::stoi( curr );
                    curr = "";
                    is_len = false;
                }
            }
            else
            {
                while( curr_len > 0 )
                {
                    curr += s[i++];
                    curr_len--;
                }

                sol.push_back( curr );
                is_len = true;
                curr = "";
            }
        }
        return sol;
    }
};