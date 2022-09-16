// add your code as appropriate 
#include <iostream>
#include "reservoir.h"

int main()
{
  std::cout << "\nTask A \n";
  std::cout << "Entered date: 01/01/2018 \n";
  get_east_storage("01/01/2018");

  std::cout << "\nTask B \n";
  get_min_east();
  get_max_east();

  
  return 0;
}
