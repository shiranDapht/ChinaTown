#ifndef _EMPLOYEE_H_ 
#define _EMPLOYEE_H_

#include "Citizen.h"
#include "Skill.h"
#include <string>
#include <iostream>
#include <set>


namespace mtm{
    class Employee : public CitizenPlus
    {
    private:
        int score_t;
        std::set<Skill> skills_t;

        /**
         * @brief print the skills of this employee
         * 
         * @param os 
         * @return ostream& 
         */
        std::ostream& printSkills(std::ostream& os) const;

    public:

        Employee(const int id, const std::string first_name, const std::string last_name, const int year);
        virtual ~Employee() override = default;
        Employee(const Employee& employee) = default;

        /**
         * @brief Get the Score
         * 
         * @return int 
         */
        int getScore() const;
        /**
         * @brief adds skill to employee
         * 
         * @param skill 
         */
        void learnSkill(const Skill skill);
        /**
         * @brief remove skill of skill_id from employee
         * 
         * @param skill_id 
         */
        void forgetSkill(const int skill_id);
        /**
         * @brief checks if employee has skill of skill_id
         * 
         * @param skill_id 
         * @return boolean
         */
        bool hasSkill(const int skill_id) const;
        /**
         * @brief Set the Score
         * 
         * @param add_score 
         */
        void setScore(const int add_score);

        /**
         * @brief prints to os full name, salary and score
         * 
         * @param os 
         * @return ostream& 
         */
        virtual std::ostream& printShort(std::ostream& os) const override;
        /**
         * @brief prints to os full name, id, birth year, salary, score and all skills
         * 
         * @param os 
         * @return ostream& 
         */
        virtual std::ostream& printLong(std::ostream& os) const override;
    
        virtual Employee* clone() const override;

    };
}

#endif 