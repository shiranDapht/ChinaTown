#ifndef _EMPLOYEE_H_ 
#define _EMPLOYEE_H_

#include <memory>
#include "Citizen.h"
#include "Skill.h"
#include "exceptions.h"
#include <set>


namespace mtm{
    class Employee : public CitizenPlus
    {
    private:
        int score_t;
        std::set<Skill> skills_t;

    public:

        Employee(const int id, const std::string first_name, const std::string last_name, const int year);
        ~Employee() = default;
        Employee(const Employee& employee) = default;


        int getScore() const;
        void learnSkill(const Skill skill);
        void forgetSkill(const int skill_id);
        bool hasSkill(const int skill_id) const;
        void setScore(const int add_score);

        virtual ostream& printShort(ostream& os) const override;
        virtual ostream& printLong(ostream& os) const override;
    
        virtual Employee* clone() const override;

        ostream& printSkills(ostream& os) const;
    };
}

#endif 