// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University

// SPDX-License-Identifier: CC0-1.0

#include "openmp_compare_thread_count.hpp"
#include "openmp_openmp_defined.hpp"
#include "openmp_try_parallel_pragma.hpp"

namespace demonstrate_meson_openmp {

bool openmp_is_defined_for_compiler_in_library()
{
    return openmp_is_defined_for_compiler_in_header();
}

bool openmp_thread_count_is_same_as_std_thread_count_in_library()
{
    return openmp_thread_count_is_same_as_std_thread_count_in_header();
}

bool openmp_parallel_pragma_is_working_in_library()
{
    return openmp_parallel_pragma_is_working_in_header();
}

} // demonstrate_meson_openmp