#pragma once
#pragma once

using namespace std;

class Info {
private:
	char* classs;
	char* classhead;
	char* averageMark;
	char* teacher;
	char* studentsNumber;

	Info* pnext;

public:
	Info();
	~Info();
	char* toString();
	char* toSaveString();


	char* getClasss();
	char* getClasshead();
	char* getAverageMark();
	char* getTeacher();
	char* getStudentsNumber();
	Info* getNext();
	void setNext(Info* info);
	void fillInfo();
	void clone(Info* source);

};

ostream& operator<<(ostream& out, Info* info);
istream& operator>>(istream& in, Info* info);


