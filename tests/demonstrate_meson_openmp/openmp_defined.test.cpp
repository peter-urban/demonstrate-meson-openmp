// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: CC0-1.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <demonstrate_meson_openmp/openmp_openmp_defined.hpp>

// using namespace testing;
using namespace std;
// using namespace themachinethatgoesping;

namespace demonstrate_meson_openmp_tests {

TEST_CASE("Test openmp based on _OPENMP defined",
          "[demonstrate_meson_openmp]") {
  REQUIRE(demonstrate_meson_openmp::openmp_is_defined_for_compiler_in_header());
  REQUIRE(
      demonstrate_meson_openmp::openmp_is_defined_for_compiler_in_library());

  // std::cerr << "_OPENMP is defined as: " << _OPENMP << std::endl;
  // REQUIRE(false);
}

} // namespace demonstrate_meson_openmp_tests
