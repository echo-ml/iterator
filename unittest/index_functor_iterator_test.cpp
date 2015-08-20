#include <echo/iterator/index_functor_iterator.h>
#include <echo/test.h>
#include <iostream>
using namespace echo;
using namespace echo::iterator;

std::nullptr_t make_index_functor_iterator(...);

double f1(index_t i) { return i; }
double f2(index_t i, float) { return i; }

TEST_CASE("index_functor_iterator") {
  auto i = make_index_functor_iterator(0, f1);
  CHECK(*i == 0);
  ++i;
  CHECK(*i == 1);

  // CHECK(echo::concept::random_access_iterator<decltype(i)>());
  // CHECK(*std::next(i) == 1);

  CHECK(std::is_same<decltype(make_index_functor_iterator(0, f2)),
                     std::nullptr_t>::value);
}
