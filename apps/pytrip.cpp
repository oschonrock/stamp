#include <iostream>
#include <numeric>

inline bool is_pythag_multiple(int x, int y, int z) noexcept { return std::gcd(std::gcd(x, y), std::gcd(x, z)) > 1; }

inline bool is_pythag_triple(int x, int y, int z) noexcept { return x * x + y * y == z * z; }

int main(int argc, char* argv[]) {
  auto name = std::string{};
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " TopN\n"; // NOLINT
    return EXIT_FAILURE;
  }
  int n = std::atoi(argv[1]); // NOLINT

  if (n < 1) {
    std::cerr << "N should be 1 or greater\n";
  }

  std::cout << "Finding top " << n << " Pythagorean triples\n";

  int count = 0;
  for (int z = 1;; ++z) {
    for (int x = 1; x != z + 1; ++x) {
      for (int y = x; y != z + 1; ++y) {
        if (is_pythag_triple(x,y,z) && !is_pythag_multiple(x, y, z)) {
            std::cout << '(' << x << ',' << y << ',' << z << ')' << '\n';
            if (++count == n) return EXIT_SUCCESS;
        }
      }
    }
  }
  return EXIT_FAILURE;
}
