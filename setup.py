
import time

from distribute_setup import use_setuptools
use_setuptools()

from setuptools import setup
from setuptools.extension import Extension

from Cython.Distutils import build_ext

# Cython extension.
source_files = ['wrapper_inner.pyx']

include_dirs = ['C:/Python27/include',
                'C:/Python27/Lib/site-packages/numpy/core/include']
extra_compile_args = ['/openmp', '/EHsc']

ext = Extension('wrapper_inner', source_files,
                language='c++',
                include_dirs=include_dirs,
                extra_compile_args=extra_compile_args)

# Time stamp.
localtime = time.localtime()
date_stamp = '%4i.%02i.%02i' % (localtime.tm_year, localtime.tm_mon, localtime.tm_mday)

# Do it.
setup(name='wrapper_inner',
      cmdclass={'build_ext':build_ext},
      ext_modules=[ ext ],

      # Metadata
      version=date_stamp,
      author='Pierre V. Villeneuve',
      author_email='pierre.villeneuve@gmail.com',
      description='Demonstration of Python/Cython embedded within C++',
)
