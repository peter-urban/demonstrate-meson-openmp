// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: CC0-1.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <demonstrate_meson_openmp/openmp_compare_thread_count.hpp>

// using namespace testing;
using namespace std;
// using namespace themachinethatgoesping;

namespace demonstrate_meson_openmp_tests {

TEST_CASE("Test openmp based on processor count", "[demonstrate_meson_openmp]")
{
    REQUIRE(demonstrate_meson_openmp::openmp_thread_count_is_same_as_std_thread_count_in_header());
    REQUIRE(demonstrate_meson_openmp::openmp_thread_count_is_same_as_std_thread_count_in_library());
}



}
