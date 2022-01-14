#ifndef _FACULTY_H_
#define _FACULTY_H_

#include "exceptions.h"
#include "Skill.h"
#include "Employee.h"

namespace mtm{

    /**
     * @brief Abstract functor for acceptance conditions to Faculty.
     * 
     */
    class Condition{
        public:
        Condition() = default;
        ~Condition() = default;
        Condition(const Condition&) = default;
        virtual bool operator()(Employee* employee) = 0;
    };


    template<class Functor>
    class Faculty{   
    private:
        int id_t;
        Skill skill_t;
        int added_pointes_t;
        Functor* isAccepted_t;

    public:
        Faculty(int id, Skill skill, int added_pointes, Functor* isAccepted);
        Faculty(const Faculty& fac) = default;
        ~Faculty() = default;

        /**
         * @brief Get the Added Points
         * 
         * @return int 
         */
        int getAddedPoints() const;
        /**
         * @brief Get the Id
         * 
         * @return int 
         */
        int getId() const;
        /**
         * @brief Get the Skill
         * 
         * @return Skill 
         */
        Skill getSkill() const;
        /**
         * @brief add faculty skill to employee
         * 
         * @param employee 
         */
        void teach(Employee* employee) const;
    };



    template<class Functor>
    Faculty<Functor>::Faculty(int id, Skill skill, int added_pointes, Functor* isAccepted): 
        id_t(id), skill_t(skill), isAccepted_t(isAccepted), added_pointes_t(added_pointes){}

    template<class Functor>
    int Faculty<Functor>::getAddedPoints() const{
        return added_pointes_t;
    }

    template<class Functor>
    int Faculty<Functor>::getId() const{
        return id_t;
    }

    template<class Functor>
    Skill Faculty<Functor>::getSkill() const{
        return skill_t;
    }

    template<class Functor>
    void Faculty<Functor>::teach(Employee* employee) const{
        if((*isAccepted_t)(employee)){
            employee->learnSkill(getSkill());
            employee->setScore(getAddedPoints());
        }
        else{
            throw EmployeeNotAccepted();
        }
    }

}

#endif