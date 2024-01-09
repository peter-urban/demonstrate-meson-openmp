// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University

// SPDX-License-Identifier: CC0-1.0

#pragma once

#include <iostream>

#include "dllexport.hpp"

namespace demonstrate_meson_openmp {

/**
 * @brief This function checks if the _OPENMP macro is defined.
 * https://stackoverflow.com/questions/56166109/detect-at-runtime-if-openmp-is-being-used-in-a-c-program
 *
 * @return true
 * @return false
 */
inline bool openmp_is_defined_for_compiler_in_header() {
#if defined(_OPENMP)
  std::cerr << "_OPENMP is defined as: " << _OPENMP << std::endl;
  return true;
#endif
  std::cerr << "_OPENMP is not defined" << std::endl;
  return false;
}


// ----- compiled library functions -----
DEMOLIB_API bool openmp_is_defined_for_compiler_in_library();

} // namespace demonstrate_meson_openmp
