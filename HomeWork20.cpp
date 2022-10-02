#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//��������� ������ ���������� ������� �� ��������� �� begin �� end.
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end + 1 - begin) + begin; // ��������� ����� � ��������� �� begin �� end ������������.
}
//����� ������� � �������.
template <typename T>
void showArr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//���������� ������ ������� ��������� �������� � ������. �������� �������� �� ��������� begin = 0.
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}
//���������� ������ ���������� ��������� �������� � ������. �������� �������� �� ��������� begin = 0.
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin = 0) {
	for (int i = length - 1; i >= begin; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

//���������� ������������ ������� �������.
template <typename T>
int maxElement(T arr[], const int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++) {
		max = max > arr[i] ? max : arr[i];
	}
	return max;
}

//���������� ����������� ������� �������.
template <typename T>
int minElement(T arr[], const int length) {
	int min = arr[0];
	for (int i = 0; i < length; i++) {
		min = min < arr[i] ? min : arr[i];
	}
	return min;
}

//���������� ������� �������������� ���� ��������� �������.
template <typename T>
double meanValue(T arr[], const int length) {
	double sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum / length;
}

//������� ��� �������� �������, ������� ������ � ���������� � ������� ��������.
template <typename T>
int range(T arr[], const int length, int begin, int end) {
	for (int i = 0; i < length; i++) {
		if (arr[i] >= begin && arr[i] <= end)
			cout << arr[i] << ", ";
	}		
	cout << "\b\b.\n";
	return 0;
}

//���������� ���������� ��������� ����������� �������� � ������.
template <typename T>
int counter(T arr[], const int length, T value) {
	int counter_value = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] == value)
			counter_value++;
	}
	return counter_value;	
}

int main() {
	setlocale(LC_ALL, "Russian");

	//������ 20.1. �������.
	cout << "������ 20.1. \n����������� ������:\n";
	const int size = 100;
	int mas[size];
	fill_arr(mas, size, -100, 100); // ��������� ������ ���������� �������
	showArr(mas, size); //������� ������
	cout << "\n������� ����� �� �������: \n";
	int n;
	cin >> n;
	//������ ���������	
	if (searchIndex(mas, size, n) == -1)
		cout << "����� " << n << " ��� � �������.\n";
	else
		cout << "������ ������� ����� " << n << " � ������� = " << searchIndex(mas, size, n) << ".\n"; 

	//��������� ���������
	if (searchLastIndex(mas, size, n) == -1)
		cout << "����� " << n << " ��� � �������.\n";
	else
		cout << "������ ������� ����� " << n << " � ������� = " << searchLastIndex(mas, size, n) << ".\n";
	//������������ ������� �������
	cout << "������������ ������� ������� = " << maxElement(mas, size) << ".\n";

	//������������ ������� �������
	cout << "����������� ������� ������� = " << minElement(mas, size) << ".\n";

	//������� �������������� ����������������
	cout << "������� �������������� ���������������� = " << meanValue(mas, size) << ".\n";

	//������� ��� �������� �������, ������� ������ � ���������� � ������� ��������.
	int A, B;
	cout << "\n������ ������ ���������: ";
	cin >> A;
	cout << "������ ����� ���������: ";
	cin >> B;
	cout << "��� �������� �������, ������� ������ � �������� �� " << A << " �� " << B << ": ";
	range(mas, size, A, B);

	//���������� ���������� ��������� ����������� �������� � ������.
	int D;
	cout << "\n������ �����: ";
	cin >> D;
	cout << "���������� ��������� ����������� �������� � ������ = " << counter(mas, size, D) << ".\n\n";

	return 0;
}