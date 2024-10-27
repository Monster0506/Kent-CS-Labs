#include <iostream>

int main(){
  char code;
  double earnings, withold, takehome;


  std::cout<<"Employee Earnings: ";
  std::cin>>earnings;
  std::cout<<"Employee Code: ";
  std::cin>>code;


  switch(code){
    case 'd':
    withold = earnings*.15;
    break;
    case 'f':
    withold = earnings*.20;
    break;
    case 'h':
    withold = earnings*.60;
    break;
    case '0':
    withold = earnings*.65;
    break;
    default:
    std::cout<<"Unknown employee code: "<<code;
    return 0;

  }

  std::cout<<"Amount to withold: "<<withold<<std::endl;
  takehome = earnings - withold;
  std::cout<<"Take Home: "<<takehome<<std::endl;


}
