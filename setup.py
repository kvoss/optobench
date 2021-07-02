from distutils.core import setup, Extension
import numpy as np
# import sysconfig

# extra_compile_args = sysconfig.get_config_var('CXXFLAGS').split()
extra_compile_args = []
numpy_include_dir = np.get_include()
extra_compile_args += ['-std=c++17', '-Wall', '-Wextra', '-I{0}'.format(numpy_include_dir)]
extra_link_args = []  # '-L/usr/lib/python3/dist-packages/numpy/core/lib/']
setup(name='cbench',
      version='0.1.0',
      author='K. Voss',
      author_email='k.voss@usask.ca',
      url="https://github.com/kvoss/optobench",
      license="BSD 3-Clause License",
      classifiers=[
          "License :: OSI Approved :: BSD License",
          "Programming Language :: Python :: 3",
          "Programming Language :: Python :: 3.8",
      ],
      ext_modules=[
          Extension('cbench',
                    ['cbench.cc', 'bss.cc'],
                    extra_compile_args=extra_compile_args,
                    extra_link_args=extra_link_args,
                    libraries=['stdc++'],
                    language='c++17'
          )
      ]
)
