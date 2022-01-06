#ifndef _MANAGER_H_ 
#define _MANAGER_H_

#include "Citizen.h"
#include "exceptions.h"
#include "Employee.h"
#include <memory>
#include <set>

using std::string;
namespace mtm{
    

class Manager : public CitizenPlus
{
private:
    std::set<Employee> employees_t;
    bool is_hired_t;

public:
    Manager(int id, std::string first_name, std::string last_name, int year);
    Manager(const Manager& manager) = default;
    ~Manager() = default;

    void addEmployee(const Employee* employee);
    void removeEmployee(const int employee_id);

    virtual ostream& printShort(ostream& os) const override;
    virtual ostream& printLong(ostream& os) const override;

    virtual Manager* clone() const override;

    bool isEmployeeHere(int id) const;
    bool getIsHired() const;
    void setIsHired(const bool is_hired);
    ostream& printEmployees(ostream& os) const;
};

}

#endif