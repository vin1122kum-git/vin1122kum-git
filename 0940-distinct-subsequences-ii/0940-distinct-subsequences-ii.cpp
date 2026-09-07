class Solution {
public:
const int MOD = 1e9 + 7;
int dp[2001];
vector<int> prev;

void solve(string s , int i, unordered_set<string> &st,string ans){
    if(i>=s.length()){
        if(ans.size()>0){
             st.insert(ans);
        }
       
        return;
    }

    // Take 
    
    ans.push_back(s[i]);
    solve(s,i+1,st,ans);
    ans.pop_back();


    // Not Take
    solve(s,i+1,st,ans);

}

int solve(int n){
    if(n==0){
        return 1;
    }

    if(dp[n]!=-1) return dp[n];

    int total = (2 * solve(n-1))%MOD;

    if(prev[n]!=0){
        int duplicates =  (solve(prev[n]-1))%MOD;
        total= (total - duplicates +MOD)%MOD;
    }
    

    return dp[n]= total;
}



    int distinctSubseqII(string s) {

        // unordered_set<string> st;
        // string ans="";

        // int n=s.length();
        // vector<int> dp(n,-1);

        // solve(s,0,st,ans);

        //  return st.size()%MOD;

        // return distinctSubseq(s);

        int n=s.length();
        memset(dp,-1,sizeof(dp));
        prev.assign(n+1,0);

        vector<int> lastSeen(26,0);

        for(int i=1;i<=n;i++){
            int idx=s[i-1]-'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx]=i;
        }

        return (solve(n)-1 + MOD)%MOD;
        
    }
};