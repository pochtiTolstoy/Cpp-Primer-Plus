#include <iostream>

struct applicant {
	char name[30];
	int credit_ratings[3];
};

void f1(applicant* a); // можно модифицировать
const char* f2(const applicant* a1, const applicant* a2); // нельзя модифицировать

typedef void (*PF1)(applicant*);
typedef const char* (*PF2)(const applicant*, const applicant*);

int main() {
	//void (*p1)(applicant* a);
	PF1 p1 = f1;
	//const char* (*p2)(const applicant* a1, const applicant* a2);
	PF2 p2 = f2;
	//void (*ap[5]) (applicant* a);
	PF1 ap[5];
	//const char* (*(*pa)[10])(const applicant* a1, const applicant* a2);
	PF2 (*pa)[10];
	return 0;
}

void f1(applicant* a) { // можно модифицировать
	std::cout << "f1 call.\n";
}

const char* f2(const applicant* a1, const applicant* a2) { // нельзя модифицировать
	std::cout << "f2 call.\n";
	const char* str = "const char* str: f2 call.\n";
	return str;
}
