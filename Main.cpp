#include "List.h"

using namespace std;

/*
* @brief ����� ����� � ���������. � ��� ����������� ������ ������ ���������������� ��������� <<.
*/
int main() {

	List<int> l1;
	l1.pushBack(1);
	l1.pushBack(5);
	l1.pushBack(10);
	cout << l1;
	
	return 0;
}