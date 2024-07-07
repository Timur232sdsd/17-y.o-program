#include<bits/stdc++.h>
using namespace std;
#define d(x) cout << #x << " = " << x << "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using ll = long long;
using ld = long double;
ll const mod = ll(1e9+7);
ll binpow(ll n, ll k) {
if(n==1) return 1LL;
if(k==0) return 1LL;
if(n==0) return 0LL;
if(k%2==0) return (binpow(n*n%mod,k/2)%mod);
return (n*binpow(n*n%mod,k/2)%mod);
}

void solve() {
int n=11,m=16;
vector<vector<int>> vec(n,vector<int>(m,0));
for(int i=1;i<n;i++) {
    for(int j=1;j<m;j++) {
        if((i+j)%5==3) vec[i][j]=1;
        if((i+j)%4==2) vec[i][j]=2;
        if((i+j)%3==1) vec[i][j]=3;
    }
}
int cnt=0,cnt1=0;
for(int i=1;i<n;i++) {
    for(int j=1;j<m;j++) {
        cnt1++;
        if(vec[i][j]==2) cnt++;
    }
}
cout << cnt <<" " << cnt1;
}


int main() {
fast;
solve();
}
