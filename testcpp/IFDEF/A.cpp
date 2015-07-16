#include <iostream>
  int main()
{
#ifdef X
	std::cout << "Hello X!" << std::endl;
#endif
#ifdef Y
	std::cout << "Hello Y!" << std::endl;
#endif
return 0;
}