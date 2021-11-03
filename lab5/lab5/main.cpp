#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> 
#include <locale.h>
using namespace std;
void BFS(int** G, int* vis, int num, int n) {
	queue <int> q;
	int i;
	q.push(num);
	vis[num] = 1;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		printf("%d ", num);
		for (i = 0; i < n; i++) {
			if (vis[i] == 0 && G[num][i] == 1) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}
int main(void) {
	setlocale(LC_ALL, "Rus");
	int** a;
	int N;
	printf("¬ведите N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	int len = N;
	int* visits = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		visits[i] = 0;
	}
	printf("¬ведите вершину: ");
	scanf("%d", &N);
	BFS(a, visits, N, len);
}

