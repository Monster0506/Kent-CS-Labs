#include <iostream>
#include <algorithm>
#include <vector>


bool findV(std::vector<char> v, char target);

int main(){
	std::vector<char> c;
	char op;
	char cha;
	do {
		std::cout <<"enter operation [a/r/q] and character: ";
		std::cin>>op;
		std::cin>>cha;
		switch (op){
		case 'a':
			if (findV(c, cha)){
					std::cout<<"Duplicate"<<std::endl;
					break;
					}

			c.push_back(cha);
		break;
		case 'r':
		if (!findV(c, cha)){
		  std::cout << "Not in list"<<std::endl;
		  break;
		}
			std::vector<char>::iterator it;
			it = std::find(c.begin(), c.end(),cha);

		     c.erase(it);
		break;
	  }
		for (auto i = 0; i<c.size(); i++)
			std::cout<<c[i]<< " ";
		
	} while (op !='q');
}

bool findV(std::vector<char> v, char target){
	std::vector<char>::iterator it;
	it =std::find(v.begin(), v.end(),target);
	if (it != v.end())
		return true;
	return false;

}
