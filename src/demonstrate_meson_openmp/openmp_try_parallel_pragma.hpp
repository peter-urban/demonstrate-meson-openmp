// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University

// SPDX-License-Identifier: CC0-1.0

#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include <omp.h>

#include "dllexport.hpp"

namespace demonstrate_meson_openmp {


inline bool openmp_parallel_pragma_is_working_in_header() {
  const unsigned int omp_max_threads = omp_get_max_threads();

  // test does not make sense if there is only one thread
  if (omp_max_threads < 2) {
    std::cerr << "omp_max_threads is less than 2" << std::endl;
    return false;
  }

  // vector with thread responses (1 = success, 0 = failure)
  std::vector<int> thread_responses(omp_max_threads);

#pragma omp parallel for
  for (unsigned int i = 0; i < omp_max_threads; ++i) {
    std::cerr << "Hello from thread " << omp_get_thread_num() << std::endl;
    thread_responses.at(omp_get_thread_num()) = 1;
    std::chrono::milliseconds duration(100);
    std::this_thread::sleep_for(duration);
  }

  for (unsigned int i = 0; i < omp_max_threads; ++i) {
    if (thread_responses.at(i) != 1) {
      std::cerr << "thread_responses.at(" << i << ") != 1" << std::endl;
      return false;
    }
  }

  return true;
}

// ----- compiled library functions -----
DEMOLIB_API bool openmp_parallel_pragma_is_working_in_library();

} // namespace demonstrate_meson_openmp
