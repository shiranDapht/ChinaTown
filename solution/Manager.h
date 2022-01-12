#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Citizen.h"
#include "Employee.h"
#include <set>
#include <string>
#include <iostream>

namespace mtm
{

    class Manager : public CitizenPlus
    {
    private:
        std::set<Employee*> employees_t;
        bool is_hired_t;

        /**
         * @brief print a list of employees working under this manager
         * 
         * @param os 
         * @return std::ostream& 
         */
        std::ostream& printEmployees(std::ostream &os) const;
        /**
         * @brief Get the Employee By Id
         * 
         * @param id 
         * @return Employee pointer, nullptr if employee doesn't work under this manager 
         */
        Employee* getEmployeeByIdOrNullptr(const int id) const;

    public:
        Manager(int id, std::string first_name, std::string last_name, int year);
        Manager(const Manager &manager) = default;
        ~Manager() = default;

        /**
         * @brief add Employee under Manager
         *
         * @param employee
         */
        void addEmployee(Employee* employee);
        /**
         * @brief remove Employee from Manager
         *
         * @param employee_id
         */
        void removeEmployee(const int employee_id);

        /**
         * @brief print to os full name and salary
         *
         * @param os
         * @return ostream&
         */
        virtual std::ostream& printShort(std::ostream& os) const override;
        /**
         * @brief print to os full name, id, birth year, salary and short print all Employees under manager
         *
         * @param os
         * @return ostream&
         */
        virtual std::ostream& printLong(std::ostream& os) const override;

        virtual Manager* clone() const override;
        //Custom methods
        /**
         * @brief checks if Employee works under Manager
         *
         * @param id
         * @return boolean
         */
        bool isEmployeeHere(int id) const;
        /**
         * @brief Get the is_hired
         * 
         * @return true 
         * @return false 
         */
        bool getIsHired() const;
        /**
         * @brief Change the manager working status
         * 
         * @param boolien 
         */
        void setIsHired(const bool is_hired);

        /**
         * @brief Get Employee By Id
         *
         * @param id
         * @return const Employee*, if employee doesn't exist return nullptr
         */
        Employee* getEmployeeById(const int id) const;

        /**
         * @brief fire all employees of manager
         * 
         * @param salary 
         */
        void fireAllEmployees(const double salary);
    };

}

#endif