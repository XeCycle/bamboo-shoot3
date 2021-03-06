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

#include <cassert>
#include <bs3/pbsf/crc-32.hh>

int main()
{

  std::string str = "abcdefghijklmnopqrstuvwxyz";

  assert(pbsf::crc32c_generic(str.data(), str.size()) == 0x9ee6ef25);

#ifdef __SSE4_2__

  assert(pbsf::crc32c_sse(str.data(), str.size()) == 0x9ee6ef25);

#endif // __SSE4_2__

  return 0;
}
