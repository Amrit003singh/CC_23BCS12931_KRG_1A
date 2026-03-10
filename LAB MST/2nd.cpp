#include <iostream>
#include<vector>
using namespace std;

int maxProduct(const vector<string>& words){
	int n = words.size();
	vector<int> mask(n,0), len(n,0);
	for(int i=0;i<n;++i){
		int m = 0;
		for(char c: words[i]) m |= 1 << (c - 'a');
		mask[i] = m;
		len[i] = words[i].size();
	}

	int ans = 0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if((mask[i] & mask[j]) == 0){
				ans = max(ans, len[i] * len[j]);
			}
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> words;

	string first;
	if(!(cin >> first)){
		words = {"abcw","baz","foo","bar","xtfn","abcdef"};
		cout << maxProduct(words) << '\n';
		return 0;
	}

	bool isNumber = true;
	for(char c: first) if(!isdigit(c) && c!='+' && c!='-') { isNumber = false; break; }

	if(isNumber){
		int n = stoi(first);
		words.reserve(n);
		for(int i=0;i<n;++i){ string w; cin >> w; words.push_back(w); }
	} else {
		words.push_back(first);
		string w;
		while(cin >> w) words.push_back(w);
	}

	cout << maxProduct(words) << '\n';
	return 0;
}

