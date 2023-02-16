/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#include "srsgnb/adt/expected.h"
#include "srsgnb/support/test_utils.h"

using namespace srsgnb;

void test_expected_trivial()
{
  expected<int> exp;
  TESTASSERT(exp.has_value());
  TESTASSERT(exp);

  exp = 5;
  TESTASSERT(exp.has_value());
  TESTASSERT(exp.value() == 5);
  TESTASSERT(exp);

  exp.set_error(default_error_t{});
  TESTASSERT(not exp.has_value());
  TESTASSERT(not exp);

  int i = 2;
  exp   = i;
  TESTASSERT(exp);
  TESTASSERT(exp.value() == 2);

  exp.set_error();
  TESTASSERT(not exp);

  exp = 3;
  {
    expected<int> exp2 = exp;
    TESTASSERT(exp2 and exp2.value() == 3);
    expected<int> exp3;
    exp3 = exp2;
    TESTASSERT(exp3 and exp3.value() == 3);
  }
  TESTASSERT(exp and exp.value() == 3);

  exp.set_error();
  {
    expected<int> exp2{exp};
    TESTASSERT(not exp2);
    expected<int> exp3;
    exp3 = exp;
    TESTASSERT(not exp3);
  }
}

struct C {
  C() : val(0) { count++; }
  C(int v) : val(v) { count++; }
  C(const C& other)
  {
    val = other.val;
    count++;
  }
  C(C&& other)
  {
    val       = other.val;
    other.val = 0;
    count++;
  }
  ~C() { count--; }
  C& operator=(const C& other)
  {
    val = other.val;
    return *this;
  }
  C& operator=(C&& other)
  {
    val       = other.val;
    other.val = 0;
    return *this;
  }
  int             val;
  static uint32_t count;
};
uint32_t C::count = 0;

void test_expected_struct()
{
  expected<C, int> exp;
  exp = C{5};
  TESTASSERT(exp and exp.value().val == 5);
  TESTASSERT(C::count == 1);

  {
    auto exp2 = exp;
    TESTASSERT(exp2 and exp2.value().val == 5);
    TESTASSERT(C::count == 2);
  }
  TESTASSERT(exp and exp.value().val == 5);
  TESTASSERT(C::count == 1);

  {
    auto exp2 = std::move(exp);
    TESTASSERT(exp2 and exp2.value().val == 5);
    TESTASSERT(exp and exp.value().val == 0);
  }

  exp.set_error(2);
  TESTASSERT(not exp and exp.error() == 2);
}

void test_unique_ptr()
{
  expected<std::unique_ptr<C>> exp;
  TESTASSERT(exp);
  exp.value().reset(new C{2});
  TESTASSERT(exp.value()->val == 2);

  {
    auto exp2 = std::move(exp);
    TESTASSERT(exp.value() == nullptr);
    TESTASSERT(exp2 and exp2.value()->val == 2);
  }
}

int main()
{
  test_expected_trivial();
  test_expected_struct();
  test_unique_ptr();
}