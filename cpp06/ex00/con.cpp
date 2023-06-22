#include <iomanip>
#include <ios>
#include <iostream>

int main() {
  std::cout << std::fixed;
  float f = 21474835700.0f;
  long comp = std::atol("21474835700.0f");
  std::cout << f << " " << comp << std::endl;
  std::cout << static_cast<int>(f) << std::endl;
  std::cout << (int)f << std::endl;
}