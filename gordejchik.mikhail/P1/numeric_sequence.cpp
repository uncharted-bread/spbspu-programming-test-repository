#include "numeric_sequence.hpp"
#include <limits>
#include <stdexcept>

gordejchik::EvenCount::EvenCount():
  maxEvenCount_(0),
  currentEvenCount_(0)
{}

void gordejchik::EvenCount::update(int number)
{
  if (number % 2 == 0)
  {
    ++currentEvenCount_;
    if (currentEvenCount_ > maxEvenCount_)
    {
      maxEvenCount_ = currentEvenCount_;
    }
  }
  else
  {
    currentEvenCount_ = 0;
  }
}

size_t gordejchik::EvenCount::getResult() const
{
  return maxEvenCount_;
}

gordejchik::LocalMax::LocalMax():
  localMaxCount_(0),
  previousNumber_(std::numeric_limits< int >::max()),
  currentNumber_(std::numeric_limits< int >::max()),
  totalNumbers_(0)
{}

void gordejchik::LocalMax::update(int number)
{
  if (currentNumber_ > previousNumber_ && currentNumber_ > number)
  {
    ++localMaxCount_;
  }
  previousNumber_ = currentNumber_;
  currentNumber_ = number;
  ++totalNumbers_;
}

size_t gordejchik::LocalMax::getResult() const
{
  if (totalNumbers_ == 0)
  {
    throw std::logic_error("Error: sequence too short for LOC-MAX");
  }
  return localMaxCount_;
}
