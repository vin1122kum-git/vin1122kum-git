class Solution {
public:
int solve(string s, string t, int i, int j){
    //base case

    if(j<0) return 1;
    if(i<0) return 0;

    //possible ways
    if(s[i]==t[j]){
        return solve(s,t,i-1,j-1) + solve(s,t,i-1,j);
    }
    else{
        return solve(s,t,i-1,j);
    }
}

int solve(string s, string t, int i, int j,vector<vector<int>> &dp){
    //base case

    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    //possible ways
    if(s[i]==t[j]){
        return dp[i][j] = solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
    }
    else{
        return  dp[i][j] = solve(s,t,i-1,j,dp);
    }
}


int solveTab(string s , string t){
    vector<vector<unsigned long long >> dp(s.length()+1,vector<unsigned long long >(t.length()+1,0));

    for(int i=0;i<=s.length();i++) dp[i][0]=1;

    for(int j=1;j<=t.length();j++) dp[0][j]=0;

    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){
             if(s[i-1]==t[j-1]){
                     dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                      dp[i][j] = dp[i-1][j];
                }
        }
    }

    return dp[s.length()][t.length()];
}

    int numDistinct(string s, string t) {

        // vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));

        // return solve(s,t,s.length()-1,t.length()-1,dp);
        return solveTab(s,t);
        
    }
};