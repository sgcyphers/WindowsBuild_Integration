/*
 * pthread_equal.c
 *
 * Description:
 * This translation unit implements miscellaneous thread functions.
 *
 * --------------------------------------------------------------------------
 *
 *      Pthreads4w - POSIX Threads Library for Win32
 *      Copyright(C) 1998 John E. Bossom
 *      Copyright(C) 1999-2018, Pthreads4w contributors
 *
 *      Homepage: https://sourceforge.net/projects/pthreads4w/
 *
 *      The current list of contributors is contained
 *      in the file CONTRIBUTORS included with the source
 *      code distribution. The list can also be seen at the
 *      following World Wide Web location:
 *      https://sourceforge.net/p/pthreads4w/wiki/Contributors/
 *
 * This file is part of Pthreads4w.
 *
 *    Pthreads4w is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Pthreads4w is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Pthreads4w.  If not, see <http://www.gnu.org/licenses/>. *
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "pthread.h"
#include "implement.h"


int
pthread_equal (pthread_t t1, pthread_t t2)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      This function returns nonzero if t1 and t2 are equal, else
      *      returns zero
      *
      * PARAMETERS
      *      t1,
      *      t2
      *              thread IDs
      *
      *
      * DESCRIPTION
      *      This function returns nonzero if t1 and t2 are equal, else
      *      returns zero.
      *
      * RESULTS
      *              non-zero        if t1 and t2 refer to the same thread,
      *              0               t1 and t2 do not refer to the same thread
      *
      * ------------------------------------------------------
      */
{
  int result;

  /*
   * We also accept NULL == NULL - treating NULL as a thread
   * for this special case, because there is no error that we can return.
   */
  result = ( t1.p == t2.p && t1.x == t2.x );

  return (result);

}				/* pthread_equal */