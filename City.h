#ifndef _CITY_H_
#define _CITY_H_

#include <string>
#include <set>
#include <memory>
#include <iostream>

#include "Manager.h"
#include "Employee.h"
#include "Faculty.h"
#include "Workplace.h"
#include "exceptions.h"

namespace mtm{
class City
{
private:
    std::string city_name_t;
    std::set<Employee> employees_t;
    std::set<Manager> managers_t;
    std::set<Faculty<Condition>> faculties_t;
    std::set<Workplace> workplaces_t;
public:
    City(std::string city_name);
    City(const City& city) = delete;
    ~City() = default;

    void addEmployee(const int id, const std::string first_name, const std::string last_name, const int year);
    void addManager(const int id, const std::string first_name, const std::string last_name,const int year);
    template<class IsAccepted>
    void addFaculty(const int id,const IsAccepted isAccepted, const Skill skill, const int added_pointes);
    void createWorkplace(int id, std::string name, double workers_salary, double managers_salary);
    void teachAtFaculty(const int employee_id, const int faculty_id);
    template<class Condition>
    void hireEmployeeAtWorkplace(const Condition cond, const int employee_id,const int manager_id, const int workplace_id);
    void hireManagerAtWorkplace(const int manager_id, const int workplace_id);
    void fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id);
    void fireManagerAtWorkplace(const int manager_id, const int workplace_id);
    int getAllAboveSalary(const ostream& os, const int salary_bar);
    bool isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2);
    void printAllEmployeesWithSkill(const ostream& os, const Skill skill);
};

}

#endif