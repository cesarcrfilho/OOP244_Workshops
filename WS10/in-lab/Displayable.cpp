// OOP244 Workshop 10 - Templates 
// File: Displayable.cpp
// Version: 1.0
// Date: 2017/07/16
// Author: Fardad Soleimanloo
// 
/////////////////////////////////////////////
#include "Displayable.h"
namespace ict{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}