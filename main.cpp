#include <iostream>
#include "Registrar.h"
using namespace std;
int main(int argc,char **argv)
{
  Registrar registers;
  registers.getInLine();
  registers.sendToWindow();
}
