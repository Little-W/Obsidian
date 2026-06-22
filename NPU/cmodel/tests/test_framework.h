#ifndef _TEST_FRAMEWORK_H
#define _TEST_FRAMEWORK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#ifndef CI_TEST
#define TESTCASE_PATH "/data/ci/" // self-test
#else
#define TESTCASE_PATH "/workspace/" // ci-test
#endif

struct TestCase {
  string name;
  void (*func)();
};

vector<TestCase> &getTestCases() {
  static vector<TestCase> tests;
  return tests;
}

struct TestStats {
  vector<string> passed_name;
  vector<string> faild_name;
  void reset() {
    passed_name.clear();
    faild_name.clear();
  }
};

struct TestRegister {
  TestRegister(const string &name, void (*func)()) {
    getTestCases().push_back({name, func});
  }
};

// 自动注册测试用例
#define TESTCASE(name)                                                         \
  void test_##name();                                                          \
  TestRegister register_##name(#name, test_##name);                            \
  void test_##name()

#define ASSERT_TRUE(condition)                                                 \
  do {                                                                         \
    if (!(condition)) {                                                        \
      cerr << "Assertion failed:" << #condition << endl;                       \
      throw runtime_error("Assertion failed");                                 \
    }                                                                          \
  } while (0)

#endif