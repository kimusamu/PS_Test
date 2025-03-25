#include "practice.h"

/*
struct node_info
{
	int V;
	int W;
};

vector<vector<node_info>> adj_list;

void add_edge(int u, int v, int w)
{
	adj_list[u].push_back({ v, w });
}

void print_adj_list()
{
	for (int i = 0; i < adj_list.size(); i++)
	{
		cout << "Node : " << i << " : ";

		for (const auto& node : adj_list[i])
		{
			cout << " -> (V : " << node.V << ", W : " << node.W << ")";
		}

		cout << endl;
	}
}

int main()
{
	int N = 5;

	adj_list.resize(N);

	add_edge(1, 2, 3);
	add_edge(2, 1, 6);
	add_edge(2, 3, 5);
	add_edge(3, 2, 1);
	add_edge(3, 4, 13);
	add_edge(4, 4, 9);
	add_edge(4, 1, 42);

	print_adj_list();

	return 0;
}
*/

/*
unordered_map<char, vector<char>> adj_list;
unordered_set<char> visited;
vector<char> result;

void dfs(char node)
{
	visited.insert(node);
	result.push_back(node);

	for (char neighbor : adj_list[node])
	{
		if (visited.find(neighbor) == visited.end())
		{
			dfs(neighbor);
		}
	}
}

vector<char> solution(vector<pair<char, char>> graph, char start)
{
	for (auto& edge : graph)
	{
		char u = edge.first;
		char v = edge.second;

		adj_list[u].push_back(v);
	}

	dfs(start);
	return result;
}
*/

/*
unordered_map<int, vector<int>> adj_list;
vector<int> result;

void bfs(int start)
{
	unordered_set<int> visited;
	queue<int> q;

	q.push(start);
	visited.insert(start);
	result.push_back(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int neighbor : adj_list[node])
		{
			if (visited.find(neighbor) == visited.end())
			{
				q.push(neighbor);
				visited.insert(neighbor);
				result.push_back(neighbor);
			}
		}
	}
}

vector<int> solution(vector<pair<int, int>> graph, int start)
{
	for (auto& edge : graph)
	{
		int u = edge.first;
		int v = edge.second;

		adj_list[u].push_back(v);
	}

	bfs(start);

	return result;
}
*/

/*
const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int num_nodes, vector<tuple<int, int, int>> edges)
{
	for (int i = 0; i < MAX_NODES; ++i)
	{
		fill_n(graph[i], MAX_NODES, INF);
		visited[i] = false;
	}

	for (const auto& [from, to, weight] : edges)
	{
		graph[from][to] = weight;
	}

	vector<int> distances(num_nodes, INF);
	distances[start] = 0;

	for (int i = 0; i < num_nodes - 1; ++i)
	{
		int min_distance = INF;
		int closes_node = -1;

		for (int j = 0; j < num_nodes; ++j)
		{
			if (!visited[j] && distances[j] < min_distance)
			{
				min_distance = distances[j];
				closes_node = j;
			}
		}

		visited[closes_node] = true;

		for (int j = 0; j < num_nodes; ++j)
		{
			int new_distance = distances[closes_node] + graph[closes_node][j];

			if (!visited[j] && graph[closes_node][j] != INF && new_distance < distances[j])
			{
				distances[j] = new_distance;
			}
		}
	}

	return distances;
}
*/

/*
const int INF = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source)
{
	vector<vector<pair<int, int>>> graph(num_vertices);

	for (auto& edge : edges)
	{
		int from, to, weight;
		tie(from, to, weight) = edge;
		graph[from].emplace_back(to, weight);
	}

	vector<int> distance(num_vertices, INF);
	distance[source] = 0;

	for (int i = 0; i < num_vertices - 1; ++i)
	{
		for (int u = 0; u < num_vertices; ++u)
		{
			for (const auto& [v, weight] : graph[u])
			{
				if (distance[u] + weight < distance[v])
				{
					distance[v] = distance[u] + weight;
				}
			}
		}
	}

	for (int u = 0; u < num_vertices; ++u)
	{
		for (const auto& [v, weight] : graph[u])
		{
			if (distance[u] + weight < distance[v])
			{
				return vector<int>(1, -1);
			}
		}
	}

	return distance;
}
*/

/*
struct Point
{
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;

bool is_with_in_range(int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}

Point find_start_point(char start, vector<string>& maps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == start)
			{
				return { i, j, 0 };
			}
		}
	}

	return { -1, -1, -1 };
}

int bfs(char start, char end, vector<string>& maps)
{
	bool visited[101][101] = { false };
	queue<Point> q;

	q.push(find_start_point(start, maps));

	while (!q.empty())
	{
		Point current = q.front();
		q.pop();

		if (maps[current.y][current.x] == end)
		{
			return current.cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = current.y + dy[i];
			int nx = current.x + dx[i];

			if (is_with_in_range(ny, nx) && !visited[ny][nx] && maps[ny][nx] != 'X')
			{
				q.push({ ny, nx, current.cnt + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	return -1;
}

int solution(vector<string> maps) {
	n = maps.size();
	m = maps[0].size();

	int distance_to_L = bfs('S', 'L', maps);

	if (distance_to_L == -1)
	{
		return -1;
	}

	int distance_to_E = bfs('L', 'E', maps);

	return distance_to_E == -1 ? -1 : distance_to_L + distance_to_E;
}
*/

/*
const int MAX_SIZE = 100;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int check[MAX_SIZE][MAX_SIZE];

struct Point
{
	int y, x;

	Point(int y, int x) : y(y), x(x) {}

	bool is_valid(int width, int height) const
	{
		return y >= 0 && y < height && x >= 0 && x < width;
	}

	Point move(int i) const { return Point(y + dy[i], x + dx[i]); }

	bool can_move_to(const vector<vector<int>>& maps) const
	{
		return maps[y][x] == 1 && check[y][x] == 0;
	}
};

queue<Point> q;

int solution(vector<vector<int> > maps)
{
	int width = maps[0].size();
	int height = maps.size();

	q.push({ 0, 0 });
	check[0][0] = 1;

	while (!q.empty())
	{
		Point current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next = current.move(i);

			if (next.is_valid(width, height) && next.can_move_to(maps))
			{
				check[next.y][next.x] = check[current.y][current.x] + 1;
				q.push({ next.y, next.x });
			}
		}
	}

	int destination_x = width - 1;
	int destination_y = height - 1;

	if (check[destination_y][destination_x] == 0)
	{
		return -1;
	}

	return check[destination_y][destination_x];
}
*/

/*
vector<bool> visited;

void dfs(const vector<vector<int>>& network, int node)
{
	visited[node] = true;

	for (int i = 0; i < network[node].size(); i++)
	{
		if (network[node][i] && !visited[i])
		{
			dfs(network, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	visited = vector<bool>(computers.size(), false);

	int network_count = 0;

	for (int i = 0; i < computers.size(); i++)
	{
		if (!visited[i])
		{
			dfs(computers, i);
			network_count++;
		}
	}

	return network_count;
}
*/

/*
vector<vector<int>> tree;
vector<int> visited;
vector<int> comp;
int n = 0;
int answer = 0;

void dfs(vector<int> cur)
{
	int sheep = 0;
	int wolf = 0;

	for (int c : cur)
	{
		if (comp[c] == 1)
		{
			wolf++;
		}

		else
		{
			sheep++;
		}
	}

	if (sheep <= wolf)
	{
		return;
	}

	answer = max(answer, sheep);

	for (int i = 0; i < cur.size(); i++)
	{
		int node = cur[i];

		for (int g : tree[node])
		{
			if (visited[g])
			{
				continue;
			}

			visited[g] = true;
			cur.push_back(g);
			dfs(cur);
			cur.pop_back();
			visited[g] = false;
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	n = info.size();
	tree.resize(n);
	visited.resize(n, false);
	comp = info;

	for (auto e : edges)
	{
		tree[e[0]].push_back(e[1]);
	}

	visited[0] = true;
	dfs({ 0 });

	return answer;
}
*/

/*
int solution(int N, vector<vector<int> > road, int K) {
	vector<vector<pair<int, int>>> graph(N + 1);
	vector<int> distances(N + 1, numeric_limits<int>::max());
	vector<bool> visited(N + 1, false);

	distances[1] = 0;

	for (const auto& r : road)
	{
		int a = r[0];
		int b = r[1];
		int cost = r[2];

		graph[a].push_back({ b, cost });
		graph[b].push_back({ a, cost });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({ 0, 1 });

	while (!heap.empty())
	{
		int dist = heap.top().first;
		int node = heap.top().second;
		heap.pop();

		if (visited[node])
		{
			continue;
		}

		visited[node] = true;

		for (const auto& next : graph[node])
		{
			int next_node = next.first;
			int next_dist = next.second;
			int cost = dist + next_dist;

			if (cost < distances[next_node])
			{
				distances[next_node] = cost;
				heap.push({ cost, next_node });
			}
		}
	}

	int count = 0;

	for (int i = 1; i <= N; i++)
	{
		if (distances[i] <= K)
		{
			count++;
		}
	}

	return count;
}
*/

/*
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1 , 0, 0 };
const int STRAIGHT_COST = 100;
const int CORNER_COST = 600;
const int MAX_SIZE = 26;
const int INF = numeric_limits<int>::max();

struct Path
{
	int y;
	int x;
	int direction;
};

bool is_valid(int x, int y, int size)
{
	return y >= 0 && y < size && x >= 0 && x < size;
}

int solution(vector<vector<int>> board) {
	int board_size = static_cast<int>(board.size());
	int dist[MAX_SIZE][MAX_SIZE][4];

	fill(&dist[0][0][0], &dist[0][0][0] + MAX_SIZE * MAX_SIZE * 4, -1);
	queue<Path> q;

	q.push({ 0,0,1 });
	q.push({ 0,0,3 });

	dist[0][0][1] = 0;
	dist[0][0][3] = 0;

	while (!q.empty())
	{
		auto [y, x, dir] = q.front();
		q.pop();

		int last_cost = dist[y][x][dir];

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!is_valid(ny, nx, board_size) || board[ny][nx])
			{
				continue;
			}

			int new_cost = last_cost + (i == dir ? STRAIGHT_COST : CORNER_COST);

			if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > new_cost)
			{
				dist[ny][nx][i] = new_cost;
				q.push({ ny, nx, i });
			}
		}
	}

	int answer = INF;

	for (int i = 0; i < 4; ++i)
	{
		if (dist[board_size - 1][board_size - 1][i] != -1)
		{
			answer = min(answer, dist[board_size - 1][board_size - 1][i]);
		}
	}

	return answer == INF ? -1 : answer;
}
*/

int dfs(int node, int parent, const vector<vector<int>>& graph)
{
	int cnt = 1;

	for (int child : graph[node])
	{
		if (child != parent)
		{
			cnt += dfs(child, node, graph);
		}
	}

	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	vector<vector<int>> graph(n + 1);

	for (auto& wire : wires)
	{
		int a = wire[0];
		int b = wire[1];

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int min_diff = INT_MAX;

	for (auto& wire : wires)
	{
		int a = wire[0];
		int b = wire[1];

		graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
		graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

		int cnt_a = dfs(a, b, graph);
		int cnt_b = n - cnt_a;

		min_diff = min(min_diff, abs(cnt_a - cnt_b));

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	return min_diff;
}