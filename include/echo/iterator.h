#pragma once

#include <echo/iterator/strided_iterator.h>
#include <echo/iterator/counting_iterator.h>
#include <echo/iterator/index_functor_iterator.h>

namespace echo {
using echo::iterator::StridedIterator;
using echo::iterator::make_strided_iterator;
using echo::iterator::make_counting_iterator;
using echo::iterator::make_index_functor_iterator;
}
