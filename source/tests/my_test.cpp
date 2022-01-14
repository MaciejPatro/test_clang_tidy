#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <some_header.h>
#include <other_header.h>

TEST_CASE("a test")
{
  // TODO wrong cpp
  else_after_return();
  wrong_function();
  CHECK(5 != 7);
}
