#include "City.h"
#include "Manager.h"
#include "Employee.h"
#include "Faculty.h"
#include "Workplace.h"
#include "exceptions.h"

#include <string>

namespace mtm{

City::City(std::string city_name) : city_name_t(city_name), employees_t(std::set<Employee>()),
    managers_t(std::set<Manager>()), faculties_t(std::set<Faculty<Condition>>()), 
    workplaces_t(std::set<Workplace>()){};

void City::addEmployee(const int id, const std::string first_name, const std::string last_name, const int year){
    Employee new_employee = Employee(id, first_name, last_name, year);
    if(employees_t.find(new_employee) != employees_t.end()){
        throw EmployeeAlreadyExists();
    }
    employees_t.insert(new_employee);
}

void City::addManager(const int id, const std::string first_name, const std::string last_name, const int year){
    Manager new_manager = Manager(id, first_name, last_name, year);
    if(managers_t.find(new_manager) != managers_t.end()){
        throw ManagerAlreadyExists();
    }
    managers_t.insert(new_manager);
}

template<class IsAccepted>
void City::addFaculty(const int id,const IsAccepted isAccepted, const Skill skill, const int added_pointes){
    Faculty<IsAccepted> new_faculty = Faculty<IsAccepted>(id, isAccepted, skill, added_pointes);
    if(faculties_t.find(new_faculty) != faculties_t.end()){
        throw FacultyAlreadyExists();
    }
    faculties_t.insert(new_faculty);
}

void City::createWorkplace(int id, std::string name, double workers_salary, double managers_salary){
    Workplace new_workplace = Workplace(id, name, workers_salary, managers_salary);
    if(workplaces_t.find(new_workplace) != workplaces_t.end()){
        throw WorkplaceAlreadyExists();
    }
    workplaces_t.insert(new_workplace);
}

void City::teachAtFaculty(const int employee_id, const int faculty_id){}

template<class Condition>
void City::hireEmployeeAtWorkplace(const Condition cond, const int employee_id,const int manager_id, const int workplace_id){}

void City::hireManagerAtWorkplace(const int manager_id, const int workplace_id){}

void City::fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id){}

void City::fireManagerAtWorkplace(const int manager_id, const int workplace_id){}

int City::getAllAboveSalary(const ostream& os, const int salary_bar){}

bool City::isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2){}

void City::printAllEmployeesWithSkill(const ostream& os, const Skill skill){}

}