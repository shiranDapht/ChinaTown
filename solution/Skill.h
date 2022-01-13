#ifndef _SKILL_H
#define _SKILL_H

#include <string>
namespace mtm{
    class Skill
    {
    private:
        int id_t;
        int required_points_t;
        std::string name_t;
    public:
        Skill(int id, std::string name, int required_points);
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
        std::string getName() const;

        friend std::ostream& operator<<(std::ostream& os, const Skill& skill);
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
    Skill operator+(const Skill& skill, int points);
    Skill operator+(int points, const Skill& skill);
}
#endif