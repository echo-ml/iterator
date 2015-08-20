#pragma once

#include <echo/htl.h>
#include <echo/concept.h>
#include <echo/index.h>
#include <echo/contract.h>
#include <boost/iterator/iterator_facade.hpp>

namespace echo {
namespace iterator {

//------------------------------------------------------------------------------
// StridedIterator
//------------------------------------------------------------------------------
template <class RandomAccessIterator, class Stride>
class StridedIterator : public boost::iterator_facade<
                            StridedIterator<RandomAccessIterator, Stride>,
                            iterator_traits::value_type<RandomAccessIterator>,
                            boost::random_access_traversal_tag,
                            iterator_traits::reference<RandomAccessIterator>>,
                        htl::Pack<Stride> {
 public:
  explicit StridedIterator(
      RandomAccessIterator iterator = RandomAccessIterator(),
      Stride stride = Stride())
      : htl::Pack<Stride>(stride), _iterator(iterator) {
    CONTRACT_EXPECT { CONTRACT_ASSERT(stride >= 1); };
  }

 private:
  friend class boost::iterator_core_access;
  RandomAccessIterator _iterator;

  decltype(auto) dereference() const { return *_iterator; }

  bool equal(StridedIterator other) const {
    return this->_iterator == other._iterator;
  }

  void advance(ptrdiff_t n) { _iterator += n * htl::unpack(*this); }

  void increment() { _iterator += htl::unpack(*this); }

  void decrement() { _iterator -= htl::unpack(*this); }

  ptrdiff_t distance_to(StridedIterator other) const {
    return (other._iterator - _iterator) / htl::unpack(*this);
  }
};

//------------------------------------------------------------------------------
// make_strided_iterator
//------------------------------------------------------------------------------
template <class RandomAccessIterator, class Stride,
          CONCEPT_REQUIRES(
              echo::concept::random_access_iterator<RandomAccessIterator>() &&
              std::is_convertible<Stride, index_t>())>
auto make_strided_iterator(RandomAccessIterator iterator, Stride stride) {
  return StridedIterator<RandomAccessIterator, Stride>(iterator, stride);
}
}
}
