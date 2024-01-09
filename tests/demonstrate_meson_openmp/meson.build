# SPDX-FileCopyrightText: 2024 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

testcomponent = 'demonstrate_meson_openmp'

sources = [
    'openmp_defined.test.cpp',
    'openmp_parallel_pragma.test.cpp',
    'openmp_thread_count.test.cpp',
]

foreach source : sources
    testname = testcomponent + '.' + source.split('.')[0] + '_.test'
    testname = testname.replace('/', '.')

    testexe = executable(testname,
            sources: [source],
            dependencies : [catch2, demolib_dep],
            link_language : 'cpp',
            override_options: [
            ]
            )

    test(testname,testexe)
endforeach








