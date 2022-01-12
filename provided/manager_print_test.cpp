#include <iostream>
#include "../Employee.h"
#include "../Manager.h"

using namespace mtm;
using std::cout;
using std::endl;

int main() {
    Employee e1(1, "John", "Williams", 2002);
    Skill s1(1,"C++",0);
    Skill s2(2, "Java", 0);
    Employee e2(2, "Alex", "Martinez", 2000);
    e1.learnSkill(s1);
    e1.learnSkill(s2);
    e2.learnSkill(s2);
    Manager m1(1,"Robert", "stark", 1980);
    cout << "Short Print" << endl;
    m1.printShort(cout);
    cout << "Long Print" << endl;
    m1.printLong(cout);
    cout << "----------" << endl;
    m1.addEmployee(&e1);
    m1.addEmployee(&e2);
    cout << "Short Print" << endl;
    m1.printShort(cout);
    m1.setSalary(10000);
    cout << "Long Print" << endl;
    m1.printLong(cout);
    return 0;
}