#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> //setprecision
using namespace std;

#define line cout << "=========================================" << endl;
#define WIDTH 8
#define BLACK 0
#define WHITE 1
#define BLANK 2
#define debug(x) cout << #x" : " << x << endl;

vector<vector<int>> field(WIDTH, vector<int>(WIDTH, BLANK));
struct count_stone {
	int black = 0;
	int white = 0;
	int blank = WIDTH * WIDTH;

	void Re() {
		int b = 0, w = 0;
		for (auto t : field) for (auto u : t) {
			if (u == BLACK) b++;
			else if (u == WHITE) w++;
		}
		black = b;
		white = w;
		blank = WIDTH * WIDTH - b - w;
	}

	count_stone() {
		int b = 0, w = 0;
		for (auto t : field) for (auto u : t) {
			if (u == BLACK) b++;
			else if (u == WHITE) w++;
		}
		black = b;
		white = w;
		blank = WIDTH * WIDTH - b - w;
	}
};


struct graph {
	int x;
	int y;

	graph(int X, int Y) : x(X), y(Y) {};
	graph() : x(0), y(0) {};

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
};
bool operator < (const graph& a, const graph& b) {
	if (a.y < b.y) return true;
	else if (a.y == b.y) return a.x < b.x;
	else return false;
}
bool operator <= (const graph& a, const graph& b) {
	if (a.y < b.y) return true;
	else if (a.y == b.y) return a.x <= b.x;
	else return false;
}
bool operator > (const graph& a, const graph& b) {
	if (a.y > b.y) return true;
	else if (a.y == b.y) return a.x > b.x;
	else return false;
}
bool operator >= (const graph& a, const graph& b) {
	if (a.y > b.y) return true;
	else if (a.y == b.y) return a.x >= b.x;
	else return false;
}
ostream& operator<< (ostream& os, graph a) {
	return os << "( " << a.x + 1 << " , " << a.y + 1 << " )";
}


void des() {
	cout << "   ";
	for (char i = 'A'; i <= 'A' + WIDTH - 1; i++) {
		cout << i << "   ";
	}puts("");

	cout << "   ";
	for (int i = 1; i <= WIDTH; i++) {
		cout << i << "   ";
	}puts("");

	for (int i = 0; i < WIDTH; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < WIDTH; j++) {
			cout << " " << (field[i][j] == BLANK ? "　" : (field[i][j] == BLACK ? "○" : "●"));
			cout << "│";
		}
		puts(""); cout << "  ";
		for (int i = 0; i < WIDTH; i++) cout << " ─ ─"; puts("");
	}
}

graph input() {//0-> BLACK 1-> WHITE 2-> BLANK
	string s; cin >> s;
	if (s == "quit") return graph(-2, -2);

	char x_, y_;
	if (s.size() == 2) x_ = s[0], y_ = s[1];
	else if (s.size() == 1) { x_ = s[0], y_; cin >> y_; }
	else return graph(-1, -1);

	int x, y;

	if (x_ >= 'A' && x_ <= 'H') x = x_ - 'A';
	else if (x_ >= 'a' && x_ <= 'h') x = x_ - 'a';
	else if (x_ >= '1' && x_ <= '8') x = x_ - '1';
	else x = -1;

	y = y_ - '1';

	if (x < 0 || y < 0 || x >= WIDTH || y >= WIDTH) {
		cout << "illegal number" << endl;
		return graph(-1, -1);
	}
	return graph(x, y);
}

void change(graph& now) {
	switch (field[now.y][now.x]) {
	case BLACK:
		field[now.y][now.x] = WHITE;
		break;
	case WHITE:
		field[now.y][now.x] = BLACK;
		break;
	case BLANK:
		field[now.y][now.x] = BLANK;
		break;
	}
}

const vector<graph> direct = {
	graph(-1, -1),
	graph(-1, 0),
	graph(-1, 1),
	graph(0, -1),
	graph(0, 1),
	graph(1, -1),
	graph(1, 0),
	graph(1, 1)
};

bool dfs(graph now, graph t) { //now , direct
	graph to = now + t;

	if (to.x < 0 || to.y < 0 || to.x >= WIDTH || to.y >= WIDTH || field[to.y][to.x] == BLANK) return false;

	if (field[now.y][now.x] == field[to.y][to.x]) {
		if (!dfs(to, t)) return false;
	}
	change(now);
	return true;
}
bool is_ok(graph now, graph t) {
	graph to = now + t;
	if (to.x < 0 || to.y < 0 || to.x >= WIDTH || to.y >= WIDTH || field[to.y][to.x] == BLANK) return false;

	if (field[now.y][now.x] == field[to.y][to.x]) {
		if (!is_ok(to, t)) return false;
	}
	return true;
}

int main() {
	field[3][3] = WHITE;
	field[3][4] = BLACK;
	field[4][3] = BLACK;
	field[4][4] = WHITE;
	count_stone cnt;
	vector<graph> history;


	des();

	int put_limit = 0;
	for (int turn = 0; ; turn++) {
		/*決着*/
		if (!cnt.blank || !cnt.black || !cnt.white) break;


		if (turn % 2 == BLACK) puts("turn : black");
		else puts("turn : white");

		/*置ける場所があるか*/
		bool is_put = 0;
		set<graph> option;
		cout << "option : ";
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < WIDTH; j++) {
				graph a(j, i);

				if (field[a.y][a.x] == BLANK) for (auto u : direct) {
					graph to = a + u;
					if (to.x < 0 || to.y < 0 || to.x >= WIDTH || to.y >= WIDTH || field[to.y][to.x] == (turn % 2) || field[to.y][to.x] == BLANK) continue;
					if (is_ok(to, u)) {
						cout << a << "  ";
						option.insert(a);
						is_put = 1;
						put_limit = 0;
						break;
					}
				}
			}
		}puts("");

		if (put_limit >= 2) {
			puts("両者ともにおける場所ななくなったためゲームを終了します");
			break;
		}
		if (!is_put) {
			put_limit++;
			puts("置ける場所がないのでスキップされます");
			history.push_back(graph(-1, -1));
			continue;
		}

		/*座標を入力*/
		graph currentP;
		int is_player_put = 0;
		while (!is_player_put) {
			graph a = input();
			if (a.x == -1) {
				puts("Do you really you wanna quit?");
				puts("press[y or 1] or [n or 0]");
				string s; cin >> s;
				if (s == "y" || s == "Y" || s == "1") return 1;
				else {
					puts("その位置には置けません");
					continue;
				}
			}
			else if (a.x == -2) return 1;

			/*核心*/
			if (option.count(a)) {
				field[a.y][a.x] = (turn % 2 == BLACK ? BLACK : WHITE);
				currentP = a;
				history.push_back(a);
				is_player_put = 1;
			}
			else {
				cout << "その位置には置けません" << endl;
			}
		}


		/*八方位DFS*/
		for (auto u : direct) {
			graph to = currentP + u;

			if (to.x < 0 || to.y < 0 || to.x >= WIDTH || to.y >= WIDTH || field[currentP.y][currentP.x] == field[to.y][to.x] || field[to.y][to.x] == BLANK) continue;

			dfs(to, u);

		}
		cnt.Re();
		des();
	}line

	des();

	puts("ゲームが終了しました");
	puts("〜結果〜");
	cout << "黒：" << cnt.black << "個" << endl;
	cout << "白：" << cnt.white << "個" << endl;
	if (cnt.black == cnt.white) puts("によって引き分けです");
	else cout << "によって" << (cnt.black > cnt.white ? "黒" : "白") << "の勝利です" << endl;
	/*棋譜*/
	puts("棋譜：");
	int i = 1;
	for (auto u : history) {
		cout << i << " : ";
		if (u.x == -1) puts("passed");
		else cout << char('A' + u.x) << u.y + 1 << endl;
		i++;
	}
}