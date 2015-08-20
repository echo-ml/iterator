#pragma once

#include <echo/concept.h>
#include <boost/iterator/counting_iterator.hpp>

namespace echo {
namespace iterator {

template <class T, CONCEPT_REQUIRES(std::is_integral<T>())>
auto make_counting_iterator(T i) {
  return boost::make_counting_iterator(i);
}
}
}
