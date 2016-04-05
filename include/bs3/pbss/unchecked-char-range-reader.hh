/*

    Copyright 2016 Carl Lei

    This file is part of Bamboo Shoot 3.

    Bamboo Shoot 3 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bamboo Shoot 3 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Bamboo Shoot 3.  If not, see <http://www.gnu.org/licenses/>.

    Carl Lei <xecycle@gmail.com>

*/

#ifndef BS3_PBSS_UNCHECKED_CHAR_RANGE_READER_HH
#define BS3_PBSS_UNCHECKED_CHAR_RANGE_READER_HH

#include <ios>
#include <string>

namespace pbss {

inline
namespace chrange_abiv1 {

template <class Char, class Traits=std::char_traits<Char> >
struct basic_unchecked_char_range_reader {

private:

  const Char* current;

public:

  basic_unchecked_char_range_reader(const Char* first)
    : current(first)
  {}

  basic_unchecked_char_range_reader& read(Char* dest, std::streamsize count)
  {
    Traits::copy(dest, current, to_unsigned(count));
    current += count;
    return *this;
  }

  constexpr bool eof() const
  {
    return false;
  }

  typename Traits::int_type
  get()
  {
    return Traits::to_int_type(*current++);
  }

  typename Traits::int_type
  peek()
  {
    return Traits::to_int_type(*current);
  }

  void ignore(std::streamsize count)
  {
    current += count;
  }

};

} // inline namespace chrange_abiv1

using unchecked_char_range_reader = basic_unchecked_char_range_reader<char>;

} // namespace pbss

#endif /* BS3_PBSS_UNCHECKED_CHAR_RANGE_READER_HH */
