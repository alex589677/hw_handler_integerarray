//author А.С.Гадиатулин group CPLUS-1006 module-7 block Base constructs C++
#include <iostream>
#include "IntegerArray.h"
#include "MyExceptions.h"
using namespace std;

/**
* Работа с программой: 
*	-сначала создание массива пункт 1;
*   -потом добавление значений через пробел пункт 2;
*   -и только потом оставшиеся пункты 3,4,5,6,q.
*  Исключения применяются в пукнтах 1,6(bad_length) и 4(bad_range).
*  Операции доступны только с первым созданным массивом.
*  Второй массив только создание(копирование от первого массива) и простотр значений.
*/

int main() {
	setlocale(LC_ALL, "Russian");
	bool isOpen = false;
	char choice = 'A';
	static IntegerArray arr1;
	static IntegerArray arr2;
	static int my_size = 0;
	while (!isOpen) {
		cout << "You select(order steps enter 1 paragraf, after 2 paragraf,...): \n"
			 << "\t1-create array\n"
			 << "\t2-fill array enter values separated by space\n"
			 << "\t3-add one value to end array\n"
			 << "\t4-insert value by index in array\n"
			 << "\t5-delete last value\n"
			 << "\t6-get value by index in array\n"
			 << "\t7-create second array\n"
			 << "\t8-display array(/arrays)\n"
			 << "\tq-exit\n";
		cin >> choice;
		switch (choice) {
			case '1': {
				cout << "Enter size array:\n";
				try {
					cin >> my_size;
					if (my_size < 0)
						throw bad_length();
				}
				catch (bad_length& e) {
					cout << "Caught " << e.what() << endl;
					cout << "Attention array dons`t create" << endl;
					break;
				}
				arr1 = { my_size };
				cout << "---------Congratulations you create array!----------\n";
				break;
			}
			case '2': {
				cout << "Fill array enter " << my_size << " numbers "
					 << "separated by space after click ENTER" << endl;
				cin >> arr1;
				break;
			}
			case '3': {
				cout << "Add one value to end array:\n";
				int value = 0;
				cin >> value;
				arr1.push_back(value);
				break;
			}
			case '4': {
				cout << "Enter one value in array:\n";
				int value = 0;
				int index = 0;
				cin >> value;
				cout << "Enter index:\n";
				cin >> index;
				try {
					if (index < 0 || index > my_size)
						throw bad_range();
					arr1.insertBefore(value, index);
				}
				catch (bad_range& e) {
					cout << "Caught " << e.what() << endl;
					break;
				}
				break;
			}
			case '5':
				arr1.pop_back();
				cout << "Deleted last value of array.\n";
				break;
			case '6': {
				cout << "Select index:\n";
				int index = 0;
				cin >> index;
				try {
					if (index < 0 || index > my_size)
						throw bad_length();
				}
				catch (bad_length& e) {
					cout << "Caught " << e.what() << endl;
					break;
				}
				cout << "You value: " << arr1.getValue(index) << endl;
				break;
			}
			case '7': {
				cout << "Created second array." << endl;
				arr2 = arr1;
				cout << "---------Congratulations you create second array!----------\n";
				break;
			}
			case '8': {
				cout << "Display array(/arrays): \n";
				for (int i = 0; i < arr1.getSize(); i++) {
					cout << arr1[i] << " ";
				}
				cout << endl;
				if (arr2.getSize() > 0) {
					for (int i = 0; i < arr2.getSize(); i++) {
						cout << arr2[i] << " ";
					}
					cout << endl;
				}
				break;
			}
			case 'q': {
				isOpen = true;
				break;
			}
			default:
				cout << "Wrong input. Try again." << endl;
				break;
		}
	}
	
	system("pause");
	return 0;
}