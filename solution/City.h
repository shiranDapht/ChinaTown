#ifndef _CITY_H_
#define _CITY_H_

#include <string>
#include <set>
#include <memory>
#include <iostream>

#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "exceptions.h"

namespace mtm{

class CompareFaculties{
    public:
    bool operator()(const Faculty<Condition>& f1, const Faculty<Condition>& f2){
        return f1.getId() < f2.getId();
    }
};


class City
{
private:
    std::string city_name_t;
    std::set<Employee> employees_t;
    std::set<Manager> managers_t;
    std::set<Faculty<Condition>, CompareFaculties> faculties_t;
    std::set<Workplace> workplaces_t;
public:
    City(std::string city_name);
    City(const City& city) = delete;
    ~City() = default;

    void addEmployee(const int id, const std::string first_name, const std::string last_name, const int year);
    void addManager(const int id, const std::string first_name, const std::string last_name,const int year);
    template<class IsAccepted>
    void addFaculty(const int id,const Skill& skill, const int added_pointes, IsAccepted* isAccepted);
    void createWorkplace(int id, std::string name, double workers_salary, double managers_salary);
    void teachAtFaculty(const int employee_id, const int faculty_id);
    template<class Condition>
    void hireEmployeeAtWorkplace(const Condition cond, const int employee_id,const int manager_id, const int workplace_id);
    void hireManagerAtWorkplace(const int manager_id, const int workplace_id);
    void fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id);
    void fireManagerAtWorkplace(const int manager_id, const int workplace_id);
    int getAllAboveSalary(ostream& os, const int salary_bar);
    bool isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2);
    void printAllEmployeesWithSkill(ostream& os, const int id);
};

template<class IsAccepted>
void City::addFaculty(const int id,const Skill& skill, const int added_pointes, IsAccepted* isAccepted){
    for(const Faculty<Condition>& faculty : faculties_t){
        if(faculty.getId() == id){
            throw FacultyAlreadyExists();
        }
    }
    Faculty<Condition> new_faculty = Faculty<Condition>(id, isAccepted, skill, added_pointes);
    faculties_t.insert(new_faculty);
}


template<class Condition>
void City::hireEmployeeAtWorkplace(const Condition cond, const int employee_id,const int manager_id, const int workplace_id){
    for(const Employee& employee : employees_t){
        if(employee.getId() == employee_id){
            for(const Manager& manager : managers_t){
                if(manager.getId() == manager_id){
                    for(const Workplace& workplace : workplaces_t){
                        if(workplace.getId() == workplace_id){
                            Workplace new_workplace = Workplace(workplace);
                            new_workplace.hireEmployee(cond, &employee, manager.getId());
                            workplaces_t.erase(workplace);
                            workplaces_t.insert(new_workplace);
                        }
                    }
                    throw WorkplaceDoesNotExist();
                }
            }
            throw ManagerDoesNotExist();
        }
    }
    throw EmployeeDoesNotExist();
}


}

#endif