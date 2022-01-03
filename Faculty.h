#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "Skill.h"
#include "Employee.h"

namespace mtm{
class Condition{
    public:
    virtual bool operator()(Employee* employee) = 0;
};


template<class IsAcceptedFunctor>
class Faculty
{
    
private:

    int id_t;
    Skill skill_t;
    int added_pointes_t;
    IsAcceptedFunctor isAccepted_t;
public:
    Faculty(int id, IsAcceptedFunctor isAccepted, Skill skill, int added_pointes);
    Faculty(const Faculty& fac);
    ~Faculty();

    int getAddedPoints() const;
    int getId() const;
    Skill getSkill() const;
    void teach(Employee& employee) const;
};


}

#endif