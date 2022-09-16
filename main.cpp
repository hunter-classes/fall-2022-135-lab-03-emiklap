// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  std::cout << "\n Task A \n";
  std::cout << "Entered date: 01/01/2018 \n";
  get_east_storage("01/01/2018");

  std::cout << "\n Task B \n";
  get_min_east();
  get_max_east();

  std::cout << "\n Task C \n";
  compare_basins("01/01/2018");
  compare_basins("02/01/2018");
  compare_basins("03/01/2018");
  
  std::cout << "\n Task D \n";
  reverse_order("05/29/2018", "06/02/2018");

  return 0;
}
