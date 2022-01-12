#ifndef _WORKPLACE_H_
#define _WORKPLACE_H_

#include "Manager.h"
#include "exceptions.h"
#include <string>
#include <set>
#include <iostream>
namespace mtm{

    class Workplace
    {
    private:
        int id_t;
        std::string name_t;
        double workers_salary_t;
        double managers_salary_t;
        std::set<Manager*> managers_set_t;

        /**
         * @brief Get the Manager By Id
         * 
         * @param id 
         * @return Manager pointer 
         */
        Manager* getManagerByIdOrNullptr(const int id) const;

    public:
        Workplace(int id, std::string name, double workers_salary, double managers_salary);
        Workplace(const Workplace& workplace) = default;
        ~Workplace() = default;

        /**
         * @brief Chack if employee work here
         * 
         * @param id 
         * @return boolean
         */
        bool isEmployeeWorkingHere(int id) const;
        /**
         * @brief Get the Managers Salary at this workplace
         * 
         * @return double 
         */
        double getManagersSalary() const;
        /**
         * @brief Get the Workers Salary at this workplace
         * 
         * @return double 
         */
        double getWorkersSalary() const;
        /**
         * @brief Get the Name of this workplace
         * 
         * @return std::string 
         */
        std::string getName() const;
        /**
         * @brief Get the Id of this workplace
         * 
         * @return int 
         */
        int getId() const;
        /**
         * @brief Check if the employee can wokr at this workplace
         * 
         * @tparam IsAcceptedToWorkFunctor 
         * @param isAccepted 
         * @param employee 
         * @param manager_id 
         */
        template<class IsAcceptedToWorkFunctor> 
        void hireEmployee(IsAcceptedToWorkFunctor isAccepted, Employee* employee, int manager_id);
        /**
         * @brief hire a given manager into workplace
         * 
         * @param manager 
         */
        void hireManager(Manager* manager);
        /**
         * @brief fire a given employee from a given manager
         * 
         * @param employee_id 
         * @param manager_id 
         */
        void fireEmployee(int employee_id, int manager_id);
        /**
         * @brief fire a given manager
         * 
         * @param manager_id 
         */
        void fireManager(int manager_id);
        
        friend std::ostream& operator<<(std::ostream& os, Workplace& workplace);

        /**
         * @brief Get the Manager By Id object
         * 
         * @param id 
         * @return Manager*, If manager does not exist throw ManagerIsNotHired
         */
        Manager* getManagerById(const int id) const;
    };

    template<class IsAcceptedToWorkFunctor>
    void Workplace::hireEmployee(IsAcceptedToWorkFunctor isAccepted, Employee* employee, int manager_id){
        if(!isAccepted(employee)){
            throw EmployeeNotSelected();
        }
        getManagerById(manager_id)->addEmployee(employee);
        employee->setSalary(getWorkersSalary());
    }



}
#endif