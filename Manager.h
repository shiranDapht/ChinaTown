#ifndef _MANAGER_H_ 
#define _MANAGER_H_

#include "Citizen.h"
#include "exceptions.h"
#include "Employee.h"
#include <memory>
#include <set>

using std::string;
namespace mtm{
    

class Manager : public Citizen
{
private:
    int salary_t;
    std::set<Employee> employees_t;
public:
    Manager(int id, std::string first_name, std::string last_name, int year, int salary);
    Manager(const Manager& manager) = default;
    ~Manager() = default;

    int getSalary() const;

    void addEmployee(const Employee& employee) const;
    void removeEmployee(const int employee_id);
    void setSalary(const int add_salary);

    virtual ostream& printShort(const ostream& os);
    virtual ostream& printLong(const ostream& os);

    virtual Manager* clone();
};

}

#endif