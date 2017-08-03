/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Aug 03 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 10 - validate header file
---------------------------------------------------------------*/

#ifndef SICT_VALIDATE_H__
#define SICT_VALIDATE_H__

namespace ict {

    template <typename T>
    bool validate(const T& min, const T& max, const T* array, const int size, bool* resultArray) {
        int i = 0; // iterator
        bool result = true;

        for (i = 0; i < size; i++) {
            if (array[i] >= min && array[i] <= max) {
				resultArray[i] = true;                
            }
            else {
				result = false;
				resultArray[i] = false;
            }
        }
        return result;
    }
}

#endif // !SICT_VALIDATE_H__
