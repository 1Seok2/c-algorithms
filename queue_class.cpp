#include<iostream>
using namespace std;

template<typename T>
class Queue {
public:
	Queue(int size = 100);
	~Queue();

	void Push(const T &value);						//데이터 넣기
	bool Empty();									//큐가 비었으면 true를 리턴
	void Front(T &value);							//맨 처음 넣은 데이터 읽기
	void Pop();										//맨 처음 넣은 데이터 삭제

private:
	int front;										//데이터를 꺼내는 위치
	int rear;										//데이터를 넣는 위치
	int size;										//큐의 크기
	int count;										//큐에 저장된 데이터 개수
	T* data;										//데이터를 저장할 버퍼의 포인터
};

template<typename T>
Queue<T>::Queue(int size) {
	this->size = size;
	front = 0;
	rear = -1;
	count = 0;
	data = new T[size];
}

template<typename T>
Queue<T>::~Queue() {
	delete[] data;
}

template<typename T>
void Queue<T>::Push(const T &value) {
	if (count >= size) {							//큐가 꽉 찼으면...
		cout << "Queue is Full\n";
	}
	rear = (rear + 1) % size;						//데이터를 넣을 위치로 이동
	count++;										//큐에 저장된 데이터 개수 증가
	data[rear] = value;								//데이터 넣기
}

template<typename T>
bool Queue<T>::Empty() {
	return (count == 0);
}

template<typename T>
void Queue<T>::Front(T &value) {
	if (Empty()) {									//큐가 비었으면...
		cout << "Queue is Empty\n";
	}
	value = data[front];							//데이터를 꺼낼 위치 이동
}

template<typename T>
void Queue<T>::Pop() {
	if (Empty()) {									//큐가 비었으면...
		cout << "Queue is Empty\n";
	}
	front = (front + 1) % size;						//데이터를 꺼낼 위치 이동
	count--;
}

int main() {
	char c;
	Queue<char> char_queue(10);
	char_queue.Push('A');
	char_queue.Push('B');
	char_queue.Push('C');

	while (!char_queue.Empty()) {
		char_queue.Front(c);
		cout << c << endl;
		char_queue.Pop();
	}

	int i;
	Queue<int> int_queue(10);
	int_queue.Push(10);
	int_queue.Push(20);
	int_queue.Push(30);
	while (!int_queue.Empty()) {
		int_queue.Front(i);
		cout << i << endl;
		int_queue.Pop();
	}

	return 0;
}