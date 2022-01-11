#ifndef _CITY_H_
#define _CITY_H_

#include <string>
#include <set>
#include <memory>
#include <iostream>
#include <vector>

#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "exceptions.h"

namespace mtm{

class City
{
private:
    std::string city_name_t;
    std::vector<Employee> employees_t;
    std::vector<Manager> managers_t;
    std::vector<Faculty<Condition>> faculties_t;
    std::vector<Workplace> workplaces_t;
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

    /**
     * @brief Get the Employee By Id object
     * 
     * @param id 
     * @return const Employee*, if does not exist throw exception
     */
    Employee* getEmployeeById(const int id);

    /**
     * @brief Get the Manager By Id object
     * 
     * @param id 
     * @return const Manager*, if does not exist throw exception
     */
    Manager* getManagerById(const int id);

    /**
     * @brief Get the Workplace By Id object
     * 
     * @param id 
     * @return const Workplace*, if does not exist throw exception
     */
    Workplace* getWorkplaceById(const int id);

    /**
     * @brief Get the Faculty By Id object
     * 
     * @param id 
     * @return Faculty<Condition>*, if does not exist throw exception
     */
    Faculty<Condition>* getFacultyById(const int id);
};

template<class IsAccepted>
void City::addFaculty(const int id,const Skill& skill, const int added_pointes, IsAccepted* isAccepted){
    try{
        getFacultyById(id);
        throw FacultyAlreadyExists();
    }
    catch(FacultyDoesNotExist&){
        faculties_t.push_back(Faculty<Condition>(id, isAccepted, skill, added_pointes));
    }
}


template<class Condition>
void City::hireEmployeeAtWorkplace(const Condition cond, const int employee_id,const int manager_id, const int workplace_id){
    getManagerById(manager_id);
    getWorkplaceById(workplace_id)->hireEmployee(cond, getEmployeeById(employee_id), manager_id);
}


}

#endif