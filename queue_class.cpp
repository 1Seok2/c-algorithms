#include<iostream>
using namespace std;

template<typename T>
class Queue {
public:
	Queue(int size = 100);
	~Queue();

	void Push(const T &value);						//������ �ֱ�
	bool Empty();									//ť�� ������� true�� ����
	void Front(T &value);							//�� ó�� ���� ������ �б�
	void Pop();										//�� ó�� ���� ������ ����

private:
	int front;										//�����͸� ������ ��ġ
	int rear;										//�����͸� �ִ� ��ġ
	int size;										//ť�� ũ��
	int count;										//ť�� ����� ������ ����
	T* data;										//�����͸� ������ ������ ������
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
	if (count >= size) {							//ť�� �� á����...
		cout << "Queue is Full\n";
	}
	rear = (rear + 1) % size;						//�����͸� ���� ��ġ�� �̵�
	count++;										//ť�� ����� ������ ���� ����
	data[rear] = value;								//������ �ֱ�
}

template<typename T>
bool Queue<T>::Empty() {
	return (count == 0);
}

template<typename T>
void Queue<T>::Front(T &value) {
	if (Empty()) {									//ť�� �������...
		cout << "Queue is Empty\n";
	}
	value = data[front];							//�����͸� ���� ��ġ �̵�
}

template<typename T>
void Queue<T>::Pop() {
	if (Empty()) {									//ť�� �������...
		cout << "Queue is Empty\n";
	}
	front = (front + 1) % size;						//�����͸� ���� ��ġ �̵�
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