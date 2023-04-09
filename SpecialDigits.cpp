//https://practice.geeksforgeeks.org/problems/7a3e0427cbb1ea9fbfec499dc6fce377ffdf7aed/1
#define ll long long
    ll mod = 1e9+7LL;
    bool check(ll sum,int &C,int &D){
        while(sum){
            if((sum % 10) != C && (sum % 10) != D){
                return false;
            }
            sum /= 10;
        }
        return true;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        vector<ll>fact(N+1,1),invfact(N+1),inv(N+1);
        for(ll i = 2; i <= N; i++){
            fact[i] = (fact[i-1] * i) % mod;
        }
        inv[1] = inv[0] = 1LL;
        for(ll i = 2; i <= N; i++){
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        }
        invfact[0] = invfact[1] = 1LL;
        for(ll i = 2; i <= N; i++){
            invfact[i] = (invfact[i-1] * inv[i]) % mod;
        }
        ll ans = 0;
        for(ll i = 0; i <= N; i++){
            if(check(i*A + B*(N-i),C,D)){
                ans += ((fact[N] * invfact[i]) % mod * invfact[N-i]) % mod;
                ans %= mod;
            }
        }
        return ans;
    }
