#include <iostream>

#ifndef CS2_OBJ_CD_
#define CS2_OBJ_CD_


class Class{
    public: 
        Class();
        Class(const Class&);
        ~Class();
        Class& operator=(const Class&);
        char getA(){return a;}

    private:
        char a;
};

#endif