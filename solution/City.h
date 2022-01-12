#ifndef _CITY_H_
#define _CITY_H_

#include <string>
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

    class City{
    private:
        std::string city_name_t;
        std::vector<Employee> employees_t;
        std::vector<Manager> managers_t;
        std::vector<Faculty<Condition>> faculties_t;
        std::vector<Workplace> workplaces_t;

        /**
         * @brief Get Employee By Id
         * 
         * @param id 
         * @return Employee poiner, if not exists nullptr
         */
        Employee* getEmployeeByIdOrNullptr(const int id);

        /**
         * @brief Get Manager By Id
         * 
         * @param id 
         * @return Manager poiner, if not exists nullptr
         */
        Manager* getManagerByIdOrNullptr(const int id);

        /**
         * @brief Get Faculty By Id
         * 
         * @param id 
         * @return Faculty<Condition>*, if not exists nullptr
         */
        Faculty<Condition>* getFacultyByIdOrNullptr(const int id);

        /**
         * @brief Get Workplace By Id
         * 
         * @param id 
         * @return Workplace poiner, if not exists nullptr
         */
        Workplace* getWorkplaceByIdOrNullptr(const int id);

        /**
         * @brief Get Employee By Id
         * 
         * @param id 
         * @return const Employee*, if does not exist throw exception
         */
        Employee* getEmployeeById(const int id);

        /**
         * @brief Get Manager By Id
         * 
         * @param id 
         * @return const Manager*, if does not exist throw exception
         */
        Manager* getManagerById(const int id);

        /**
         * @brief Get Workplace By Id
         * 
         * @param id 
         * @return const Workplace*, if does not exist throw exception
         */
        Workplace* getWorkplaceById(const int id);

        /**
         * @brief Get Faculty By Id
         * 
         * @param id 
         * @return Faculty<Condition>*, if does not exist throw exception
         */
        Faculty<Condition>* getFacultyById(const int id);

    public:
        City(std::string city_name);
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
        void addEmployee(const int id, const std::string first_name, const std::string last_name, const int year);

        /**
         * @brief Create Manager and add to city
         * 
         * @param id 
         * @param first_name 
         * @param last_name 
         * @param year 
         */
        void addManager(const int id, const std::string first_name, const std::string last_name,const int year);

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
        void createWorkplace(int id, std::string name, double workers_salary, double managers_salary);

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
        int getAllAboveSalary(std::ostream& os, const int salary_bar) const;

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
        void printAllEmployeesWithSkill(std::ostream& os, const int id) const;

    };


    template<class IsAccepted>
    void City::addFaculty(const int id,const Skill& skill, const int added_pointes, IsAccepted* isAccepted){
        if(getFacultyByIdOrNullptr(id) == nullptr){
            faculties_t.push_back(Faculty<Condition>(id, isAccepted, skill, added_pointes));
            return;
        }
        throw FacultyAlreadyExists();
    }


    template<class Condition>
    void City::hireEmployeeAtWorkplace(const Condition cond, const int employee_id,
                        const int manager_id, const int workplace_id){
        getManagerById(manager_id);
        getWorkplaceById(workplace_id)->hireEmployee(cond, getEmployeeById(employee_id), manager_id);
    }


}

#endif