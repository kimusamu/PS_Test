// BOJ 17478

#include <iostream>
#include <string>

using namespace std;

int cnt;

void chat(string str, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "____";
	}

	cout << str;
}

void bot(int n)
{
	chat("\"����Լ��� ������?\"\n", n);

	if (n == cnt)
	{
		chat("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", n);
	}

	else
	{
		chat("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", n);
		chat("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", n);
		chat("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", n);
		bot(n + 1);
	}

	chat("��� �亯�Ͽ���.\n", n);
}

int main()
{
	cin >> cnt;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	
	bot(0);
}