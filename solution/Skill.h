#ifndef _SKILL_H
#define _SKILL_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;
namespace mtm{
    class Skill
    {
    private:
        int id_t;
        string name_t;
        int required_points_t;
        
    public:
        Skill(int id, string name, int required_points);
        Skill(const Skill& skill);
        ~Skill() = default;

        /**
         * @brief Get the Id object
         * 
         * @return int 
         */
        int getId() const;

        /**
         * @brief Get the Required Points object
         * 
         * @return int 
         */
        int getRequiredPoints() const;

        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        string getName() const;

        friend ostream& operator<<(ostream& os, const Skill& skill);
        bool operator>(const Skill& rvalue) const;
        bool operator<(const Skill& rvalue) const;
        bool operator>=(const Skill& rvalue) const;
        bool operator<=(const Skill& rvalue) const;
        bool operator==(const Skill& rvalue) const;
        bool operator!=(const Skill& rvalue) const;
        Skill operator++(int);
        Skill& operator+=(int points);
        friend Skill operator+(const Skill& skill, int points);
        friend Skill operator+(int points, const Skill& skill);
    };
}
#endif