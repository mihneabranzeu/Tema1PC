#include <stdio.h>

int main(void)
{
	int N, current_tree, left_tree, right_tree;
	unsigned long long sum = 0;
	unsigned int cnt_special_trees = 0;
	int xmax_impar = -1;
	int xmin_par = -1;
	double m_a;

	scanf("%d", &N);
	scanf("%d", &left_tree);
	if (N >= 2) {
		scanf("%d", &current_tree);

		for (int i = 2; i < N; i++) {
			scanf("%d", &right_tree);

			if (left_tree < current_tree && current_tree > right_tree) {
				sum += current_tree;
				cnt_special_trees++;

				if (i % 2 == 0)
					if (xmax_impar < current_tree)
						xmax_impar = current_tree;

				if (i % 2 == 1) {
					if (xmin_par == -1)
						xmin_par = current_tree;
					if (xmin_par > current_tree)
						xmin_par = current_tree;
				}
			}

			left_tree = current_tree;
			current_tree = right_tree;
		}
	}
	printf("%lld\n", sum);

	if (cnt_special_trees == 0)
		m_a = 0;
	else
		m_a = 1.0 * sum / cnt_special_trees;
	printf("%.7lf\n", m_a);

	if (xmax_impar == -1 && xmin_par == -1) {
		xmax_impar = 0;
		xmin_par = 0;
	}
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);
	return 0;
}
