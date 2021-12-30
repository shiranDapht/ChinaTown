#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "Skill.h"
typedef int Employee;// Very temporary typedef!!!!

namespace mtm{

class Faculty
{
private:
    int id;
    bool (*isAccepted)(Employee);
    Skill skill;
    int added_pointes;
public:
    Faculty(int id, bool (*isAccepted)(Employee), Skill skill, int added_pointes);
    Faculty(const Faculty& fac);
    ~Faculty();

    int getAddedPoints();
    int getId();
    Skill getSkill();
    void teach(Employee emp);
};


}

#endif