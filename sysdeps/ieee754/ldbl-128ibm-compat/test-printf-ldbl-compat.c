/* Test for the long double variants of *printf functions.
   Copyright (C) 2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include <support/check.h>

static void
do_test_call_varg (FILE *stream, const char *format, ...)
{
  va_list args;

  printf ("%20s", "vfprintf: ");
  va_start (args, format);
  vfprintf (stream, format, args);
  va_end (args);
  printf ("\n");
}

static int
do_test (void)
{
  long double ld = -1;

  /* Print in decimal notation.  */
  do_test_call_varg (stdout, "%.60Lf", ld);

  /* Print in hexadecimal notation.  */
  do_test_call_varg (stdout, "%.60La", ld);

  return 0;
}

#include <support/test-driver.c>
