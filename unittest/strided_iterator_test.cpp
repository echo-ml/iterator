#include <echo/iterator/strided_iterator.h>
#include <echo/test.h>
#include <numeric>

using namespace echo;
using namespace echo::iterator;

TEST_CASE("strided_iterator") {
  int x[6];
  std::iota(std::begin(x), std::end(x), 0);
  auto i1 = make_strided_iterator(x, 2l);
  auto i2 = make_strided_iterator(x, 2_index);
  CHECK(sizeof(i1) == sizeof(long)+sizeof(int*));
  CHECK(sizeof(i2) == sizeof(int*));

  CHECK(*i1 == 0);
  CHECK(*std::next(i1) == 2);
  CHECK(*std::prev(std::next(i1)) == 0);
  CHECK(*std::next(i1, 1) == 2);
  CHECK(*std::prev(std::next(i1,1),1) == 0);

  CHECK(*i2 == 0);
  CHECK(*std::next(i2) == 2);
  CHECK(*std::prev(std::next(i2)) == 0);
  CHECK(*std::next(i2, 1) == 2);
  CHECK(*std::prev(std::next(i2,1),1) == 0);
}
