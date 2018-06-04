ifeq ($(subdir),stdio-common)
# Wrappers for *printf functions that take long double arguments with
# IEEE binary128 format
routines += ieee128-vfprintf

# Printing long double values with IEEE binary128 format reuses the part
# of the internal float128 implementation (__printf_fp, __printf_fphex,
# and __float128 variables and union members).  Thus, the compilation of
# the following functions, must have -mfloat128 passed to the compiler.
CFLAGS-vfprintf-internal.c += -mfloat128

# Basic tests for the implementation of long double with IEEE binary128
# format and for the related redirections in installed headers.
tests-internal += test-printf-ieee128 test-printf-ibm128
CFLAGS-test-printf-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-printf-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

ifeq ($(run-built-tests),yes)
tests-special += $(objpfx)test-printf-ieee128.out
tests-special += $(objpfx)test-printf-ibm128.out
endif

$(objpfx)test-printf-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-printf-ldbl-compat.sh \
  $(objpfx)test-printf-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-printf-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-printf-ldbl-compat.sh \
  $(objpfx)test-printf-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

# XXX: DO NOT COMMIT.
#
# On powerpc64le, the implementation of long double with IEEE binary128
# format is not complete.  The redirections of the stdio.h functions
# are supposed to be implemented in bits/stdio-ldbl.h, however, we can
# only redirect all or none.  In the meantime, bits/stdio-ieee128.h
# allows us to redirect part of them for testing purposes.  */
headers += bits/stdio-ieee128.h
endif
