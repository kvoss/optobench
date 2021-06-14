from distutils.core import setup, Extension
# import sysconfig

# extra_compile_args = sysconfig.get_config_var('CXXFLAGS').split()
extra_compile_args = []
extra_compile_args += ['-std=c++17', '-Wall', '-Wextra']


CLASSIFIERS = """\
Development Status :: 2 - Pre-Alpha
Intended Audience :: Developers
Intended Audience :: Education
Intended Audience :: Science/Research
License :: OSI Approved :: BSD License
Programming Language :: C++
Programming Language :: Python
Programming Language :: Python :: 3
Programming Language :: Python :: 3.7
Programming Language :: Python :: 3.8
Programming Language :: Python :: 3.9
Topic :: Software Development :: Libraries
Topic :: Scientific/Engineering
Topic :: Scientific/Engineering :: Artificial Intelligence
Topic :: Scientific/Engineering :: Mathematics
Operating System :: Microsoft :: Windows
Operating System :: POSIX
Operating System :: POSIX :: Linux
Operating System :: Unix
Operating System :: MacOS
"""


setup(name='cbench',
      version='0.2.0',
      author='K. Voss',
      author_email='k.voss@usask.ca',
      url="https://github.com/kvoss/optobench",
      download_url="https://github.com/kvoss/optobench/releases",
      license="BSD 3-Clause License",
      classifiers=[cs for cs in CLASSIFIERS.split('\n') if cs],
      platforms=["Windows", "Linux", "Solaris", "Mac OS-X", "Unix"],
      # include_package_data=True,
      ext_modules=[
          Extension('cbench',
                    ['cbench.cc', 'bss.cc'],
                    extra_compile_args=extra_compile_args,
                    libraries=['stdc++'],
                    language='c++17'
          )
      ]
)
