#ifndef Hospital_hpp
#define Hospital_hpp

#include <stdio.h>
#include "Doctor.hpp"
#include "Nurse.hpp"
#include "Dentist.hpp"
#include "Surgeon.hpp"

class Hospital{
public:
    Hospital();
    Hospital(int);
    Hospital(const Hospital&);
    Hospital& operator=(const Hospital&);
    ~Hospital();
    
    void print() const;
    void addDoctor(Doctor*);
    void removeDoctor(int);
    void removeDentist(int);
    void removeSurgeon(int);
    void removeNurse(int);
private:
    Doctor** arr;
    int numberDoctors;
    int maxCapacity;
    
    void copyHospital(const Hospital&);
    void erase();
    void resize();
};
#endif /* Hospital_hpp */
