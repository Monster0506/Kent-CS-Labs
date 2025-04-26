#include "object_creation_destruction.hpp"

int main(){
    Class c;
    std::cout<<"c.a: "<<c.getA()<<std::endl;
    Class d(c);
    std::cout<<"d.a: "<<d.getA()<<std::endl;

    Class e;
    e=c;
    std::cout<<"e.a: "<<d.getA()<<std::endl;

}