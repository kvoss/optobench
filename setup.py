from distutils.core import setup, Extension
# import sysconfig

# extra_compile_args = sysconfig.get_config_var('CFLAGS').split()
extra_compile_args = []
extra_compile_args += ["-std=c++17", "-Wall", "-Wextra"]

setup(name='cbench',
      ext_modules=[
          Extension('cbench'
                    , ['cbench.cc', 'bss.cc']
                    , extra_compile_args=extra_compile_args
                    , libraries=['stdc++']
                    , language='c++17'
          )
      ]
)
