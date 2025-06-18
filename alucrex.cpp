#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
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
template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using p_q = priority_queue<T, v<T>, greater<T>>;
const int INF = 1001001001;
const int INTMAX = (1ll<<31)-1;
const ll LINF = (1ll<<62);
const ll LLMAX = (1ll<<62) + ((1ll<<62)-1);
#define line cout << "================================" << endl;
#define Yn(x) ((x) ? "Yes" : "No")
#define yn(x) ((x) ? "yes" : "no")
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define outs(x) cout << #x << endl;
#define mod(n) %(n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define m_p(a, b) make_pair(a, b)
#define set_time(x) steady_clock::time_point (x) = steady_clock::now()
#define p_time(x) duration_cast<milliseconds>(x).count()
#define show_time(s, e) cout << "実行時間" << duration_cast<milliseconds>(e-s).count() << "ms\n"
template <typename T> bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
template <typename T> bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
ostream& operator<< (ostream& os, P a) {return os << a.first << " , " << a.second;}

class alucrex{
    public:
    void vin(vi& a){for(auto& i:a)cin>>i;}
    void vin(vl& a){for(auto& i:a)cin>>i;}
    template<typename T> void vin(T& a){for(auto& i:a)cint>>i;}
    void vin1(vi& a){rep1(i,a.size()-1)cin>>a[i];}
    void vvin(vvi& a){for(auto& i:a)for(auto& j:i)cin>>j;}
    void vvin(vvl& a){for(auto& i:a)for(auto& j:i)cin>>j;}
    void vvdes(vvi& a){for(auto& i:a){for(auto& j:i){
        cout << j << " ";}puts("");
    }}
    void vvdes(vvl& a){for(auto& i:a){for(auto& j:i){
        cout << j << " ";}puts("");
    }}
    void vpin(vP& a){for(auto& x:a)cin>>x.first>>x.second;}
    template<typename T>
    void vvd(vv<T>& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    bool TLE(steady_clock::time_point s, int time = 9800){
        steady_clock::time_point e = steady_clock::now();
        if(duration_cast<milliseconds>(e - s).count() >= time)return true;
        return false;
    }
    ll rui(ll n, int r, ll m = LLMAX) { //O(logR + のこり)
        n %= m;
        ll res = (r < 2 ? 1 : n);
        ll cnt = 1;
        if(r >= 2)for( ; cnt *2 <= r ; cnt *= 2) {
            res *= res;
            res %= m;
        }
        else cnt = 0;
        for(int i = 0 ; i < (r - cnt) ; i++) {res *= n; res %= m;}
        return res;
    }
    ll kai(ll n) { //O(N)
        ll res = 1;
        for(int i = 2 ; i <= n ; i++) res *= i;
        return res;
    }
};

struct graph {
    int x;
    int y;

    double dist(graph a, graph b) {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }

    graph(int a, int  b) : y(a), x(b) {}
    graph() {}

    graph operator+ (const graph& a) {
		graph res;
		res.x = this->x + a.x;
		res.y = this->y + a.y;
		return res;
	}
	graph operator- (const graph& a) {
		graph res;
		res.x = this->x - a.x;
		res.y = this->y - a.y;
		return res;
	}
	void operator+= (const graph& a) {
		*this = *this + a;
	}
    void operator-= (const graph& a) {
        *this = *this - a;
    }
};
bool operator< (const graph& a, const graph& b) {
    if(a.y < b.y) return true;
    if(a.y > b.y) return false;
    return a.x < b.x;
}
bool operator<= (const graph& a, const graph& b) {
    if(a.y < b.y) return true;
    if(a.y > b.y) return false;
    return a.x <= b.x;
}
bool operator> (const graph& a, const graph& b) {
    if(a.y > b.y) return true;
    if(a.y < b.y) return false;
    return a.x > b.x;
}
bool operator>= (const graph& a, const graph& b) {
    if(a.y > b.y) return true;
    if(a.y < b.y) return false;
    return a.x >= b.x;
}
ostream& operator<< (ostream& os, const graph& a) {
	return os << "( " << a.x << " , " << a.y << " )";
}


// ll surplus ;
// struct mmod{
//     ll culP(ll a, ll b){
//         ll res;
//         res = mod(a,surplus) + mod(b,surplus);
//         res %= surplus;
//         return res;
//     }
//     ll culM(ll a, ll b){
//         ll res;
//         res = mod(a,surplus) - mod(b,surplus);
//         res %= surplus;
//         while(res >= 0){
//             res += surplus;
//         }
//         return res;
//     }
//     ll culX(ll a, ll b){
//         ll res;
//         res = mod(a,surplus) * mod(b,surplus);
//     }
//     ll culD(ll a, ll b){
//         ll res;
//         ll(a);
//         if(b == 0){
//             cout << "xxxxxxxxxxxxx" << endl;
//             return -1;
//         }
//         while(mod(a,b) != 0){
//             a += surplus;
//         }
//         res = a / b;
//         res %= surplus;
//         return res;
//     }
//     ll rui(ll a, ll n){
//         ll res = 1;
//         for(ll i = 2 ; i <= n ; i++){
//             res *= i;
//             res %= surplus;
//         }
//         return res;
//     }
//     ll kai(ll a){
//         ll res = 1;
//         for(int i = a ; i >= 2 ; i--)res *= i;
//         return res;
//     }
//     ll combe(ll n, ll r){
//         ll left = 1, right = 1;
//         if(r == 0)return 1;
//         if(r > n/2)r = n - r;
//         for(ll i = 0 ; i < r ; i++){
//             left *= n-i;
//             right *= i+1;
//             left %= surplus;
//             right %= surplus;
//         }
//         return culD(left, right);
//     }
// };

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
    a.yakubun();b.yakubun();
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
namespace bunsu{
    double tod(const fraction& a){
        return (double)a.n/a.d;
    }
    long double told(const fraction& a){
        return (long double)a.n/a.d;
    }
    fraction make_fraction(ll n, ll m){
        fraction res(n,m);
        return res;
    }
};

using namespace bunsu;
int main(){
    alucrex al;
    fraction b(3,5), c(15,25);
    int a  = 2;
    cout << a + b << endl;
    if(c == a)cout << 1 << endl;
    v<fraction> vec(5);
    vec[0] = make_fraction(1,3);
    vec[1] = make_fraction(1,4);
    vec[2] = make_fraction(1,6);
    vec[3] = make_fraction(1,7);
    vec[4] = make_fraction(1,9);
    rep1(i,4)vec[0] += vec[i];
    cout << vec[0] << endl;
}