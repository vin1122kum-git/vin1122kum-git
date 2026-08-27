class Solution {
public:
    bool permutations(string &curr, vector<int>&count, string s,string target,int index,bool isGreater, string &result){

        if(index>=s.length()){
            if(isGreater){
                result=curr;
                return true;
            }

            return false;
        }

        for(char ch='a' ; ch<='z' ;ch++){
            
            if(count[ch-'a']==0) continue;

            if(isGreater==false && ch<target[index]) continue;

            curr.push_back(ch);
            count[ch-'a']--;

            bool greater = isGreater || ch>target[index];

            if(permutations(curr,count,s,target,index+1,greater,result)){
                return true;
            }

            curr.pop_back();
            count[ch-'a']++;
        }

        return false;


    }

    string lexGreaterPermutation(string s, string target) {

       vector<int> count(26,0);

       for(auto &it:s){
            count[it-'a']++;
       }

        string curr;
        string result="";

        permutations(curr,count,s,target,0,false,result);

        return result;

    }
};