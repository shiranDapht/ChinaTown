#ifndef _SKILL_H
#define _SKILL_H

#include <string>
namespace mtm{
class Skill
{
private:
    int id;
    int required_points;
    std::string name;
public:
    Skill(int id, std::string name, int required_points);
    Skill(const Skill& skill);
    ~Skill();

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

    friend std::ostream& operator<<(std::ostream& os, const Skill& skill); // Note that this is not a memeber function, rather it is defined as a friend.
    bool operator>(const Skill& rvalue);
    bool operator<(const Skill& rvalue);
    bool operator>=(const Skill& rvalue);
    bool operator<=(const Skill& rvalue);
    bool operator==(const Skill& rvalue);
    bool operator!=(const Skill& rvalue);
    void operator++(int);
    void operator+=(int points);
    int operator+(int points); // Verify if understood correctly
};
}
#endif