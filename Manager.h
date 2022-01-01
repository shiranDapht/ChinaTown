#ifndef _MANAGER_H_ 
#define _MANAGER_H_

#include "Citizen.h"
#include "exceptions.h"
#include "Employee.h"
#include <memory>
#include <set>

namespace mtm{
    class Manager : public Citizen
    {
    private:
        int salary_t;
        std::unique_ptr<std::set<Employee>>  employees_t;
    public:
        Manager();
        Manager(int id, string first_name, string last_name, int year, int salary):
            Citizen(id, first_name, last_name, year), salary_t(salary) {
                employees_t = std::unique_ptr<std::set<Employee>>(new std::set<Employee>());

            };
        Manager(const Manager& manager);
        ~Manager();

        int getSalary() const;

        void addEmployee(const Employee& employee);
        void removeEmployee(const int employee_id);
        void setSalary(const int add_salary);

        virtual ostream& printShort(const ostream& os);
        virtual ostream& printLong(const ostream& os);
    
        virtual Citizen& clone();
    };

}

#endif