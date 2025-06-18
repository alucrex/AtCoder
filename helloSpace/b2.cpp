#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;
using PL = pair<ll,ll>;
using PD = pair<double,double>;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vP = vector<P>;
using p_q = priority_queue<int, vi, greater<int>>;
const int INF = 1001001001;
const ll LINF = (1ll<<62) + ((1ll<<62)-1);
#define v(n) vector<n>
#define vv(n) vector<vector<n>>
#define vvv(n) vector<vector<vector<n>>>
#define p_q(n) priority_queue<(n), v(n), greater<n>>
#define line cout << "================================" << endl;
#define Yn(x) ((x) ? "Yes" : "No")
#define yn(x) ((x) ? "yes" : "no")
#define mmax(a,b) a = max(a,b)
#define mmin(a,b) a = min(a,b)
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define outs(x) cout << #x << endl;
#define mod(n,x) ((n)%(x))
#define all(a) (a).begin(),(a).end()

class alucrex{
    public:
    void vin(vi& a){rep(i,a.size())cin>>a[i];}
    void vvin(vvi& a){rep(i,a.size())rep(j,a[i].size())cin>>a[i][j];}
    void vvdes(vvi& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    void vinl(vl& a){rep(i,a.size())cin>>a[i];}
    void vvinl(vvl& a){rep(i,a.size())rep(j,a[i].size())cin>>a[i][j];}
    void vvdesl(vvl& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    void vpin(vP& a){for(auto& x:a)cin>>x.first>>x.second;}
    template<typename T>
    void vvd(vv(T)& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
};

class fraction{
    ll rui(ll n, ll r){
        ll res = 1;
        for(int i = 0 ; i < r ; i++)res *= n;
        return res;
    }
    ll euclidean(ll n, ll m){//n>m
        n = abs(n);
        m = abs(m);
        if(n < m)swap(n,m);
        while(n % m != 0){
            n %= m;
            swap(n,m);
        }
        return m;
    }
    fraction make_f(ll n, ll m){
        fraction res(n,m);
        return res;
    }
    public:
        /*コンストラクタ*/
        fraction(){}
        fraction(ll numerator,ll denominator){
            n = numerator;
            d = denominator;
            if(d < 0){
                n *= -1;
                d *= -1;
            }
        }
        fraction(string num){
            string s = num;
            string numerator;
            ll denominator = 0;
            for(int i = 0 ; i < s.size() ; i++){
                if(s[i] == '.'){
                    numerator += s.substr(0,i);
                    i++;
                    denominator = s.size() - i;
                    numerator += s.substr(i);
                    break;
                }
            }
            n = stol(numerator);
            d = rui(10,denominator);
            yakubun();
        }
        fraction(const fraction& old){
            n = old.n;
            d = old.d;
            yakubun();
        }

        fraction yakubun(){
            if(d == 0){
                puts("分母に0が代入されています");
                return make_f(-1,1);
            }
            if(d < 0){
                d *= -1;
                n *= -1;
            }
            if(n == 0)return make_f(n,d);

            ll gcm = euclidean(n,d);
            n /= gcm;
            d /= gcm;
            return make_f(n,d);
        }

        
        ll n = 1;  //numerator(子)
        ll d = 1;  //denominator(母)
        
/*オーバーロード地獄*/
        fraction operator + (const fraction& a){
            fraction res;
            res.n = this->n * a.d + a.n * this->d;
            res.d = this->d * a.d;
            res.yakubun();
            return res;
        }
        fraction operator - (const fraction& a){
            fraction res;
            res.n = this->n * a.d - a.n * this->d;
            res.d = this->d * a.d;
            res.yakubun();
            return res;
        }
        fraction operator * (const fraction& a){
            fraction res;
            res.n = this->n * a.n;
            res.d = this->d * a.d;
            res.yakubun();
            return res;
        }
        fraction operator / (const fraction& a){
            fraction res;
            res.n = this->n * a.d;
            res.d = this->d * a.n;
            res.yakubun();
            return res;
        }
        fraction operator + (ll a){
            fraction res = *this;
            res.n += res.d * a;
            return res;
        }
        fraction operator - (ll a){
            fraction res = *this;
            res.n -= res.d * a;
            return res;
        }
        fraction operator * (ll a){
            fraction res = *this;
            res.n *= a;
            res.yakubun();
            return res;
        }
        fraction operator / (ll a){
            fraction res = *this;
            res.d *= a;
            res.yakubun();
            return res;
        }
        fraction operator ++ (){
            n += d;
            return *this;
        }
        fraction operator -- (){
            n -= d;
            return *this;
        }
        bool operator == (fraction& a){
            ll compa, compb;
            this->yakubun(); a.yakubun();
            return (this->n == a.n && this->d == a.d);
        }
        bool operator != (fraction& a){
            ll compa, compb;
            this->yakubun(); a.yakubun();
            return !(this->n == a.n && this->d == a.d);
        }
        bool operator == (ll a){
            ll compa, compb;
            this->yakubun();
            return (this->d == 1 && this->n == a);
        }
        bool operator != (ll a){
            ll compa, compb;
            this->yakubun();
            return !(this->d == 1 && this->n == a);
        }
        void operator += (const fraction& a){
            *this = *this + a;
        }
        void operator -= (const fraction& a){
            *this = *this - a;
        }
        void operator *= (const fraction& a){
            *this = *this * a;
        }
        void operator /= (const fraction& a){
            *this = *this / a;
        }
        void operator += (ll a){
            *this = *this + a;
        }
        void operator -= (ll a){
            *this = *this - a;
        }
        void operator *= (ll a){
            *this = *this * a;
        }
        void operator /= (ll a){
            *this = *this / a;
        }
};
fraction operator + (ll a, const fraction& b){
    fraction res(b);
    res += a;
    return res;
}
fraction operator - (ll a, const fraction& b){
    fraction res(b);
    res -= a;
    return res;
}
fraction operator * (ll a, const fraction& b){
    fraction res(b);
    res *= a;
    res.yakubun();
    return res;
}
fraction operator / (ll a, const fraction& b){
    fraction res(b);
    res /= a;
    res.yakubun();
    return res;
}
bool operator < (fraction& a, fraction& b){
    // a.yakubun();b.yakubun();
    ll compa, compb;
    compa = a.n * b.d;
    compb = b.n * a.d;
    return compa < compb;
}
bool operator > (fraction& a, fraction& b){
    a.yakubun();b.yakubun();
    ll compa, compb;
    compa = a.n * b.d;
    compb = b.n * a.d;
    return compa > compb;
}
bool operator <= (fraction& a, fraction& b){
    a.yakubun();b.yakubun();
    ll compa, compb;
    compa = a.n * b.d;
    compb = b.n * a.d;
    return compa <= compb;
}
bool operator >= (fraction& a, fraction& b){
    a.yakubun();b.yakubun();
    ll compa, compb;
    compa = a.n * b.d;
    compb = b.n * a.d;
    return compa >= compb;
}
ostream& operator<<(ostream& os, fraction a){
    if(a.d < 0){
        a.n *= -1;
        a.d *= -1;
    }
    if(a.d == 1)os << a.n;
    else os << a.n << " / " << a.d;
    return os;
}
/*ここまで*/
namespace bunsu{
    double tod(const fraction& a){//fraction -> double
        return (double)a.n/a.d;
    }
    long double told(const fraction& a){//fraction -> long double
        return (long double)a.n/a.d;
    }
    fraction make_fraction(ll n, ll m){//make_pairのノリ
        fraction res(n,m);
        return res;
    }
};

int main(){
    alucrex al;
    int n, h, d; cin >> n >> d >> h;
    fraction ans(1,-INF);
    rep(i,n){
        fraction f; cin >> f.d >> f.n;
        if(ans < f) ans = f;
    }
    double res = h - d * (long double)(h - ans.n) / (d - ans.d);
    
    printf("%.10lf\n",res < 0 ? 0.0 : res);

}