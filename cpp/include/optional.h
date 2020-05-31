#ifndef OPTIONAL_H
#define OPTIONAL_H

#ifdef STD_OPTIONAL_EXISTS

#include <optional>
using std::nullopt;
using std::optional;

#else

#ifdef STD_EXPERIMENTAL_OPTIONAL_EXISTS

#include <experimental/optional>
using std::experimental::nullopt;
using std::experimental::optional;

#endif

#endif

#endif  // OPTIONAL_H
