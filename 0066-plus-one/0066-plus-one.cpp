class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1; i>=0; i--){
            if(digits[i]<9){
                digits[i]++;  
                return digits; 
            }
            digits[i] = 0; //if 9
        }
        // If all digits were 9, we have carried all the way to the front
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning

        return digits;
    }
};