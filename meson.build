project('ASCII-transfer', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++17', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

add_global_arguments('-I ~/workspace/builds/asio/asio/include/', language : 'cpp')
add_global_arguments('-DASIO_STANDALONE', language : 'cpp')
add_global_arguments('-DASIO_NO_DEPRECATED', language : 'cpp')

inc_dir = include_directories(['include',
                               get_option('asio_include_dir'),
                               get_option('cli11_include_dir')
#                               get_option('spdlog_include_dir'),
#                               get_option('json_include_dir'),                              
                              ])

#subdir('XXX')


executable('client',
            sources : 'src/client/main.cpp',
            include_directories : inc_dir,
            dependencies : thread_dep
            #link_with : XXX_lib
           )


executable('server',
            sources : 'src/server/main.cpp',
            include_directories : inc_dir,
            dependencies : thread_dep
            #link_with : XXX_lib
           )
# doctest_dir = include_directories([get_option('doctest_include_dir')])

# test_src = ['tests/test1.cpp',
#             'src/stack.cpp']

# test_exe = executable('test1',
#                       sources : test_src,
#                       include_directories : [inc_dir, doctest_dir],
#                       dependencies : lib_fmt)

# test('test1', test_exe)

