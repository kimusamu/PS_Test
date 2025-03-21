#include "practice.h"

/*
string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> hash;

	for (const auto& name : participant)
	{
		hash[name]++;
	}

	for (const auto& name : completion)
	{
		hash[name]--;

		if (hash[name] == 0)
		{
			hash.erase(name);
		}
	}

	return hash.begin()->first;
}
*/

/*
vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);
	unordered_set<string> usedword;

	usedword.insert(words[0]);

	for (int i = 0; i < words.size(); ++i)
	{
		if (!usedword.insert(words[i]).second || words[i].front() != words[i - 1].back())
		{
			answer[0] = i % n + 1;
			answer[0] = i / n + 1;

			return answer;
		}
	}

	return answer;
}
*/

/*
bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; ++i)
	{
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
		{
			return false;
		}
	}

	return true;
}
*/

/*
int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	unordered_map<string, int> want_number;

	for (int i = 0; i < want.size(); ++i)
	{
		want_number[want[i]] = number[i];
	}

	for (int i = 0; i < discount.size() - 9; ++i)
	{
		unordered_map<string, int> discount_number;

		for (int j = i; j < 10 + i; ++j)
		{
			discount_number[discount[j]]++;
		}

		if (want_number == discount_number)
		{
			++answer;
		}
	}

	return answer;
}
*/

/*
vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> uid;

	for (const auto& line : record)
	{
		stringstream ss;
		string cmd, id, name;

		ss >> cmd >> id;

		if (cmd != "Leave")
		{
			ss >> name;
			uid[id] = name;
		}
	}

	for (const auto& line : record)
	{
		stringstream ss;
		string cmd, id;

		ss >> cmd >> id;

		if (cmd == "Enter")
		{
			answer.push_back(uid[id] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}

		else if (cmd == "Leave")
		{
			answer.push_back(uid[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}

	return answer;
}
*/

/*
bool compare_genre(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second > b.second;
}

bool compare_song(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, vector<pair<int, int>>> genres_dict;
	unordered_map<string, int> play_dict;

	for (int i = 0; i < genres.size(); ++i)
	{
		genres_dict[genres[i]].push_back({ i, plays[i] });
		play_dict[genres[i]] += plays[i];
	}

	vector<pair<string, int>> sorted_genres(play_dict.begin(), play_dict.end());

	sort(sorted_genres.begin(), sorted_genres.end(), compare_genre);

	for (auto& genre : sorted_genres)
	{
		auto& songs = genres_dict[genre.first];

		sort(songs.begin(), songs.end(), compare_song);

		for (int i = 0; i < min(2, (int)songs.size()); ++i)
		{
			answer.push_back(songs[i].first);
		}
	}

	return answer;
}
*/

/*
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	unordered_map<string, unordered_set<string>> reported_user;
	unordered_map<string, int> count;

	for (string& r : report)
	{
		stringstream ss(r);
		string user_id, reported_id;

		ss >> user_id >> reported_id;

		reported_user[reported_id].insert(user_id);
	}

	for (auto& [reported_id, user_id_lst] : reported_user) {
		if (user_id_lst.size() >= k) {
			for (const string& uid : user_id_lst)
			{
				count[uid]++;
			}
		}
	}

	vector<int> answer;

	for (string& id : id_list)
	{
		answer.push_back(count[id]);
	}

	return answer;
}
*/

map<string, int> combi;

void combination(string src, string dst, int depth)
{
	if (dst.size() == depth)
	{
		combi[dst]++;
	}

	else for (int i = 0; i < src.size(); ++i)
	{
		combination(src.substr(i + 1), dst + src[i], depth);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (string& order : orders)
	{
		sort(order.begin(), order.end());
	}

	for (int len : course)
	{
		for (string order : orders)
		{
			combination(order, "", len);
		}

		int max_order = 0;

		for (auto it : combi)
		{
			max_order = max(max_order, it.second);
		}

		for (auto it : combi)
		{
			if (max_order >= 2 && it.second == max_order)
			{
				answer.push_back(it.first);
			}
		}

		combi.clear();
	}

	sort(answer.begin(), answer.end());

	return answer;
}