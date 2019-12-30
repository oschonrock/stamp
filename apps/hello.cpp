#include <iostream>

int main(int argc, char *argv[])
{
  auto name = std::string{};
  if (argc > 1) {
    name = argv[1]; // NOLINT
  }
  std::cout << "Hello, World! Your name is " << name << "\n";
  return 0;
}
