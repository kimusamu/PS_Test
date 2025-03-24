#include "practice.h"

/*
string preorder(const vector<int>& nodes, int idx)
{
	if (idx < nodes.size())
	{
		string ret = to_string(nodes[idx]) + " ";
		ret += preorder(nodes, idx * 2 + 1);
		ret += preorder(nodes, idx * 2 + 2);

		return ret;
	}

	return "";
}

string inorder(const vector<int>& nodes, int idx)
{
	if (idx < nodes.size())
	{
		string ret = inorder(nodes, idx * 2 + 1);
		ret += to_string(nodes[idx]) + " ";
		ret += inorder(nodes, idx * 2 + 2);

		return ret;
	}

	return "";
}

string postorder(const vector<int>& nodes, int idx)
{
	if (idx < nodes.size())
	{
		string ret = postorder(nodes, idx * 2 + 1);
		ret += postorder(nodes, idx * 2 + 2);
		ret += to_string(nodes[idx]) + " ";

		return ret;
	}

	return "";
}

vector<string> solution(vector<int> nodes)
{
	vector<string> result;
	string pre = preorder(nodes, 0);
	string in = inorder(nodes, 0);
	string post = postorder(nodes, 0);

	pre.pop_back();
	in.pop_back();
	post.pop_back();

	result.push_back(pre);
	result.push_back(in);
	result.push_back(post);

	return result;

}
*/

/*
class Node
{
public:
	int val;
	Node* left, * right;

	Node(int key) : val(key), left(nullptr), right(nullptr){}
};

class BST
{
private:
	Node* root;

	Node* insertNode(Node* node, int key)
	{
		if (!node)
		{
			return new Node(key);
		}

		if (key < node->val)
		{
			node->left = insertNode(node->left, key);
		}

		else
		{
			node->right = insertNode(node->right, key);
		}

		return node;
	}

	bool searchNode(Node* node, int key)
	{
		if (!node)
		{
			return false;
		}

		if (key == node->val)
		{
			return true;
		}

		return key < node->val ? searchNode(node->left, key) : searchNode(node->right, key);
	}

public:
	BST() : root(nullptr) {}

	void insert(int key)
	{
		root = insertNode(root, key);
	}

	bool search(int key)
	{
		return searchNode(root, key);
	}
};

vector<bool> solution(vector<int> lst, vector<int> search_lst)
{
	BST bst;

	for (int key : lst)
	{
		bst.insert(key);
	}

	vector<bool> result;

	for (int search_val : search_lst)
	{
		result.push_back(bst.search(search_val));
	}

	return result;
}
*/

/*
int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b)
	{
		a = (a + 1) / 2;
		b = (b + 1) / 2;

		++answer;
	}

	return answer;
}
*/

/*
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	unordered_map<string, string> parent;

	for (size_t i = 0; i < enroll.size(); ++i)
	{
		parent[enroll[i]] = referral[i];
	}

	unordered_map<string, int> total;

	for (const auto& name : enroll)
	{
		total[name] = 0;
	}

	for (size_t i = 0; i < seller.size(); ++i)
	{
		int money = amount[i] * 100;
		string cur_name = seller[i];

		while (money > 0 && cur_name != "-")
		{
			int to_distribute = money / 10;
			total[cur_name] += money - to_distribute;

			if (parent.find(cur_name) != parent.end())
			{
				cur_name = parent[cur_name];
			}

			else
			{
				break;
			}

			money = to_distribute;
		}
	}

	vector<int> result;
	result.reserve(enroll.size());

	for (const auto& name : enroll)
	{
		result.push_back(total[name]);
	}

	return result;
}
*/

/*
struct Node
{
	int id, x, y;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

class BinaryTree
{
private:
	Node* root = nullptr;

	static bool compareNodes(Node* a, Node* b)
	{
		if (a->y != b->y)
		{
			return a->y > b->y;
		}

		return a->x < b->x;
	}

	Node* addNode(Node* current, Node* newNode)
	{
		if (current == nullptr)
		{
			return newNode;
		}

		if (newNode->x < current->x)
		{
			current->left = addNode(current->left, newNode);
		}

		else
		{
			current->right = addNode(current->right, newNode);
		}

		return current;
	}

	void preOrder(Node* node, vector<int>& travelsal)
	{
		if (node == nullptr)
		{
			return;
		}

		travelsal.push_back(node->id);
		preOrder(node->left, travelsal);
		preOrder(node->right, travelsal);
	}

	void postOrder(Node* node, vector<int>& travelsal)
	{
		if (node == nullptr)
		{
			return;
		}

		postOrder(node->left, travelsal);
		postOrder(node->right, travelsal);
		travelsal.push_back(node->id);
	}

public:
	BinaryTree() : root(nullptr) {}

	void buildTree(const vector<vector<int>>& nodeInfo)
	{
		vector<Node*> nodes;

		for (int i = 0; i < nodeInfo.size(); ++i)
		{
			nodes.push_back(new Node(i + 1, nodeInfo[i][0], nodeInfo[i][1]));
		}

		sort(nodes.begin(), nodes.end(), compareNodes);

		for (Node* node : nodes)
		{
			root = addNode(root, node);
		}
	}

	vector<int> getPreOrderTravelsal()
	{
		vector<int> travelsal;

		preOrder(root, travelsal);

		return travelsal;
	}

	vector<int> getPostOrderTravelsal()
	{
		vector<int> travelsal;

		postOrder(root, travelsal);

		return travelsal;
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	BinaryTree tree;

	tree.buildTree(nodeinfo);

	vector<int> preOrder = tree.getPreOrderTravelsal();
	vector<int> postOrder = tree.getPostOrderTravelsal();

	return { preOrder, postOrder };
}
*/

/*
vector<int> parents;

int charToInt(char c)
{
	return c - '0';
}

int find(int x)
{
	if (parents[x] == x)
	{
		return x;
	}

	return find(parents[x]);
}

void unionSet(int x, int y)
{
	int root1 = find(x);
	int root2 = find(y);

	if (root1 != root2)
	{
		parents[root1] = root2;
	}
}

vector<bool> solution(int k, vector<vector<char>> operations)
{
	parents.resize(k);

	for (int i = 0; i < k; ++i)
	{
		parents[i] = i;
	}

	vector<bool> result;

	for (const auto& op : operations)
	{
		if (op[0] == 'u')
		{
			int x = charToInt(op[1]);
			int y = charToInt(op[2]);
			unionSet(x, y);
		}

		else if(op[0] == 'f')
		{
			int x = charToInt(op[1]);
			int y = charToInt(op[2]);

			result.push_back(find(x) == find(y));
		}
	}

	return result;
}
*/

/*
int solution(vector<int> nums)
{
	unordered_set<int> s(nums.begin(), nums.end());

	return min(nums.size() / 2, s.size());
}
*/

class DisjointSet
{
private:
	vector<int> parent, rank;

public:
	DisjointSet(int size) : parent(size, -1), rank(size, 0) {}

	int find(int node)
	{
		if (parent[node] == -1)
		{
			return node;
		}

		return parent[node] = find(parent[node]);
	}

	void merge(int node1, int node2)
	{
		int root1 = find(node1);
		int root2 = find(node2);

		if (root1 != root2)
		{
			if (rank[root1] > rank[root2])
			{
				parent[root2] = root1;
			}

			else if (rank[root1] < rank[root2])
			{
				parent[root1] = root2;
			}

			else
			{
				parent[root2] = root1;
				rank[root1]++;
			}
		}
	}

	bool isCycle(int node1, int node2) { return find(node1) == find(node2); }
};

int solution(int n, vector<vector<int>> costs) {
	sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2]; });

	DisjointSet disjointset(n);

	int total = 0;

	for (const auto& edge : costs)
	{
		int cost = edge[2];
		int node1 = edge[0];
		int node2 = edge[1];

		if (!disjointset.isCycle(node1, node2))
		{
			disjointset.merge(node1, node2);
			total += cost;
		}
	}

	return total;
}