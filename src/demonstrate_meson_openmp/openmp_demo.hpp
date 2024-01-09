// SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University

// SPDX-License-Identifier: CC0-1.0

#pragma once

#include <iostream>
#include <thread>

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

// ----- compiled library functions -----
bool openmp_thread_count_is_same_as_std_thread_count_in_library();
bool openmp_is_defined_for_compiler_in_library();

} // namespace demonstrate_meson_openmp
