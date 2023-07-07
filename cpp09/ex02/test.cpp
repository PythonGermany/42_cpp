#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

template <typename T>
void mergeSort(typename T::iterator start, typename T::iterator end) {
  if (end - start < 2) return;
  typename T::iterator mid = start + (end - start) / 2;
  mergeSort<T>(start, mid);
  mergeSort<T>(mid, end);
  T tmp(end - start);
  typename T::iterator left = start, right = mid;
  for (size_t i = 0; i < tmp.size(); i++) {
    if (left == mid)
      tmp[i] = *right;
    else if (right == end)
      tmp[i] = *left++;
    else if (*left < *right)
      tmp[i] = *left++;
    else
      tmp[i] = *right++;
  }
  for (size_t i = 0; i < tmp.size(); i++) *start++ = tmp[i];
}

template <typename T>
T binarySearch(int& target, T start, T end) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
  if (*mid == target) return mid;
  if (*mid < target) return binarySearch(target, mid + 1, end);
  return binarySearch(target, start, mid);
}

template <typename T>
void mergeInsertSort(T& data) {
  T sorted;
  for (int i = 0; i < data.size() - 1; i += 2) {
    if (data[i] < data[i + 1]) std::swap(data[i], data[i + 1]);
    sorted.push_back(data[i]);
  }
  mergeSort<T>(sorted.begin(), sorted.end());
  for (int i = 1; i < data.size(); i += 2)
    sorted.insert(binarySearch(data[i], sorted.begin(), sorted.end()), data[i]);
  data = sorted;
}

long long getTimeNanos() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return static_cast<long long>(ts.tv_sec) * 1000000000LL +
         static_cast<long long>(ts.tv_nsec);
}

std::string valueToString(double val) {
  std::stringstream ss;
  ss << std::setprecision(std::numeric_limits<double>::digits10 + 1);
  ss << std::fixed << val << std::scientific;
  return ss.str();
}

std::string removeTrailingZeros(std::string str) {
  if (str.empty()) return str;
  while (str[str.length() - 1] == '0') {
    if (str.length() < 2 || str[str.length() - 2] == '.') break;
    str.erase(str.length() - 1, 1);
  }
  return str;
}

int main(int argc, char** argv) {
  if (argc < 2) return 1;
  std::vector<int> arg(argc - 1);
  for (int i = 0; i < argc - 1; i++) arg[i] = std::atoi(argv[i + 1]);
  long long startTime = getTimeNanos();
  mergeInsertSort(arg);
  double length = (double)(getTimeNanos() - startTime) / 1000000.0;
  for (int i = 0; i < arg.size(); i++) std::cout << arg[i] << " ";
  std::cout << std::endl;
  std::cout << removeTrailingZeros(valueToString(length)) << "ms" << std::endl;
}