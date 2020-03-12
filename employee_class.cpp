#include<iostream>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#pragma warning(disable : 4996)
using namespace std;

class Employee {
public:
	Employee(char* name, int pos, int sal);
	~Employee();

	char* getname();
	char* getpos();
	char* getsalt();
	virtual int getsal() = 0;

protected:
	char* name;
	int pos;
	int sal;
};

Employee::Employee(char* name, int pos, int sal) {
	this->name = (char*)malloc(strlen(name) + 1);
	//this->name=new char[strlen(name)+1];
	strcpy(this->name, name);
	this->pos = pos;
	this->sal = sal;
}

Employee::~Employee() {
	delete[] name;
}

char* Employee::getname() {
	return name;
}

char* Employee::getpos() {
	char* title[] = { "»ç¿ø","´ë¸®","°úÀå","ºÎÀå","ÀÓ¿ø" };
	return title[pos];
}

char* Employee::getsalt() {
	char* type[] = { "½Ã±ÞÁ¦","¿ù±ÞÁ¦","¿¬ºÀÁ¦" };
	return type[sal];
}

class EmployeeHourly :public Employee {
public:
	EmployeeHourly(char* name, int pos, int workHour);
	virtual int getsal();

private:
	int workHour;
};

class EmployeeMonthly :public Employee {
public:
	EmployeeMonthly(char* name, int pos, int year);
	virtual int getsal();

private:
	int year;
};

class EmployeeYearly : public Employee {
public:
	EmployeeYearly(char* name, int pos, int grade);
	virtual int getsal();

private:
	int grade;
};

EmployeeHourly::EmployeeHourly(char* name, int pos, int workHour) : Employee(name, pos, 0) {
	this->workHour = workHour;
}

EmployeeMonthly::EmployeeMonthly(char* name, int pos, int year) : Employee(name, pos, 1) {
	this->year = year;
}

EmployeeYearly::EmployeeYearly(char* name, int pos, int grade) : Employee(name, pos, 2) {
	this->grade = grade;
}

int EmployeeHourly::getsal() {
	int sal = workHour * 10000;
	for (int i = 0; i < pos; i++) {
		sal *= 2;
	}
	return sal;
}

int EmployeeMonthly::getsal() {
	int sal = 2000000;
	sal += 200000 * pos;
	sal += 50000 * year;
	return sal;
}

int EmployeeYearly::getsal() {
	int sal = 20000000;
	sal += 10000000 * pos;
	sal += 5000000 * grade;
	return sal / 12;
}

int main() {
	int i = 0;
	Employee *em[] = {
		new EmployeeHourly("±è¹ÎÃ¶",0,200),
		new EmployeeHourly("¹Î½ÂÁÖ",0,220),
		new EmployeeMonthly("±èÁö¿í",2,12),
		new EmployeeYearly("ÃÖ¿ø¼®",4,89),
		new EmployeeYearly("Çü»óÃ¶",2,50)
	};

	for (int i = 0; i < 5; i++) {
		printf("%s | ", em[i]->getname());
		printf("%s | ", em[i]->getpos());
		printf("%s | ", em[i]->getsalt());
		printf("%d\n", em[i]->getsal());

		delete em[i];
	}

	return 0;
}