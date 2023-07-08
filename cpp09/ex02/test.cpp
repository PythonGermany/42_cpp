#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

int comp = 0;
int compCpy = 0;

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
      tmp[i] = *right++;
    else if (right == end)
      tmp[i] = *left++;
    else {
      compCpy++;
      tmp[i] = *left < *right ? *left++ : *right++;
    }
  }
  for (size_t i = 0; i < tmp.size(); i++) *start++ = tmp[i];
}

typedef std::vector<std::pair<int, int> >::iterator iter;
void mergeSortOne(iter start, iter end) {
  if (end - start < 2) return;
  iter mid = start + (end - start) / 2;
  mergeSortOne(start, mid);
  mergeSortOne(mid, end);
  std::vector<std::pair<int, int> > tmp(end - start);
  iter left = start, right = mid;
  for (size_t i = 0; i < tmp.size(); i++) {
    if (left == mid)
      tmp[i] = *right++;
    else if (right == end)
      tmp[i] = *left++;
    else {
      comp++;
      tmp[i] = (*left).first < (*right).first ? *left++ : *right++;
    }
  }
  for (size_t i = 0; i < tmp.size(); i++) *start++ = tmp[i];
}

template <typename T>
T binarySearch(int& target, T start, T end) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
  comp++;
  if (*mid < target) return binarySearch(target, mid + 1, end);
  return binarySearch(target, start, mid);
}

void mergeInsertSort(std::vector<int>& data) {
  const size_t size = data.size();
  if (size < 2) return;
  std::vector<std::pair<int, int> > pairs;
  pairs.reserve(size / 2);
  for (size_t i = 0; i < size - 1; i += 2) {
    if (data[i] < data[i + 1]) std::swap(data[i], data[i + 1]);
    comp++;
    pairs.push_back(std::make_pair(data[i], data[i + 1]));
  }
  mergeSortOne(pairs.begin(), pairs.end());

  std::vector<int> sorted;
  sorted.reserve(size);
  sorted.push_back(pairs[0].second);
  for (size_t i = 0; i < pairs.size(); i++) sorted.push_back(pairs[i].first);
  int insertions = 0;

  size_t jacPrev = 1;
  size_t jac = 1;
  if (pairs.size() > 1)
    sorted.insert(binarySearch(pairs[1].second, sorted.begin(),
                               sorted.begin() + ++insertions + 1),
                  pairs[1].second);
  while (jacPrev < (size + 1) / 2) {
    for (size_t i = std::min(jac, pairs.size() - 1); i > jacPrev; i--)
      sorted.insert(binarySearch(pairs[i].second, sorted.begin(),
                                 sorted.begin() + ++insertions + i),
                    pairs[i].second);
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }

  // for (size_t i = 1; i < pairs.size(); i++)
  //   sorted.insert(binarySearch(pairs[i].second, sorted.begin(),
  //                              sorted.begin() + ++insertions + i),
  //                 pairs[i].second);
  if (size % 2 == 1)
    sorted.insert(binarySearch(data.back(), sorted.begin(), sorted.end()),
                  data.back());
  std::swap(data, sorted);
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
  std::vector<int> cpy = arg;
  for (size_t i = 0; i < arg.size(); i++) std::cout << arg[i] << " ";
  std::cout << std::endl;

  long long startTime = getTimeNanos();
  mergeInsertSort(arg);
  double length = (double)(getTimeNanos() - startTime) / 1000000.0;
  for (size_t i = 0; i < arg.size(); i++) std::cout << arg[i] << " ";
  std::cout << std::endl;

  long long startTime1 = getTimeNanos();
  mergeSort<std::vector<int> >(cpy.begin(), cpy.end());
  double length1 = (double)(getTimeNanos() - startTime1) / 1000000.0;
  for (size_t i = 0; i < cpy.size(); i++) std::cout << cpy[i] << " ";
  std::cout << std::endl;

  std::cout << removeTrailingZeros(valueToString(length)) << "ms" << std::endl;
  std::cout << comp << std::endl;

  std::cout << removeTrailingZeros(valueToString(length1)) << "ms" << std::endl;
  std::cout << compCpy << std::endl;
}