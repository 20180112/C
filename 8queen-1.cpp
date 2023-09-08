#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;

//attack函数记录放下此皇后后，别的位置能否继续放皇后，不能的记为1
void put_queen(int x, int y, vector<vector<int>>& attack) {
	//常量的方向数组，向八个方向进行标记
	static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
	static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
	attack[x][y] = 1;

	for (int i = 0; i < attack.size(); i++)
	{//向1到n-1延伸
		for (int j = 0; j < 8; j++) {//遍历8个方向
			int nx = x + i * dx[j];
			int ny = y + i * dy[j];
			//新位置在期盼范围内  
			if (nx >= 0 && nx < attack.size() && ny >= 0 && ny < attack.size())
			{
				attack[nx][ny] = 1;
			}
		}
	}
}

void backtrack(int k, int n, vector<string>& queen, 
							 vector<vector<int>>& attack, 
							 vector<vector<string>>& solve) 
{
	//回溯法求解N皇后的递归函数
	//k表示当前处理的行
	//n表示N皇后问题
	//queen存储皇后的位置
	//attack标记皇后的攻击位置
	//solve存
	if (k == n)
	{//递归结束条件
		solve.push_back(queen);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (attack[k][i] == 0) {
			vector<vector<int>> tmp = attack; //备份attack数组
			queen[k][i] = 'Q';
			put_queen(k, i, attack);
			backtrack(k + 1, n, queen, attack, solve);
			//回溯
			attack = tmp; 
			queen[k][i] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> solve;
	vector<vector<int>> attack;
	vector<string> queen;

	for (int i = 0; i < n; i++)
	{
		attack.push_back((std::vector<int>())); //初始化attack数组
		for (int j = 0; j < n; j++)
		{
			attack[i].push_back(0);
		}
		queen.push_back("");
		queen[i].append(n, '.');
	}
	backtrack(0, n, queen, attack, solve);
	return solve;
}

int main() {
	vector<vector<string>> result;
	int n;
	cin >> n;
	result = solveNQueens(n);
	int count = 0;
	for (int i = 0; i < result.size(); i++)
	{
		//printf("解法%d:\n", i + 1);
		for (int j = 0; j < result[i].size(); j++)
		{
			char* s = (char*)malloc(sizeof(char)*100000);
			strcpy(s, result[i][j].c_str());
			//printf("%s\n", s);
			for (int k = 0; k < strlen(s); k++)
			{
				if (s[k] == 'Q') {
					printf("%d ", k+1); continue;
				}
			}
		}
		printf("\n");
		count++;
		if (count == 3)
		{
			break;
		}
	}


	//printf("%d皇后共有%d种解法.\n", n,result.size());
	printf("%d\n",result.size());
	//for (int i = 0; i < result.size(); i++)
	//{
	//	printf("解法%d:\n", i + 1);
	//	for (int j = 0; j < result[i].size(); j++)
	//	{
	//		printf("%s\n", result[i][j].c_str());
	//		//printf("%s\n", result[i][j].c_str());
	//	}
	//	printf("\n");
	//}
	return 1;
}
