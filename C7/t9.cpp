#include <iostream>
#include <cstring>

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);
//--------------------------------------------
void clear_buffer(void);

int main() {
	std::cout << "Enter class size: ";
	int class_size;
	std::cin >> class_size;
	clear_buffer();	
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; ++i) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	std::cout << "Done\n";
	return 0;
}

int getinfo(student pa[], int n) {
	char temp[SLEN];
	int items;
	for (items = 0; items < n; ++items) {
//-------------------Fullname---------------------
		std::cout << "Enter full name of student: ";
		if (!(std::cin.getline(temp, SLEN))) {
			std::cin.clear();
			clear_buffer();
		}
		if (temp[0] == '\0')
			break;
		strcpy(pa[items].fullname, temp);

//-------------------Hobby---------------------
		std::cout << "Enter hobby of student: ";
		if (!(std::cin.getline(pa[items].hobby, SLEN))) {
			std::cin.clear();
			clear_buffer();
		}

//-------------------Hobby---------------------
		std::cout << "Enter they OOP level: ";
		if (!(std::cin >> pa[items].ooplevel)) //to read '\n'
			break;
		clear_buffer();
	}
	if (std::cin.fail()) {
		std::cin.clear();
		clear_buffer();
	}
	return items;	
}

void display1(student st) {
	std::cout << "Display 1\n";
	std::cout << "Fullname: "  << st.fullname << ",\n"
						<< "Hobby: "     << st.hobby    << ",\n"
						<< "OOP level: " << st.ooplevel << ".\n\n";
}

void display2(const student* ps) {
	std::cout << "Display 2\n";
	std::cout << "Fullname: "  << ps->fullname << ",\n"
						<< "Hobby: "     << ps->hobby    << ",\n"
						<< "OOP level: " << ps->ooplevel << ".\n\n";
}

void display3(const student pa[], int n) {
	std::cout << "Display 3\n";
	for (int i = 0; i < n; ++i)
		display2(&pa[i]);
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		continue;
}
