#ifndef _WORKPLACE_H_
#define _WORKPLACE_H_

#include <string>
#include <set>
#include "Manager.h"
namespace mtm{

class Workplace
{
private:
    int id_t;
    std::string name_t;
    double workers_salary_t;
    double managers_salary_t;
    std::set<Manager*> managers_set_t;
public:
    Workplace(int id, std::string name, double workers_salary, double managers_salary);
    Workplace(const Workplace& workplace) = default;
    ~Workplace() = default;

    bool isEmployeeWorkingHere(int id) const;
    double getManagersSalary() const;
    double  getWorkersSalary() const;
    std::string getName() const;
    int getId() const;
    template<class IsAcceptedToWorkFunctor> void hireEmployee(IsAcceptedToWorkFunctor isAccepted, Employee* employee, int manager_id);
    void hireManager(Manager* manager);
    void fireEmployee(int employee_id, int manager_id);
    void fireManager(int manager_id);
    bool operator<(const Workplace& workplace) const;
    friend ostream& operator<<(ostream& os, Workplace& workplace);

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