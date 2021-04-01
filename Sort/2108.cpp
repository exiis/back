#include<iostream>
#include<cmath>

using std::cout;
using std::cin;

int main(void) {
	/* 0 ~ 3999 : - value
	* 4001~8000 : - value */
	int arr[8002] = { 0 };
	int N;
	int input;

	int max = -4000;
	int min = 4000;

	int sum = 0;

	int mode_big = 0;
	int mode_small = -4001;
	int mode_count = -4001;

	cin >> N;
	/* get data & counting */
	for (int i = 0; i < N; i++) {
		cin >> input;
		/* update min & max value for range */
		if (input > max) max = input;
		if (input < min) min = input;

		/* for avg */
		sum += input;


		/* Debug Note :
		* �ڵ鸵�� ���Ͽ� 4000���� ���������� �� ��ü�� �ٷ�� ���Ͽ��� 4000�� ���� ���� �ٽ� ����� �Ѵ�.
		* �̺κп� ���Ͽ� �򰥸��� �ʰ� Ȯ���� ����� ��.
		*/

		/* handling negative value */
		input += 4000;
		arr[input]++;

		/* for mode */
		if (mode_count < arr[input]) {
			mode_count = arr[input];
			mode_small = input - 4000;
			mode_big = -4001;
		}
		else if (mode_count == arr[input]) {
			if (mode_small > input - 4000) {
				mode_big = mode_small;
				mode_small = input - 4000;
			}
			else if (mode_big == -4001 || mode_big > input - 4000) mode_big = input - 4000;
		}
	}

	int range = max - min;

	/* Debug Note :
	* round �Լ��� ���ڴ� ���ø��� Ȱ���ϱ� ������ 1.0�� ���Ͽ� double������ �������� �Ѵ�.
	* (���ø� = �ڹ��� ���׸� Ÿ�԰� ����)
	*/
	int avg = round(1.0 * sum / N);
	
	int mode;
	if (mode_big == -4001) mode = mode_small;
	else mode = mode_big;

	int count = N / 2 + 1;
	int i = 0;
	int mid = 0;
	while (1) {
		count -= arr[i];
		if (count <= 0) {
			i -= 4000;
			mid = i;
			break;
		}
		i++;
	}

	cout << avg << "\n"
		<< mid << "\n"
		<< mode << "\n"
		<< range << "\n";

	return 0;
}