#include<iostream>
#include<cstdlib>
#include <string>
#include <time.h>
using namespace std;


int correctinput() {
	int i, t, b;
	bool a = true;
	string temp;
	do
	{
		getline(cin, temp);
		t = 0;
		for (i = 0; i < temp.length(); i++) {
			if ((int)temp[i]< (int) '0' || (int)temp[i] > (int)'9') {
				cout << "Error!" << endl;
				a = true;
				break;
			}
			else {
				t++;
				a = false;
			}
		}
		if (a == false && t == temp.length()) { b = atoi(temp.c_str()); }
		else {
			a = true;
		}
	} while (a);
	return b;
};

template <typename T>
class MyClass
{
private:
	int size;
	T* arr;

public:
	MyClass()
	{
		size = 0;
		this->arr = new T[this->size];
	}
	MyClass(T* a, int size1)
	{
		int i;
		this->size = size1;
		this->arr = new T[this->size];
		for (i = 0; i < this->size; i++) {
			arr[i] = a[i];
		}
	}

	void set() {
		int i = 0;
		cout << "Input size:" << endl;
		size = correctinput();
		delete[]arr;
		T* arr1 = new  T[size];
		for (i = 0; i < size; i++) {
			cout << "Input arr[" << i << "]:" << endl;
			cin >> arr1[i];
		}
		this->arr = arr1;
	}
	void pr() {
		int i;
		for (i = 0; i < size; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}

	int sizearr() {
		return size;
	}

	T get(int i) {
		return arr[i];
	}

	~MyClass()
	{
		delete[] arr;
	}

};

template <typename T1>

T1 count(MyClass<T1>& a, T1 usl) {
	int k = 0, i;
	for (i = 0; i < a.sizearr(); i++) {
		if (a.get(i) == usl) {
			k++;
		}
	}
	return k;
}



int main()
{
	srand(time(NULL));
	int size = 0,k=0;
	int usl;
	char usl2;


	cout << "Input size:" << endl;
	size = correctinput();
	char* arrchar = new char[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Input char [" << i << "]: ";
		cin >> arrchar[i];
	}

	MyClass <char> achar( arrchar, size);
	
	achar.pr();

	cout << "Input uslovie:\n";
	cin >> usl2;

	k = count(achar, usl2);
	cout << "Result: " << k << endl;
	k = 0;
	MyClass<int> aint;
	aint.set();
	aint.pr();
	cout << "Input uslovie:\n";
	cin >> usl;
	
	k = count(aint, usl);
	cout << "Result: " << k << endl;

	return 0;
}