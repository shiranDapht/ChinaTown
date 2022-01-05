#ifndef _EMPLOYEE_H_ 
#define _EMPLOYEE_H_

#include <memory>
#include "Citizen.h"
#include "Skill.h"
#include "exceptions.h"
#include <set>


namespace mtm{
    class Employee : public Citizen
    {
    private:
        int salary_t;
        int score_t;
        std::set<Skill> skills_t;

    public:

        Employee(const int id, const std::string first_name, const std::string last_name, const int year);
        ~Employee() = default;
        Employee(const Employee& employee) = default;

        int getSalary() const;
        int getScore() const;

        void learnSkill(const Skill skill);
        void forgetSkill(const int skill_id);
        bool hasSkill(const int skill_id) const;
        void setSalary(const int add_salary);
        void setScore(const int add_score);

        virtual ostream& printShort(ostream& os) const override;
        virtual ostream& printLong(ostream& os) const override;
    
        virtual Employee* clone() override;

        ostream& printSkills(ostream& os) const;
    };
}

#endif 