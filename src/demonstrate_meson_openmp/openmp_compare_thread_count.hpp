// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University

// SPDX-License-Identifier: CC0-1.0

#pragma once

#include <iostream>
#include <thread>

#include <omp.h>

#include "dllexport.hpp"

namespace demonstrate_meson_openmp {

/**
 * @brief This function checks if the openmp processor count is the same as the
 * std::thread::hardware_concurrency() count and if omp_get_num_threads() is the
 * same as omp_get_max_threads().
 *
 * https://stackoverflow.com/questions/10481623/how-to-tell-if-openmp-is-working
 *
 * @return true
 * @return false
 */
inline bool openmp_thread_count_is_same_as_std_thread_count_in_header() {
  const int processor_count = std::thread::hardware_concurrency();
  const int omp_processor_count = omp_get_num_procs();
  const int omp_max_threads = omp_get_max_threads();

  // test does not make sense if there is only one thread
  if (processor_count < 2) {
    std::cerr << "processor_count is less than 2" << std::endl;
    return false;
  }

  bool thread_test = true;
#pragma omp parallel
  {
#pragma omp master
    {
      if (omp_get_num_threads() != omp_max_threads) {
        std::cerr << "Failure omp_get_num_threads [" << omp_get_num_threads()
                  << "] != omp_max_threads [" << omp_max_threads << "]"
                  << std::endl;
        thread_test = false;
      }
    }
  }
  if (!thread_test) {
    return false;
  }

  if (processor_count == omp_processor_count &&
      processor_count == omp_max_threads) {
    return true;
  }

  std::cerr << "Failure: processor_count: " << processor_count << std::endl;
  std::cerr << "Failure: omp_processor_count: " << omp_processor_count
            << std::endl;
  std::cerr << "Failure: omp_max_threads: " << omp_max_threads << std::endl;
  return false;
}

// ----- compiled library functions -----
DEMOLIB_API bool openmp_thread_count_is_same_as_std_thread_count_in_library();

} // namespace demonstrate_meson_openmp
