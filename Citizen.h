#ifndef _CITIZEN_H_
#define _CITIZEN_H_

#include <string>
#include <iostream>

using std::string;
using std::ostream;
namespace mtm{
    class Citizen
    {
    private:
        int id_t;
        std::string first_name_t;
        std::string last_name_t;
        int year_of_birth_t;

    public:
        Citizen() = default;
        Citizen(const int id, const std::string first_name, const std::string last_name, const int year): id_t(id), 
                    first_name_t(first_name), last_name_t(last_name), year_of_birth_t(year) {};
        ~Citizen() = default; 
        Citizen(const Citizen& citizen) {
            id_t = citizen.id_t;
            first_name_t = citizen.first_name_t;
            last_name_t = citizen.last_name_t;
            year_of_birth_t = citizen.year_of_birth_t;
        }

        int getId() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        int getBirthYear() const;

        //Operators for Citizen

        bool operator<(const Citizen& citizen);
        bool operator>(const Citizen& citizen);
        bool operator==(const Citizen& citizen);
        bool operator<=(const Citizen& citizen);
        bool operator>=(const Citizen& citizen);
        bool operator!=(const Citizen& citizen);

        //Print functions

        virtual ostream& printShort(ostream& os) const = 0 ;
        virtual ostream& printLong(ostream& os) const = 0;
    
        virtual Citizen* clone() = 0;
    };
    
}

#endif