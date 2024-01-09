// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: CC0-1.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <demonstrate_meson_openmp/openmp_try_parallel_pragma.hpp>

// using namespace testing;
using namespace std;
// using namespace themachinethatgoesping;

namespace demonstrate_meson_openmp_tests {

TEST_CASE("Test openmp based on parallel pragma action", "[demonstrate_meson_openmp]")
{
    REQUIRE(demonstrate_meson_openmp::openmp_parallel_pragma_is_working_in_header());
    REQUIRE(demonstrate_meson_openmp::openmp_parallel_pragma_is_working_in_library());
}


}
