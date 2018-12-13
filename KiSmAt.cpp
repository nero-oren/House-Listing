//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
const int N = 2 * 1e5 + 10;

ll a[N];

struct house{
	ll no_of_room;
	ll cost;
	string location;
	house() : no_of_room(), cost(), location(){}
	house(ll _n, ll _c, string _l) : no_of_room(_n), cost(_c), location(_l){}
};

vector<house> res;

struct BIT {
    vector<house> data[N];
    void update(ll idx, ll room, string loc) {
        while (idx < N) {
            data[idx].push_back(house(room, idx, loc));
            idx += idx & -idx;
        }
    }
    void query(ll idx) {
        while (idx > 0) {
        	for(int i = 0; i < data[idx].size(); ++i){
        		res.push_back(data[idx][i]);
        	}
            idx -= idx & -idx;
        }
    }
    void clear(){
    	for(int i = 0; i < N; ++i){
    		data[i].clear();
    	}
    }
};

void solve(){
	BIT nero;
	ll x, nr, cc;
	string s;
	cout << "Press 1 for customer\nPress 2 for Admin\nChoice : ";
	while(cin >> x){
		if(x - 1){
			cout << "Enter Details of New house created\nEnter no of rooms : ";
			cin >> nr;
			cout << "Enter cost of House : ";
			cin >> cc;
			cout << "Enter location of house : ";
			cin >> s;
			nero.update(cc, nr, s);
			cout << "Details Entered Sucessfully!!\n";
		}
		else{
		cout << "Enter your Budget : ";
			cout << cc;
			nero.query(cc); 
			cout << "List of houses under " << cc << "\n";
			cout << "S.no\tCost\tNo of rooms\tLocation\n";
			for(int i = 0; i < res.size(); ++i){
				cout << i + 1 << "\t" << res[i].cost << "\t" << res[i].no_of_room << "\t" << res[i].location << "\n";
			}
			res.clear();
		}
        cout << "Press 1 for customer\nPress 2 for Admin\nChoice : ";
	}
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
}
// nEro
