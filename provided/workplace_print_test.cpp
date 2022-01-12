#include <iostream>
#include "../Workplace.h"
using namespace mtm;
using std::cout;
using std::endl;
class Condition{
public:
    bool operator()(Employee* emp){
        return emp->getId()>0;
    }
};
int main() {
    Workplace Meta(1,"Meta", 10000, 20000);
    Employee* e1 = new Employee(1, "John", "Williams", 2002);
    Employee* e2 = new Employee(2, "Alex", "Martinez", 2000);
    Manager* m1 = new Manager(1,"Robert", "stark", 1980);
    Meta.hireManager(m1);
    Condition condition;
    Meta.hireEmployee(condition,e1,m1->getId());
    Meta.hireEmployee(condition,e2,m1->getId());
    cout << Meta;
    Meta.fireEmployee(e1->getId(),m1->getId());
    Meta.fireManager(m1->getId());
    cout << "-----------" << endl;
    cout << Meta;
    return 0;
}
