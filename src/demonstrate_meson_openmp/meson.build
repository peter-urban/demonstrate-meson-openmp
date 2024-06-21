# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# -- library setup --
libname   = 'demonstrate_meson_openmp'
headerdir = 'demonstrate_meson_openmp'

# -- source files (demo library with cpp source) --
sources = [
  'openmp_demo_lib.cpp'
]

headers = [
  'openmp_compare_thread_count.hpp',
  'openmp_openmp_defined.hpp',
  'openmp_try_parallel_pragma.hpp'
]


# -- targets --
demolib_lib = library(
  libname,
  sources,
  dependencies : [
    openmp
  ],
  cpp_shared_args: ['-DDEMOLIB_DLL', '-DDEMOLIB_DLL_EXPORTS'],
  install : true
  )

if get_option('default_library') == 'shared'
    demolib_compile_args += '-DDEMOLIB_DLL'
endif

# -- internal dependency --
demolib_dep = declare_dependency(
  dependencies : [
    openmp,
  ],
  link_with : [demolib_lib],
  compile_args : demolib_compile_args,
  include_directories : ['../']
  )



# -- installation setup --

# install headers
if headers != ['']
    install_headers(headers, subdir: headerdir+'/', preserve_path: true)
endif


# create pkgconfig file
pkg = import('pkgconfig')
pkg.generate(demolib_lib,
             #requires : [openmp],
             description : 'Test project to demonstrate how to use meson with openmp and to debug related issues.',
             url : 'https://github.com/peter-urban/demonstrate-meson-openmp')
