#include<iostream>
using namespace std;

template<typename T>
class Stack {
public:
	Stack(int size = 100);
	~Stack();

	void Push(const T &value);						//������ �ֱ�
	void Pop();										//�������� ���� ������ ����
	void Top(T &value);								//�������� ���� ������ �б�
	bool Empty();									//������ ������� true�� ����

private:
	int top;										//�����Ͱ� ����Ǵ� ��ġ�� ��Ÿ���� �Լ�
	int size;										//������ ũ��		
	T* data;										//�����͸� ������ ������ ������
};

template<typename T>
Stack<T>::Stack(int size) {
	top = -1;
	this->size = size;
	data = new T[size];
}

template<typename T>
Stack<T>::~Stack() {
	delete[] data;
}

template<typename T>
void Stack<T>::Push(const T &value) {
	if (top >= size - 1) {							//������ �� á����...
		cout << "OVERLOADED\n";
		exit(0);
	}

	data[++top] = value;							//������ �ֱ�
}

template<typename T>
void Stack<T>::Pop() {
	if (Empty()) {									//������ �� �������...
		cout << "EMPTY\n";
	}

	--top;											//������ ����
}

template<typename T>
void Stack<T>::Top(T &value) {
	if (Empty()) {									//������ �� �������...
		cout << "EMPTY\n";
	}

	value = data[top];								//������ �б�
}

template<typename T>
bool Stack<T>::Empty() {
	return (top < 0);
}

int main() {
	char c;
	Stack<char> char_stack(10);
	char_stack.Push('A');
	char_stack.Push('B');
	char_stack.Push('C');
	while (!char_stack.Empty()) {
		char_stack.Top(c);
		cout << c << endl;
		char_stack.Pop();
	}

	int i;
	Stack<int> int_stack(10);
	int_stack.Push(10);
	int_stack.Push(20);
	int_stack.Push(30);
	while (!int_stack.Empty()) {
		int_stack.Top(i);
		cout << i << endl;
		int_stack.Pop();
	}

	return 0;
}