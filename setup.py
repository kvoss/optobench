from distutils.core import setup, Extension
# import sysconfig

# extra_compile_args = sysconfig.get_config_var('CFLAGS').split()
extra_compile_args = []
extra_compile_args += ["-std=c++11", "-Wall", "-Wextra"]

setup(name='cbench',
      ext_modules=[
          Extension('cbench'
                    , ['cbench.cpp', 'bss.cpp']
                    , extra_compile_args=extra_compile_args
                    , libraries=['stdc++']
                    , language='c++11'
          )
      ]
)

