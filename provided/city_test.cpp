#include <iostream>
#include "../Employee.h"
#include "../Manager.h"
#include "../Faculty.h"
#include "../Workplace.h"
#include "../City.h"

using namespace mtm;
using std::cout;
using std::endl;

class FacultyCondition1: public Condition{
    bool operator()(Employee* employee) override{
        return employee->getId() > 0;
    }
};

class FacultyCondition2: public Condition{
    bool operator()(Employee* employee) override{
        return employee->getId() > 3;
    }
};

class HiringCondition {
public:
    bool operator()(Employee *emp) {
        return emp->getScore() > 5;
    }
};


int main() {
    City city ("TLV");
    Skill skill1(1,"Programming with c++",0);
    Skill skill2(2,"Programming with c",10);
    city.addEmployee(11, "John", "Williams", 2002);
    city.addEmployee(12, "Alex", "Martinez", 2000);
    city.addEmployee(13, "Lionel", "Smith", 2000);
    city.addManager(104,"Mohamad","Masarwa",1998);
    FacultyCondition1 fc1;
    FacultyCondition2 fc2;
    city.addFaculty(1001, skill1, 10, &fc1);
    city.addFaculty(1002, skill2, 15, &fc2);
    city.teachAtFaculty(11,1001);
    city.teachAtFaculty(11,1002);
    city.teachAtFaculty(12,1001);
    city.teachAtFaculty(13,1001);
    city.createWorkplace(10001, "Meta", 10000, 20000);
    city.hireManagerAtWorkplace(104,10001);
    HiringCondition hiringCondition;
    city.hireEmployeeAtWorkplace(hiringCondition, 11, 104, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition, 12, 104, 10001);
    city.hireEmployeeAtWorkplace(hiringCondition, 13, 104, 10001);
    city.fireEmployeeAtWorkplace(12,104,10001);
    cout << "getAllAboveSalary output: " << endl;
    city.getAllAboveSalary(cout,1000);
    cout << endl << "printAllEmployeesWithSkill output" << endl;
    city.printAllEmployeesWithSkill(cout, 1);
    city.fireManagerAtWorkplace(104,10001);
    cout << "getAllAboveSalary output: " << endl;
    city.getAllAboveSalary(cout,1000);
    cout << endl << "printAllEmployeesWithSkill output" << endl;
    city.printAllEmployeesWithSkill(cout, 1);
    return 0;
}
