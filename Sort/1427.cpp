#include<iostream>

using std::cout;
using std::cin;

/* debug note:
* 각 자리수의 구분을 1억부터 시작하여 10으로 나눠서 구분 하려고 했다.
* ( num / cur -> cur = cur/10 , num%cur와 같이..)
* 붙어있는 큰 자리수의 정수의 경우 문자열 형태로 만들어 처리 하는 것이 훨씬 편하다.
* 이를 숙지하자.
*/
int main(void) {
	char N[15] = { 0 };
	cin >> N;

	int arr[10] = { 0 };

	int i = 0;
	while (N[i] != 0) {
		/* note :
		* 문자로 표현된 정수를 정수값으로 만드는 방법중
		* 쉽고 간편한 스킬이 아스키 문자 '0'을 빼주는 방법이다.
		* 숙지하도록 하자.
		*/
		int temp = N[i] - '0';
		arr[temp]++;
		i++;
	}

	for (int i = 9; i >= 0; i--)
		for (int j = arr[i]; j > 0; j--)
			cout << i;

	return 0;
}