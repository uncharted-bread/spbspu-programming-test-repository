#include <iostream>
#include <stdexcept>
#include "numeric_sequence.hpp"

int main()
{
  gordejchik::EvenCount evenCount;
  gordejchik::LocalMax localMax;

  int currentNumber = 0;
  while (std::cin >> currentNumber && currentNumber != 0)
  {
    evenCount.update(currentNumber);
    localMax.update(currentNumber);
  }

  if (std::cin.fail())
  {
    if (std::cin.eof())
    {
      std::cerr << "Error: sequence doesn't end with a zero\n";
    }
    else
    {
      std::cerr << "Error: sequence contains non-numeric characters\n";
    }
    return 1;
  }

  std::cout << evenCount.getResult() << '\n';

  try
  {
    std::cout << localMax.getResult() << '\n';
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }

  return 0;
}
