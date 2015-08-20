#pragma once

#include <echo/iterator/counting_iterator.h>
#include <echo/index.h>
#include <boost/iterator/transform_iterator.hpp>

namespace echo {
namespace iterator {

template <
    class Functor,
    CONCEPT_REQUIRES(std::is_copy_constructible<Functor>::value &&
                     !std::is_same<std::result_of_t<Functor(index_t)>, void>())>
auto make_index_functor_iterator(index_t i, Functor functor) {
  return boost::make_transform_iterator(
      echo::iterator::make_counting_iterator(i), functor);
}
}
}
