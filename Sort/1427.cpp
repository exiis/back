#include<iostream>

using std::cout;
using std::cin;

/* debug note:
* �� �ڸ����� ������ 1����� �����Ͽ� 10���� ������ ���� �Ϸ��� �ߴ�.
* ( num / cur -> cur = cur/10 , num%cur�� ����..)
* �پ��ִ� ū �ڸ����� ������ ��� ���ڿ� ���·� ����� ó�� �ϴ� ���� �ξ� ���ϴ�.
* �̸� ��������.
*/
int main(void) {
	char N[15] = { 0 };
	cin >> N;

	int arr[10] = { 0 };

	int i = 0;
	while (N[i] != 0) {
		/* note :
		* ���ڷ� ǥ���� ������ ���������� ����� �����
		* ���� ������ ��ų�� �ƽ�Ű ���� '0'�� ���ִ� ����̴�.
		* �����ϵ��� ����.
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