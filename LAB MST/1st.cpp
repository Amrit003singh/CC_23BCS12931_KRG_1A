#include <iostream>
#include <utility>
#include<vector>
using ll = long long;
using namespace std;


ll minInitialEnergy(vector<pair<ll,ll>> &tasks){
	sort(tasks.begin(), tasks.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
		ll da = a.second - a.first;
		ll db = b.second - b.first;
		if(da != db) return da > db;
		return a.second > b.second;
	});

	ll need = 0, cur = 0;
	for(auto &t : tasks){
		ll act = t.first, minreq = t.second;
		if(cur < minreq){
			need += (minreq - cur);
			cur = minreq;
		}
		cur -= act;
	}
	return need;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	if(!(cin >> n)){
	
		vector<pair<ll,ll>> tasks = {{1,2},{2,4},{3,2}};
		cout << minInitialEnergy(tasks)<<endl;
		return 0;
	}

	vector<pair<ll,ll>> tasks;
	for(int i = 0; i < n; ++i){
		ll act, minreq;
		cin >> act >> minreq;
		tasks.emplace_back(act, minreq);
	}

	cout << minInitialEnergy(tasks)<<endl;
	return 0;
}

