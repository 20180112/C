#include<iostream>
#include<cmath>

using namespace std;

int N;
int queenPos[100];
int cnt = 0;

void NQueen(int k) {
	int i;
	if (k==N)
	{
		cnt++;
		if (cnt <= 3)
		{
			for (i = 0; i < N; i++) cout << queenPos[i] + 1 << " ";
			cout << endl;
		}
		return;
	}
	for ( i = 0; i < N; i++)
	{//尝试每一列，找是否有正确的解
		int j;
		for ( j = 0; j < k; j++)
		{//遍历前面已经放好的皇后位置，看看是否冲突
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) {
				//查看是否列相同或者斜对角相同
				break;
			}
		}
		if (j == k)
		{
			queenPos[k] = i;
			NQueen(k + 1);
		}
	}
}

int main() {
	cin >> N;
	NQueen(0);
	cout << cnt << endl;
	return 0;
}
