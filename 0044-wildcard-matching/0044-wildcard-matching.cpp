class Solution {
public:
bool solve(string s, string p,int i, int j){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0)  return false;

    if(j<0 && i>=0){
        bool flag=true;
        for(int ii=0;ii<=i;ii++){
            if(p[ii]!='*'){
                flag=false;
                break;
            }
        }

        return flag;
    }


    if(p[i]==s[j] || p[i]=='?'){
        return solve(s,p,i-1,j-1);
    }

    else if(p[i]=='*'){
        return (solve(s,p,i-1,j) ||  solve(s,p,i,j-1));
    }

    return false;

}

bool solve(string s, string p,int i, int j,vector<vector<int>> &dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0)  return false;

    

    if(j<0 && i>=0){
        bool flag=true;
        for(int ii=0;ii<=i;ii++){
            if(p[ii]!='*'){
                flag=false;
                break;
            }
        }

        return flag;
    }

    if(dp[i][j]!=-1) return dp[i][j];


    if(p[i]==s[j] || p[i]=='?'){
        return dp[i][j]=solve(s,p,i-1,j-1,dp);
    }

    else if(p[i]=='*'){
        return dp[i][j]=(solve(s,p,i-1,j,dp) ||  solve(s,p,i,j-1,dp));
    }

    return dp[i][j]=false;

}

bool solveTab(string s, string p){

    vector<vector<bool>> dp(p.length()+1,vector<bool>(s.length()+1,false));

    dp[0][0]=true;

    for(int j=1;j<=s.length();j++){
        dp[0][j]=false;
    }

    for(int i=1;i<=p.length();i++){

        bool flag=true;
        for(int ii=1;ii<=i;ii++){
            if(p[ii-1 ]!='*'){
                flag=false;
                break;
            }
        }

        dp[i][0]=flag;

    }


    for(int i=1;i<=p.length();i++){
        for(int j=1;j<=s.length();j++){

             if(p[i-1]==s[j-1] || p[i-1]=='?'){
                     dp[i][j]=dp[i-1][j-1];
                }

                else if(p[i-1]=='*'){
                     dp[i][j]=dp[i-1][j] ||  dp[i][j-1];
                }

                else{
                         dp[i][j]=false;
                }

            

        }
    }


    return dp[p.length()][s.length()];

}
    bool isMatch(string s, string p) {

        // vector<vector<int>> dp(p.length()+1,vector<int>(s.length()+1,-1));

        // return solve(s,p,p.length()-1,s.length()-1,dp);

        return solveTab(s,p);
        
    }
};