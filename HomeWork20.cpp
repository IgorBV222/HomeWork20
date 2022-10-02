#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Заполняет массив случайными числами из диапазона от begin до end.
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end + 1 - begin) + begin; // случайное число в диапазоне от begin до end включительно.
}
//Вывод массива в консоль.
template <typename T>
void showArr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Возвращает индекс первого вхождения элемента в массив. Содержит параметр по умолчанию begin = 0.
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}
//Возвращает индекс последнего вхождения элемента в массив. Содержит параметр по умолчанию begin = 0.
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin = 0) {
	for (int i = length - 1; i >= begin; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

//Возвращает максимальный элемент массива.
template <typename T>
int maxElement(T arr[], const int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++) {
		max = max > arr[i] ? max : arr[i];
	}
	return max;
}

//Возвращает минимальный элемент массива.
template <typename T>
int minElement(T arr[], const int length) {
	int min = arr[0];
	for (int i = 0; i < length; i++) {
		min = min < arr[i] ? min : arr[i];
	}
	return min;
}

//Возвращает среднее арифметическое всех элементов массива.
template <typename T>
double meanValue(T arr[], const int length) {
	double sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum / length;
}

//Выводит все элементы массива, которые входят в переданный в функцию диапазон.
template <typename T>
int range(T arr[], const int length, int begin, int end) {
	for (int i = 0; i < length; i++) {
		if (arr[i] >= begin && arr[i] <= end)
			cout << arr[i] << ", ";
	}		
	cout << "\b\b.\n";
	return 0;
}

//Возвращает количество вхождений переданного элемента в массив.
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

	//Задача 20.1. Функции.
	cout << "Задача 20.1. \nИзначальный массив:\n";
	const int size = 100;
	int mas[size];
	fill_arr(mas, size, -100, 100); // Заполняем массив случайными числами
	showArr(mas, size); //Выводим массив
	cout << "\nВведите число из массива: \n";
	int n;
	cin >> n;
	//Первое вхождение	
	if (searchIndex(mas, size, n) == -1)
		cout << "Числа " << n << " нет в массиве.\n";
	else
		cout << "Первая позиция числа " << n << " в массиве = " << searchIndex(mas, size, n) << ".\n"; 

	//Последнее вхождение
	if (searchLastIndex(mas, size, n) == -1)
		cout << "Числа " << n << " нет в массиве.\n";
	else
		cout << "Первая позиция числа " << n << " в массиве = " << searchLastIndex(mas, size, n) << ".\n";
	//Максимальный элемент массива
	cout << "Максимальный элемент массива = " << maxElement(mas, size) << ".\n";

	//Максимальный элемент массива
	cout << "Минимальный элемент массива = " << minElement(mas, size) << ".\n";

	//Среднее арифметическое элементовмассива
	cout << "Среднее арифметическое элементовмассива = " << meanValue(mas, size) << ".\n";

	//Выводим все элементы массива, которые входят в переданный в функцию диапазон.
	int A, B;
	cout << "\nВедите начало диапазона: ";
	cin >> A;
	cout << "Ведите конец диапазона: ";
	cin >> B;
	cout << "Все элементы массива, которые входят в диапазон от " << A << " до " << B << ": ";
	range(mas, size, A, B);

	//Возвращаем количество вхождений переданного элемента в массив.
	int D;
	cout << "\nВедите число: ";
	cin >> D;
	cout << "Количество вхождений переданного элемента в массив = " << counter(mas, size, D) << ".\n\n";

	return 0;
}