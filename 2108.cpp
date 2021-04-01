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
		* 핸들링을 위하여 4000값을 더해줬으나 값 자체를 다루기 위하여는 4000을 더한 값을 다시 빼줘야 한다.
		* 이부분에 대하여 헷갈리지 않고 확실히 해줘야 함.
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
	* round 함수의 인자는 템플릿을 활용하기 때문에 1.0을 곱하여 double형으로 만들어줘야 한다.
	* (템플릿 = 자바의 제네릭 타입과 유사)
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