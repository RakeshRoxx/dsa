class Solution {
private:
	unordered_map<string, int> graph;
	vector<vector<string>> ans;
	string begin;


	void dfs(string start, vector<string> &osf) {
		if (start == begin) {
			reverse(osf.begin(), osf.end());
			ans.push_back(osf);
			reverse(osf.begin(), osf.end());
			return;
		}

		int sz = start.size();
		int steps = graph[start];
		for (int i = 0; i < sz; i++) {
			char ori = start[i];
			for (char ch = 'a'; ch <= 'z'; ch++) {
				start[i] = ch;
				if (graph.find(start) != graph.end() and graph[start] + 1 == steps) {
					osf.push_back(start);
					dfs(start, osf);
					osf.pop_back();
				}
			}
			start[i] = ori;
		}
	}



public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> list(wordList.begin(), wordList.end());
		// if(list.find(endWord) == list.end()) return ans;
		begin = beginWord;
		queue<string> q;
		q.push(beginWord);
		graph[beginWord] = 1;
		int sz = beginWord.size();
		while (not q.empty()) {
			string word = q.front(); q.pop();
			int steps = graph[word];
			for (int i = 0; i < sz; i++) {
				char ori = word[i];
				for (char ch = 'a'; ch <= 'z'; ch++) {
					word[i] = ch;
					if (word == beginWord) continue;
					if (list.find(word) != list.end()) {
						q.push(word);
						graph[word] = steps + 1;
						list.erase(word);
					}
				}
				word[i] = ori;
			}
		}
		vector<string> osf;
		// for(auto &it : graph){
		//     cout << it.first << " " << it.second << "\n";
		// }
		osf.push_back(endWord);
		if (graph.find(endWord) != graph.end()) {
			dfs(endWord, osf);
		}
		return ans;
	}
};