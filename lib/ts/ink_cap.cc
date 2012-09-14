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

# include "ink_config.h"
# include "Diags.h"
# include "ink_cap.h"

# if TS_USE_POSIX_CAP
#   include <sys/capability.h>
#   include <sys/prctl.h>
# endif

void
DebugCapabilities(char const* tag) {
  if (is_debug_tag_set(tag)) {
#   if TS_USE_POSIX_CAP
      cap_t caps = cap_get_proc();
      char* caps_text = cap_to_text(caps, 0);
#   endif

    Debug(tag,
      "uid=%u, gid=%u, euid=%u, egid=%u"
#     if TS_USE_POSIX_CAP
        ", caps %s thread 0x%x"
#     endif
      ,static_cast<unsigned int>(getuid())
      ,static_cast<unsigned int>(getgid())
      ,static_cast<unsigned int>(geteuid())
      ,static_cast<unsigned int>(getegid())
#     if TS_USE_POSIX_CAP
        ,caps_text
        ,pthread_self()
#     endif
    );

#   if TS_USE_POSIX_CAP
      cap_free(caps_text);
      cap_free(caps);
#   endif
  }
}

int
PreserveCapabilities() {
  int zret = 0;
# if TS_USE_POSIX_CAP
    zret = prctl(PR_SET_KEEPCAPS, 1);
# endif
  return zret;
}

// Adjust the capabilities to only those needed.
int
RestrictCapabilities() {
  int zret = 0; // return value.
# if TS_USE_POSIX_CAP
    cap_t caps = cap_init(); // start with nothing.
    // Capabilities we need.
    cap_value_t cap_list[] = { CAP_NET_ADMIN, CAP_NET_BIND_SERVICE, CAP_IPC_LOCK };
    static int const CAP_COUNT = sizeof(cap_list)/sizeof(*cap_list);

    cap_set_flag(caps, CAP_PERMITTED, CAP_COUNT, cap_list, CAP_SET);
    cap_set_flag(caps, CAP_EFFECTIVE, CAP_COUNT, cap_list, CAP_SET);
    zret = cap_set_proc(caps);
    cap_free(caps);
#  endif
  return zret;
}
