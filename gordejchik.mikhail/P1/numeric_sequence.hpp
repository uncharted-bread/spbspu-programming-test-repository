#ifndef NUMERIC_SEQUENCE_HPP
#define NUMERIC_SEQUENCE_HPP

#include <cstddef>

namespace gordejchik
{
  class EvenCount
  {
  public:
    EvenCount();
    void update(int number);
    size_t getResult() const;

  private:
    size_t maxEvenCount_;
    size_t currentEvenCount_;
  };

  class LocalMax
  {
  public:
    LocalMax();
    void update(int number);
    size_t getResult() const;

  private:
    size_t localMaxCount_;
    int previousNumber_;
    int currentNumber_;
    size_t totalNumbers_;
  };
}

#endif
