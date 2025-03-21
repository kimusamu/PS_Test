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

