class Solution {
public:
    int mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        int small = min(a,b), big=max(a,b);
        int LCM = (a*1ll*b)/__gcd(a,b);
        long long low = 1, high = n, ans = high;
        while(low<=high){
            long long mid = (low+high)>>1;
            long long total = mid+(small*mid)/big-(small*mid)/LCM;
            if(total == n)return (small*mid)%mod;
            else if(total > n){
                ans = mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return big*((ans*small)/big)%mod;
    }
};
