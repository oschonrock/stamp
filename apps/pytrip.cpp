#include <cstdlib>
#include <iostream>
#include <tuple>
#include <vector>

using triple = std::tuple<int, int, int>;

// http://realtimecollisiondetection.net/blog/?p=89
bool equal(double x, double y) {
  return std::abs(x - y) <= std::numeric_limits<double>::epsilon() * std::max(1.0, std::max(std::abs(x), std::abs(y)));
}

bool are_multiples(triple a, triple b) {
  auto [xa, ya, za] = a;
  auto [xb, yb, zb] = b;
  auto rat_x = static_cast<double>(xa) / xb;
  auto rat_y = static_cast<double>(ya) / yb;
  auto rat_z = static_cast<double>(za) / zb;
  return
      equal(rat_x, rat_y) &&
      equal(rat_x, rat_z) &&
      equal(rat_y, rat_z);
}

bool exists(const std::vector<triple>& existing, triple n) {
  for (auto t: existing) {
    if (are_multiples(t, n)) return true;
  }
  return false;
}

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

  auto triples = std::vector<triple>{};

  int count = 0;
  for (int z = 1;; ++z) {
    for (int x = 1; x != z + 1; ++x) {
      for (int y = x; y != z + 1; ++y) {
        if (x * x + y * y == z * z) {
          auto t = std::make_tuple(x,y,z);
          if (!exists(triples, t)) {
            triples.push_back(t);
            std::cout << '(' << x << ',' << y << ',' << z << ')' << '\n';
            if (++count == n) return EXIT_SUCCESS;
          }
        }
      }
    }
  }
  return EXIT_FAILURE;
}
