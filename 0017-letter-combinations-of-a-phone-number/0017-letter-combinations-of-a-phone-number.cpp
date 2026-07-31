class Solution {

    void solve(string digits,vector<string> &ans,string output,int index,string mappings[]){

            if(index>=digits.length()){
                ans.push_back(output);
                return;
            }


            int number=digits[index]-'0';
            string value=mappings[number];

            for(int i=0;i<value.length();i++){
                output.push_back(value[i]);
                solve(digits,ans,output,index+1,mappings);
                output.pop_back();
            }
    }
public:
    vector<string> letterCombinations(string digits) {
       
        vector<string> ans;

        if(digits.length()==0){
            return ans;
        }
        
        string output = "";

        string mappings[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits,ans,output,0,mappings);

        return ans;
    }
};