MODULE_NAME := High5

_FILES := open_h5 \
          read_h5attr \
          read_h5attrs \
          read_h5dset \
          read_h5dattr \
          read_h5dattrs

_TESTS := open_h5_tests \
          read_h5attr_tests \
          read_h5attrs_tests \
          read_h5dset_tests \
          read_h5dattr_tests \
          read_h5dattrs_tests

_LIBS := -lhdf5

include ./Makefile.paCage/Makefile
