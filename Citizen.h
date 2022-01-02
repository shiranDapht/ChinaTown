#ifndef _CITIZEN_H_
#define _CITIZEN_H_

#include <string>
#include <iostream>
typedef std::string string;
typedef std::ostream ostream;

namespace mtm{
    class Citizen
    {
    private:
        int id_t;
        string first_name_t;
        string last_name_t;
        int year_of_birth_t;

    public:
        Citizen() = default;
        Citizen(int id, string first_name, string last_name, int year): id_t(id), 
                    first_name_t(first_name), last_name_t(last_name), year_of_birth_t(year) {};
        ~Citizen() = default; 
        Citizen(const Citizen& citizen) {
            id_t = citizen.id_t;
            first_name_t = citizen.first_name_t;
            last_name_t = citizen.last_name_t;
            year_of_birth_t = citizen.year_of_birth_t;
        }

        int getId() const;
        string getFirstName() const;
        string getLastName() const;
        int getBirthYear() const;

        //Operators for Citizen

        bool operator<(const Citizen& citizen);
        bool operator>(const Citizen& citizen);
        bool operator==(const Citizen& citizen);
        bool operator<=(const Citizen& citizen);
        bool operator>=(const Citizen& citizen);
        bool operator!=(const Citizen& citizen);

        //Print functions

        virtual ostream& printShort(const ostream& os) = 0 ;
        virtual ostream& printLong(const ostream& os) = 0;
    
        virtual Citizen& clone() = 0;
    };
    
}

#endif