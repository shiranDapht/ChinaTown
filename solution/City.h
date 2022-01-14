#ifndef _CITY_H_
#define _CITY_H_

#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "exceptions.h"

#include <string>
#include <iostream>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::ostream;


namespace mtm{

    class City{
    private:
        string city_name_t;
        vector<shared_ptr<Employee>> employees_t;
        vector<shared_ptr<Manager>> managers_t;
        vector<shared_ptr<Faculty<Condition>>> faculties_t;
        vector<shared_ptr<Workplace>> workplaces_t;

        /**
         * @brief Get Employee By Id
         * 
         * @param id 
         * @return Employee pointer, if not exists nullptr
         */
        shared_ptr<Employee> getEmployeeByIdOrNullptr(const int id);

        /**
         * @brief Get Manager By Id
         * 
         * @param id 
         * @return Manager pointer, if not exists nullptr
         */
        shared_ptr<Manager> getManagerByIdOrNullptr(const int id);

        /**
         * @brief Get Faculty By Id
         * 
         * @param id 
         * @return Faculty<Condition>*, if not exists nullptr
         */
        shared_ptr<Faculty<Condition>> getFacultyByIdOrNullptr(const int id);

        /**
         * @brief Get Workplace By Id
         * 
         * @param id 
         * @return Workplace pointer, if not exists nullptr
         */
        shared_ptr<Workplace> getWorkplaceByIdOrNullptr(const int id);

        /**
         * @brief Get Employee By Id
         * 
         * @param id 
         * @return const Employee*, if does not exist throw exception
         */
        shared_ptr<Employee> getEmployeeById(const int id);

        /**
         * @brief Get Manager By Id
         * 
         * @param id 
         * @return const Manager*, if does not exist throw exception
         */
        shared_ptr<Manager> getManagerById(const int id);

        /**
         * @brief Get Workplace By Id
         * 
         * @param id 
         * @return const Workplace*, if does not exist throw exception
         */
        shared_ptr<Workplace> getWorkplaceById(const int id);

        /**
         * @brief Get Faculty By Id
         * 
         * @param id 
         * @return Faculty<Condition>*, if does not exist throw exception
         */
        shared_ptr<Faculty<Condition>> getFacultyById(const int id);

    public:
        City(string city_name);
        City(const City& city) = delete;
        ~City() = default;

        /**
         * @brief Create Employee and add to city
         * 
         * @param id 
         * @param first_name 
         * @param last_name 
         * @param year 
         */
        void addEmployee(const int id, const string first_name, const string last_name, const int year);

        /**
         * @brief Create Manager and add to city
         * 
         * @param id 
         * @param first_name 
         * @param last_name 
         * @param year 
         */
        void addManager(const int id, const string first_name, const string last_name,const int year);

        /**
         * @brief Create Faculty and add to city
         * 
         * @tparam IsAccepted Functor derived from mtm::Condition that defines acceptance criteria.
         * @param id 
         * @param skill 
         * @param added_pointes 
         * @param isAccepted 
         */
        template<class IsAccepted>
        void addFaculty(const int id,const Skill& skill, const int added_pointes, IsAccepted* isAccepted);

        /**
         * @brief Create Workplace and add to city
         * 
         * @param id 
         * @param name 
         * @param workers_salary 
         * @param managers_salary 
         */
        void createWorkplace(int id, string name, int workers_salary, int managers_salary);

        /**
         * @brief Teaches an Employee a skill of the Faculty
         * 
         * @param employee_id - mtm::Employee id
         * @param faculty_id - mtm::Faculty id
         */
        void teachAtFaculty(const int employee_id, const int faculty_id);

        /**
         * @brief Adds Employee to Workplace under Manager all from city at the city if Employee 
         *        fits the hiring Condition
         * 
         * @tparam Condition - Functor of the form: bool functor(Employee*)
         * @param cond 
         * @param employee_id 
         * @param manager_id 
         * @param workplace_id 
         */
        template<class Condition>
        void hireEmployeeAtWorkplace(const Condition cond,const int employee_id
            ,const int manager_id,const int workplace_id);

        /**
         * @brief Adds manager from city to given workplace
         * 
         * @param manager_id 
         * @param workplace_id 
         */
        void hireManagerAtWorkplace(const int manager_id, const int workplace_id);

        /**
         * @brief remove Employee and update its salary
         * 
         * @param employee_id 
         * @param manager_id 
         * @param workplace_id 
         */
        void fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id);
        
        /**
         * @brief remove Manager and update its salary
         * 
         * @param manager_id 
         * @param workplace_id 
         */
        void fireManagerAtWorkplace(const int manager_id, const int workplace_id);

        /**
         * @brief short print all citizens with salary above salary_bar into os
         * 
         * @param os 
         * @param salary_bar 
         * @return int 
         */
        int getAllAboveSalary(ostream& os, const int salary_bar) const;

        /**
         * @brief Checks if two employees work at the same Workplace
         * 
         * @param employee_id1 
         * @param employee_id2 
         * @return boolean 
         */
        bool isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2) const;

        /**
         * @brief short print all employees with skill of id into os.
         * 
         * @param os 
         * @param id 
         */
        void printAllEmployeesWithSkill(ostream& os, const int id) const;

    };


    template<class IsAccepted>
    void City::addFaculty(const int id, const Skill& skill, const int added_pointes, IsAccepted* isAccepted){
        if(getFacultyByIdOrNullptr(id) == nullptr){

            faculties_t.push_back(shared_ptr<Faculty<Condition>>(new Faculty<Condition>(id, skill, added_pointes, isAccepted)));
            return;
        }
        throw FacultyAlreadyExists();
    }


    template<class Condition>
    void City::hireEmployeeAtWorkplace(const Condition cond, const int employee_id,
                        const int manager_id, const int workplace_id){
        getManagerById(manager_id);
        getWorkplaceById(workplace_id)->hireEmployee(cond, getEmployeeById(employee_id).get(), manager_id);
    }

}

#endif