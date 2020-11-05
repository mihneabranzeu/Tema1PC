#include <stdio.h>

#define LIMIT 101

int check_matrix(void)
{
	int n, m;
	int a[LIMIT][LIMIT] = {{0}}, v[LIMIT + LIMIT][LIMIT] = {{0}};
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++) {
		scanf("%d", &v[i][0]);
		for (int j = 1; j <= v[i][0]; j++)
			scanf("%d", &v[i][j]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++) {
		int cnt_v = 1;
		int start;
		for (int j = 0; j < m; j++)
			if (a[i][j]  == 1) {
				start = j;
				break;
			}
		for (int j = start; j < m; j++) {
			if (a[i][j] == 0 && a[i][j - 1] == 1) {
				cnt_v++;
				continue;
			}
			if (a[i][j] == 1)
				v[i][cnt_v]--;
		}
		for (int j = 1; j <= m; j++)
			if (v[i][j] != 0)
				return 0;
	}
	for (int j = 0; j < m; j++) {
		int cnt_v = 1;
		int start;
		for (int i = 0; i < n; i++)
			if (a[i][j]  == 1) {
				start = i;
				break;
			}
		for (int i = start; i < n; i++) {
			if (a[i][j] == 0 && a[i - 1][j] == 1) {
				cnt_v++;
				continue;
			}
			if (a[i][j] == 1)
				v[n + j][cnt_v]--;
		}
		for (int i = 1; i <= n; i++)
			if (v[n + j][i] != 0)
				return 0;
	}
	return 1;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++) {
		int ok = check_matrix();
		if (ok == 0)
			printf("Eroare\n");
		else
			printf("Corect\n");
	}
	return 0;
}

