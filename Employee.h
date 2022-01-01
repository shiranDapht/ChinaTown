#ifndef _EMPLOYEE_H_ 
#define _EMPLOYEE_H_

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
        Employee();
        Employee(int id, string first_name, string last_name, int year, int salary, int score,
            std::set<Skill> skills) : Citizen(id, first_name, last_name, year), salary_t(salary),
            score_t(score), skills_t(skills) {};
        ~Employee();
        Employee(const Employee& employee);

        int getSalary() const;
        int getScore() const;

        void learnSkill(const Skill skill);
        void forgetSkill(const int skill_id);
        bool hasSkill(const int skill_id) const;
        void setSalary(const int add_salary);
        void setScore(const int add_score);

        virtual ostream& printShort(const ostream& os);
        virtual ostream& printLong(const ostream& os);
    
        virtual Citizen& clone();
    };
}

#endif 