#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ";_print(x); cerr << endl;
#else
#define debug(x)
#endif

typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef map<ll,ll> mll;
typedef vector<pair<ll,ll>> vpll;
typedef tuple<ll,ll,ll> tll;
template<class T> void _print(vector<T> v){cerr << "[ ";for(T i : v){cerr << i << " ";}cerr << "]";}

void _print(int a){cerr << a << " ";}
void _print(long long a){cerr << a << " ";}
void _print(char a){cerr << a << " ";}
void _print(string a){cerr << a << " ";}
void _print(bool  a){cerr << a << " ";}

#define pb push_back
#define for0(i,n) for(ll i=0;i<n;i++)
#define MOD 1000000009
const int N=1e6+7;
ll rr[N];
void solve(){
    string s;
    cin >> s;
    ll count = 0;
    string a;
    cin >> a;
    // if(a.length()==1){
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]==a){
    //             count ++;
    //         }
    //     }
    //     return;
    // }
    // 19 + 1*29 + 9*841 + 16*24389 + 16*707281
    ll n = 1;
    int pow=29;
    ll aa = a.length();
    rr[0]=int(s[0])-int('a')+1;
    for(int i=1;i<s.length();i++){
        int k=int(s[i])-int('a')+1;
        n=(n*pow)%MOD;
        rr[i]=(rr[i-1]+k*n)%MOD;
    }
    int hash = 0;
    n=1;
    for(int i=0;i<a.length();i++){
        int k=int(a[i])-int('a')+1;
        hash=(hash+k*n)%MOD;
        n=(n*pow)%MOD;
    }
    // cout << hash << "\n";
    n=1;
    // cout << rr[2] << "\n";
    for(int i=0;i<s.length();i++){
        if(i+1>aa)n=(n*pow)%MOD;
        if(i+1<aa)continue;
        else{
            ll h=rr[i];
            // cout << i-aa << " ";
            // cout << h << " ";
            if(i-a.length()>=0)h=(h+MOD-rr[i-aa])%MOD;
            // cout << h << "\n";
            if((hash*n)%MOD==h){
                count++;
            }
            // cout << i << " " <<  n << " " << (hash*n)%MOD << " " << h << "\n";
        }

    }
    cout << count << "\n";
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
freopen("Error.txt","w",stderr);
#endif

int t=1;
while(t--){
    solve();
}
    
    return 0;
}