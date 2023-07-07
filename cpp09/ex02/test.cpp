#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
void mergeSort(T start, T end) {
  if (end - start < 2) return;
  T mid = start + (end - start) / 2;
  mergeSort(start, mid);
  mergeSort(mid, end);
  std::inplace_merge(start, mid, end);
}

int main(int argc, char** argv) {
  if (argc < 2) return 1;
  std::vector<int> arg(argc - 1);
  for (int i = 0; i < argc - 1; i++) arg[i] = std::atoi(argv[i + 1]);
  std::vector<std::pair<int, int> > pairs;
  for (int i = 0; i < arg.size() - 1; i += 2) {
    if (arg[i] <= arg[i + 1])
      pairs.push_back(std::pair<int, int>(arg[i], arg[i + 1]));
    else
      pairs.push_back(std::pair<int, int>(arg[i + 1], arg[i]));
  }
  std::vector<int> sorted;
  for (int i = 0; i < pairs.size(); i++) sorted.push_back(pairs[i].second);
  mergeSort(sorted.begin(), sorted.end());
  for (int i = 0; i < sorted.size(); i++) std::cout << sorted[i] << " ";
  std::cout << std::endl;
  // Test
}