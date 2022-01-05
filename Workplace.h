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
    std::set<Manager> managers_set_t;
public:
    Workplace(int id, std::string name, double workers_salary, double managers_salary);
    Workplace(Workplace& workplace) = delete;
    ~Workplace() = default;

    double getManagersSalary() const;
    double  getWorkersSalary() const;
    std::string getName() const;
    int getID() const;
    template<class IsAcceptedToWorkFunctor> void hireEmployee(IsAcceptedToWorkFunctor isAccepted, Employee* employee, int manager_id);
    void hireManager(Manager* manager);
    void fireEmployee(int employee_id, int manager_id);
    void fireManager(int manager_id);
    friend ostream& operator<<(ostream& os, Workplace& workplace);
};





}
#endif