class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.size()>s.size()) return 0;
        vector<vector<unsigned long long >>dp(t.size(),vector<unsigned long long >(s.size(),0));

        // for(int i=0; i<t.size(); i++){
        //     if(t[0]==s[0]){
        //         dp[i][0]=1;
        //     }
        // }
        if(t[0]==s[0]) dp[0][0]=1;
        for(int i=1; i<t.size(); i++){
          dp[i][0]=0;
         }
        for(int i=1; i<s.size(); i++){
            if(s[i]==t[0]){
                dp[0][i]=dp[0][i-1]+1;
            }
            else dp[0][i]=dp[0][i-1];
        }
        //1st row and col done....

        for(int i=1; i<t.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(t[i]==s[j]){
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[t.size()-1][s.size()-1];
    }
};
