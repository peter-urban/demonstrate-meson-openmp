// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University

// SPDX-License-Identifier: CC0-1.0

#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include <omp.h>

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

/**
 * @brief This function checks if the openmp processor count is the same as the
 * std::thread::hardware_concurrency() count.
 *
 * https://stackoverflow.com/questions/10481623/how-to-tell-if-openmp-is-working
 *
 * @return true
 * @return false
 */
inline bool openmp_thread_count_is_same_as_std_thread_count_in_header() {
  const unsigned int processor_count = std::thread::hardware_concurrency();
  const unsigned int omp_processor_count = omp_get_num_procs();
  const unsigned int omp_max_threads = omp_get_max_threads();

  if (processor_count < 2) {
    std::cerr << "processor_count is less than 2" << std::endl;
    return false;
  }
  if (processor_count == omp_processor_count &&
      processor_count == omp_max_threads) {
    std::cerr << "Success: processor_count: " << processor_count << std::endl;
    std::cerr << "Success: omp_processor_count: " << omp_processor_count
              << std::endl;
    std::cerr << "Success: omp_max_threads: " << omp_max_threads << std::endl;
    return true;
  }

  std::cerr << "Failure: processor_count: " << processor_count << std::endl;
  std::cerr << "Failure: omp_processor_count: " << omp_processor_count
            << std::endl;
  std::cerr << "Failure: omp_max_threads: " << omp_max_threads << std::endl;
  return false;
}

inline bool openmp_parallel_pragma_is_working_in_header() {
  const unsigned int omp_max_threads = omp_get_max_threads();

  if (omp_max_threads < 2) {
    std::cerr << "omp_max_threads is less than 2" << std::endl;
    return false;
  }

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
bool openmp_thread_count_is_same_as_std_thread_count_in_library();
bool openmp_is_defined_for_compiler_in_library();
bool openmp_parallel_pragma_is_working_in_library();

} // namespace demonstrate_meson_openmp
