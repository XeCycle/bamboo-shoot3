#include <bs3/pbss/pbss.hh>

using pbss::is_memory_layout;

struct empty {
  PBSS_TUPLE_MEMBERS();
};
static_assert(!is_memory_layout<empty>(), "empty is not memory layout");

struct one {
  char a;
  PBSS_TUPLE_MEMBERS(PBSS_TUPLE_MEMBER(&one::a));
};
static_assert(is_memory_layout<one>(), "tuple with one primitive member is memory layout");

struct contiguous {
  int a;
  int b;
  PBSS_TUPLE_MEMBERS(PBSS_TUPLE_MEMBER(&contiguous::a), PBSS_TUPLE_MEMBER(&contiguous::b));
};
static_assert(is_memory_layout<contiguous>(), "contiguous tuple is memory layout");

struct middle_pad {
  char a;
  int b;
  PBSS_TUPLE_MEMBERS(PBSS_TUPLE_MEMBER(&middle_pad::a), PBSS_TUPLE_MEMBER(&middle_pad::b));
};
static_assert(!is_memory_layout<middle_pad>(), "tuple with padding in middle is not memory layout");

struct post_pad {
  int b;
  char a;
  PBSS_TUPLE_MEMBERS(PBSS_TUPLE_MEMBER(&post_pad::b), PBSS_TUPLE_MEMBER(&post_pad::a));
};
static_assert(!is_memory_layout<post_pad>(), "tuple with padding at last is not memory layout");

struct reversed {
  int b;
  int a;
  PBSS_TUPLE_MEMBERS(PBSS_TUPLE_MEMBER(&reversed::a), PBSS_TUPLE_MEMBER(&reversed::b));
};
static_assert(!is_memory_layout<reversed>(), "tuple with out-of-order members is not memory layout");

int main()
{
  return 0;
}
