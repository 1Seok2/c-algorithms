#include<iostream>
#include<cstring>
#define MAX_INPUT 256
#pragma warning(disable : 4996)							//C4996 ERROR ����
using namespace std;

//���ڿ��� �����ϴ� Ŭ������ ����� =, +=, +, ==, [], <<, >> ������ ����

class text {
public:
	text(const char* s = NULL);
	text(const text &s);
	~text();
	int length() {
		return len;
	}

	text &operator=(const text &s);
	text &operator+=(const text &s);
	text operator+(const text &s);
	bool operator==(const text &s);
	char &operator[](int l);

	friend ostream &operator<<(ostream &os, const text &s);
	friend istream &operator>>(istream &is, text &s);

private:
	int len;													//���ڿ��� ���� ����
	char* str;													//���ڿ� ����
};

text::text(const char* s) {
	if (s) {													//NULL�� �ƴ� ���ڿ��� �ʱ�ȭ�� ���
		len = (int)strlen(s);									//���ڿ� ���� ���
		str = new char[len + 1];								//���ڿ� ���̸�ŭ �޸� �Ҵ�
		strcpy(str, s);											//���ڿ��� �����Ͽ� ����
	}
	else {														//NULL�� �ʱ�ȭ�� ���
		len = 0;												//���̸� 0���� �ʱ�ȭ
		str = NULL;												//�����͸� NULL�� �ʱ�ȭ
	}
}

text::text(const text &s) {	
	len = s.len;												//���ڿ� ���� ����
	str = new char[len + 1];									//���ڿ� ���̸�ŭ �޸� �Ҵ�
	strcpy(str, s.str);											//���ڿ��� �����ؼ� ����
}

text::~text() {
	if (str) delete[] str;										//�޸� �ݳ�
}

text &text::operator=(const text &s) {
	if (str) delete[] str;										//������ �޸� �ݳ�

	len = s.len;												//���ο� ���� ����
	str = new char[len + 1];									//�޸𸮸� �ٽ� �Ҵ�
	strcpy(str, s.str);											//���ڿ��� �����ؼ� ����

	return *this;
}

text &text::operator+=(const text &s) {
	len += s.len;												//�̾� ���� ���ڿ� ���� �ջ�
	char* newstr = new char[len + 1];							//���ο� �޸� �Ҵ�
	strcpy(newstr, str);										//���� ���ڿ� ����
	if (str) delete[] str;										//���� �޸� �ݳ�

	strcat(newstr, s.str);										//�̾� ���� ���ڿ� ����
	str = newstr;												//���ο� �޸� ����
	return *this;												
}

text text::operator+(const text &s) {
	text temp;													//�ӽ� ���� ����
	temp.len = len + s.len;										//�� ���ڿ��� ���� �ջ�
	temp.str = new char[temp.len + 1];							//�޸� �Ҵ�
	strcpy(temp.str, str);										//ù��° ���ڿ� ����
	strcat(temp.str, s.str);									//�ι�° ���ڿ� ����

	return temp;
}

bool text::operator==(const text &s) {
	return strcmp(str, s.str) == 0;
}

char &text::operator[](int l) {
	return str[l];
}

ostream &operator<<(ostream &os, const text &s) {
	os << s.str;
	return os;
}

istream &operator>>(istream &is, text &s) {
	char str[MAX_INPUT];
	is >> str;

	s = text(str);
	return is;
}

int main() {
	text t1("text");
	text t2("test");
	text t3("text test");

	text t4 = t1;
	t4 += text(" ") + t2;

	cout << "t3 : " << t3 << endl;
	cout << "t4 : " << t4 << endl;

	if (t3 == t4) {
		cout << "t3 & t4 is same !!\n";
	}

	for (int i = 0; i < t4.length(); i++) {
		cout << t4[i] << " / ";
	}
	cout << endl;
	return 0;
}