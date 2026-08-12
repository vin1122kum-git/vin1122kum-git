class Solution {
public:
string solve(string num,int k){

    string ans= "";

    for(auto &it:num){

            int temp = it - '0';
          
          while(k>0 && ans.length()>0 && ans.back()-'0'>temp){
              ans.pop_back();
                k--;
          }

          ans.push_back(it);
    }

    //if k is still there

    while(k>0){
        ans.pop_back();
        k--;
    }

    // remove leading zeroes

    int i=0;

    while(i<ans.length()-1 && ans[i]=='0'){
        i++;
    }

  return ans.substr(i);

}
    string removeKdigits(string num, int k) {

        if(num.length()==k) return "0";

        return solve(num,k);
        
    }
};