#include <stdio.h>

#define NMAX 101

void sort_array(int v[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (v[j] > v[i]) {
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

int main(void)
{
	int n, p_min, c;
	int x[NMAX];
	int sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		sum += x[i] * c;
		x[i] = (10 - x[i]) * c;
	}

	scanf("%d", &p_min);

	sort_array(x, n);
	int cnt = 0;

	while (sum < p_min && cnt < n)
		sum += x[cnt++];

	if (sum < p_min)
		printf("-1\n");
	else
		printf("%d\n", cnt);
	return 0;
}
