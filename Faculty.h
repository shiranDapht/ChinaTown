#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "Skill.h"
#include <functional>
#include "Employee.h"

namespace mtm{

class Faculty
{
    
private:

    int id_t;
    Skill skill_t;
    int added_pointes_t;
    std::function<bool (Employee)> isAccepted_t;
public:
    Faculty(int id, std::function<bool (Employee)> isAccepted, Skill skill, int added_pointes);
    Faculty(const Faculty& fac);
    ~Faculty();

    int getAddedPoints() const;
    int getId() const;
    Skill getSkill() const;
    void teach(Employee& employee) const;
};


}

#endif