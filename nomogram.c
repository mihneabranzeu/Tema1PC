#include <stdio.h>

#define LIMIT 101

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++) {
		int n, m;
		scanf("%d %d", &n, &m);
		int ok = 0;
		int gasit = 0;
		int a[LIMIT][LIMIT] = {{0}};
		int v[LIMIT + LIMIT][LIMIT] = {{0}};
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
					cnt_v++; continue;
				}
				if (a[i][j] == 1)
					v[i][cnt_v]--;
			}
			for (int j = 1; j <= m; j++)
				if (v[i][j] != 0) {
					ok = 1; break;
				}
			if (ok == 1) {
				gasit = 1; break;
			}
		}
		if (gasit == 1) {
			printf("Eroare\n"); continue;
		}
		ok = 0;
		gasit = 0;
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
				if (v[n + j][i] != 0) {
					ok = 1;
					break;
				}
			if (ok == 1) {
				gasit = 1;
				break;
			}
		}
		if (gasit == 1) {
			printf("Eroare\n");
			continue;
		}
		printf("Corect\n");
	}
	return 0;
}
