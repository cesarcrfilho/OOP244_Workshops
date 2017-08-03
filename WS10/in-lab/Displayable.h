// OOP244 Workshop 10 - Templates 
// File: Displayable.h
// Version: 1.0
// Date: 2017/07/16
// Author: Fardad Soleimanloo
// 
/////////////////////////////////////////////
#include <iostream>

#ifndef ICT_DISPLAYABLE_H_
#define ICT_DISPLAYABLE_H_
namespace ict{
  class Displayable{
  public:
    virtual std::ostream& display(std::ostream& os)const = 0;
  };

  std::ostream& operator<<(std::ostream& os, const Displayable& D);
}

#endif
