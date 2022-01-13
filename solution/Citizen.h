#ifndef _CITIZEN_H_
#define _CITIZEN_H_

#include <string>
#include <iostream>

namespace mtm{
    class Citizen
    {
    private:
        int id_t;
        std::string first_name_t;
        std::string last_name_t;
        int year_of_birth_t;

    public:
        Citizen(const int id, const std::string first_name, const std::string last_name, const int year);
        virtual ~Citizen() = default; 
        Citizen(const Citizen& citizen) = default;


        virtual int getId() const;

        std::string getFirstName() const;

        std::string getLastName() const;

        int getBirthYear() const;


        bool operator<(const Citizen& citizen) const;
        bool operator>(const Citizen& citizen) const;
        bool operator==(const Citizen& citizen) const;
        bool operator==(const int id) const;
        bool operator<=(const Citizen& citizen) const;
        bool operator>=(const Citizen& citizen) const;
        bool operator!=(const Citizen& citizen) const;

        virtual std::ostream& printShort(std::ostream& os) const = 0;
        virtual std::ostream& printLong(std::ostream& os) const = 0;
    
        virtual Citizen* clone() const = 0;
    };
    

    /**
     * @brief CitizenPlus is an extention to Citizen: Adds salary member to Citizen.
     * 
     */
    class CitizenPlus : public Citizen{
        protected:
        int salary_t;

        public:
        CitizenPlus(const int id, const std::string first_name, const std::string last_name, const int year);
        CitizenPlus(const CitizenPlus& citizen_plus) = default;
        virtual ~CitizenPlus() = default;

        int getSalary() const;

        void setSalary(const double add_salary);
    };


}

#endif