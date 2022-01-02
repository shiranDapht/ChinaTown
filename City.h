#ifndef _CITY_H_
#define _CITY_H_

#include <string>
#include "exceptions.h"
#include <set>
#include <memory>
#include <iostream>

#include "Manager.h"
#include "Employee.h"
#include "Faculty.h"
#include "Workplace.h"

typedef std::string string;
typedef std::ostream ostream;

namespace mtm{
class City
{
private:
    string city_name_t;
    std::unique_ptr<std::set<Employee>> employees_t;
    std::unique_ptr<std::set<Manager>> managers_t;
    std::unique_ptr<std::set<Faculty>> faculties_t;
    std::unique_ptr<std::set<Workplace>> workplaces_t;
public:
    City(string city_name){
        city_name_t = city_name;
        employees_t = std::unique_ptr<std::set<Employee>>(new std::set<Employee>());
        managers_t = std::unique_ptr<std::set<Manager>>(new std::set<Manager>());
        faculties_t = std::unique_ptr<std::set<Faculty>>(new std::set<Faculty>());
        workplaces_t = std::unique_ptr<std::set<Workplace>>(new std::set<Workplace>());
    };
    City(const City& city){

    }
    ~City();

    ostream& operator>>(const ostream& os);

    void addEmployee(const int id, const string first_name,const string last_name, const int year);
    void addManager(const int id,const string first_name,const string last_name,const int year);
    void addFculty(const int id,const std::function<bool (Employee)> isAccepted, const Skill skill, const int added_pointes);
    void createWorkplace();
    void teachAtFaculty(const int employee_id, const int faculty_id);
    typedef bool (*condition)(Employee employee);
    void hireEmployeeAtWorkplace(const condition cond, const int employee_id,const int manager_id, const int workplace_id);
    void hireManagerAtWorkplace(const int manager_id, const int workplace_id);
    void fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id);
    void fireManagerAtWorkplace(const int manager_id, const int workplace_id);
    int getAllAboveSalary(const ostream& os, const int salary_bar);
    bool isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2);
    void printAllEmployeesWithSkill(const ostream& os, const Skill skill);
};

}

#endif