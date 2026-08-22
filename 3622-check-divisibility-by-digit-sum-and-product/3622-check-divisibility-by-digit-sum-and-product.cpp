class Solution {
public:
    bool checkDivisibility(int n) {

        int temp=n;

        int sumofDigits = 0 ;
        int product = 1;

        while(temp>0){
            int rem=temp%10;

            sumofDigits += rem;
            product*=rem;

            temp=temp/10;
        }
        
        return n%(sumofDigits+product) == 0 ? true : false;
        
    }
};