class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(a==b && b==c && c==a) return "equilateral";
        if(a+b<=c || b+c<=a || c+a<=b) return "none";
        if(a+b>c && b+c>a && c+a>b && a!=b && b!=c && c!=a) return "scalene";
        if(a+b>c && b+c>a && c+a>b && ((a==b && b!=c && c!=a)|| (a!=b && b==c && c!=a) || (a!=b && b!=c && c==a))) return "isosceles";

        return  "none";

    }
};