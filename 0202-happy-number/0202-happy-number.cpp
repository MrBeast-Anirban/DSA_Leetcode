class Solution {
public:
    bool isHappy(int n) {
        int turtle = getTheSumOfDigits(n);
        int rabbit = getTheSumOfDigits(getTheSumOfDigits(n));
        while(turtle != rabbit){
            if(rabbit == 1) return true;
            turtle = getTheSumOfDigits(turtle);
            rabbit = getTheSumOfDigits(getTheSumOfDigits(rabbit));
        }
        return turtle == 1;
    }
private:
    int getTheSumOfDigits(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};