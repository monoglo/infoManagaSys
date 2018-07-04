#include "declaration.h"
class Set : public List
{
public:
  List operator+(Set ls);
  List operator-(Set ls);
  List operator and(Set ls);
};