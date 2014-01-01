/** @file

  A brief file description

  @section license License

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 */

#ifndef _ink_unused_h
#define _ink_unused_h

#ifdef DEBUG
#define RELEASE_UNUSED
#else
#define RELEASE_UNUSED __attribute__ ((unused))
#endif /* #ifdef DEBUG */

#define UNUSED __attribute__ ((unused))
#define INK_UNUSED __attribute__ ((unused))

#if 0 /* NOT USED */
# define inline               inline __attribute__ ((always_inline))
# define __pure               __attribute__ ((pure))
# define __const      __attribute__ ((const))
# define __noreturn   __attribute__ ((noreturn))
# define __must_check __attribute__ ((warn_unused_result))
# define __deprecated __attribute__ ((deprecated))
# define __used               __attribute__ ((used))
# define __unused     __attribute__ ((unused))
# define __packed     __attribute__ ((packed))
#endif

#ifndef likely
#define likely(x)	__builtin_expect (!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x)	__builtin_expect (!!(x), 0)
#endif

#endif /* #ifndef _ink_unused_h */
