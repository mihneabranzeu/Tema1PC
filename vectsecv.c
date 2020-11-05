#include <stdio.h>

#define ARRAY_LIMIT 101

int compute_crescator(int x)
{
	int digitscnt[10] = {0}; //keeps track of the digits
	int n_crescator = 0;
	do {
		int c = x % 10;
		digitscnt[c]++;
		x /= 10;
	} while (x > 0);

	for (int i = 0; i <= 9; i++) {
		while (digitscnt[i] > 0) {
			n_crescator = n_crescator * 10 + i;
			digitscnt[i]--;
		}
	}

	return n_crescator;
}

int compute_descrescator(int x)
{
	int digitscnt[10] = {0}; //keeps track of the digits
	int n_descrescator = 0;
	do {
		int c = x % 10;
		digitscnt[c]++;
		x /= 10;
	} while (x > 0);

	for (int i = 9; i >= 0; i--) {
		while (digitscnt[i] > 0) {
			n_descrescator = n_descrescator * 10 + i;
			digitscnt[i]--;
		}
	}

	return n_descrescator;
}

int main(void)
{
	int N, n_crescator, n_descrescator, new_number;
	int v[ARRAY_LIMIT] = {0};
	int ok = 0;
	int cnt = 0;

	scanf("%d", &N);

	while (ok == 0) {
		n_crescator = compute_crescator(N);
		n_descrescator = compute_descrescator(N);
		new_number = n_descrescator - n_crescator;
		int found = 0;

		for (int i = 0; i < cnt; i++)
			if (new_number == v[i]) {
				ok = 1;
				found = 1;
				break;
			}

		if (found == 0)
			v[cnt++] = new_number;

		if (ok == 1) {
			int start_display = 0;
			for (int i = 0; i < cnt; i++) {
				if (v[i] == new_number) {
					printf("%d\n", i);
					start_display = 1;
				}

				if (start_display == 1)
					printf("%d ", v[i]);
			}
			printf("\n");
		}

		N = new_number;
	}
	return 0;
}
