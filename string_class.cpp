#include<iostream>
#include<cstring>
#define MAX_INPUT 256
#pragma warning(disable : 4996)							//C4996 ERROR 방지
using namespace std;

//문자열을 저장하는 클래스를 만들고 =, +=, +, ==, [], <<, >> 연산자 제작

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
	int len;													//문자열의 길이 저장
	char* str;													//문자열 저장
};

text::text(const char* s) {
	if (s) {													//NULL이 아닌 문자열로 초기화할 경우
		len = (int)strlen(s);									//문자열 길이 계산
		str = new char[len + 1];								//문자열 길이만큼 메모리 할당
		strcpy(str, s);											//문자열을 복사하여 저장
	}
	else {														//NULL로 초기화할 경우
		len = 0;												//길이를 0으로 초기화
		str = NULL;												//포인터를 NULL로 초기화
	}
}

text::text(const text &s) {	
	len = s.len;												//문자열 길이 설정
	str = new char[len + 1];									//문자열 길이만큼 메모리 할당
	strcpy(str, s.str);											//문자열을 복사해서 저장
}

text::~text() {
	if (str) delete[] str;										//메모리 반납
}

text &text::operator=(const text &s) {
	if (str) delete[] str;										//기존의 메모리 반납

	len = s.len;												//새로운 길이 설정
	str = new char[len + 1];									//메모리를 다시 할당
	strcpy(str, s.str);											//문자열을 복사해서 저장

	return *this;
}

text &text::operator+=(const text &s) {
	len += s.len;												//이어 붙일 문자열 길이 합산
	char* newstr = new char[len + 1];							//새로운 메모리 할당
	strcpy(newstr, str);										//기존 문자열 복사
	if (str) delete[] str;										//기존 메모리 반납

	strcat(newstr, s.str);										//이어 붙일 문자열 연결
	str = newstr;												//새로운 메모리 설정
	return *this;												
}

text text::operator+(const text &s) {
	text temp;													//임시 변수 선언
	temp.len = len + s.len;										//두 문자열의 길이 합산
	temp.str = new char[temp.len + 1];							//메모리 할당
	strcpy(temp.str, str);										//첫번째 문자열 복사
	strcat(temp.str, s.str);									//두번째 문자열 연결

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