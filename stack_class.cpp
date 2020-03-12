#include<iostream>
using namespace std;

template<typename T>
class Stack {
public:
	Stack(int size = 100);
	~Stack();

	void Push(const T &value);						//데이터 넣기
	void Pop();										//마지막에 넣은 데이터 삭제
	void Top(T &value);								//마지막에 넣은 데이터 읽기
	bool Empty();									//스택이 비었으면 true를 리턴

private:
	int top;										//데이터가 저장되는 위치를 나타내는 함수
	int size;										//스택의 크기		
	T* data;										//데이터를 저장할 버퍼의 포인터
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
	if (top >= size - 1) {							//스택이 꽉 찼으면...
		cout << "OVERLOADED\n";
		exit(0);
	}

	data[++top] = value;							//데이터 넣기
}

template<typename T>
void Stack<T>::Pop() {
	if (Empty()) {									//스택이 텅 비었으면...
		cout << "EMPTY\n";
	}

	--top;											//데이터 삭제
}

template<typename T>
void Stack<T>::Top(T &value) {
	if (Empty()) {									//스택이 텅 비었으면...
		cout << "EMPTY\n";
	}

	value = data[top];								//데이터 읽기
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