#ifndef _CITIZEN_H_
#define _CITIZEN_H_

#include <string>
#include <iostream>
#include <memory>

using std::string;
using std::ostream;
using std::shared_ptr;

namespace mtm{
    class Citizen
    {
    private:
        int id_t;
        string first_name_t;
        string last_name_t;
        int year_of_birth_t;

    public:
        Citizen(const int id, const string first_name, const string last_name, const int year);
        virtual ~Citizen() = default; 
        Citizen(const Citizen& citizen) = default;


        virtual int getId() const;
        string getFirstName() const;
        string getLastName() const;
        int getBirthYear() const;
        virtual int getSalary() const;
        virtual void setSalary(const int add_salary);


        bool operator<(const Citizen& citizen) const;
        bool operator>(const Citizen& citizen) const;
        bool operator==(const Citizen& citizen) const;
        bool operator==(const int id) const;
        bool operator<=(const Citizen& citizen) const;
        bool operator>=(const Citizen& citizen) const;
        bool operator!=(const Citizen& citizen) const;

        virtual ostream& printShort(ostream& os) const = 0;
        virtual ostream& printLong(ostream& os) const = 0;
    
        virtual shared_ptr<Citizen> clone() const = 0;
    };

    /**
     * @brief Comperator for Citizen collection sorting
     * 
     */
    class Comparator{
            public:
            Comparator() = default;
            ~Comparator() = default;
            Comparator(const Comparator&) = default;
            
            bool operator()(const shared_ptr<Citizen> ptr1, const shared_ptr<Citizen> ptr2);
    };


}

#endif