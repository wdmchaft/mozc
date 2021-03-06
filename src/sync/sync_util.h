// Copyright 2010-2012, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MOZC_SYNC_SYNC_UTIL_H_
#define MOZC_SYNC_SYNC_UTIL_H_

#include <string>
#include "base/base.h"

namespace mozc {
namespace sync {

// Abstract interface which represents time function.
class ClockTimerInterface {
 public:
  virtual uint64 GetCurrentTime() const = 0;

  ClockTimerInterface() {}
  virtual ~ClockTimerInterface() {}
};

// Common util for sync adapters.
class SyncUtil {
 public:
  // Copy |current| to |prev|.
  // On windows, makes |prev| file 'system hidden' file.
  static bool CopyLastSyncedFile(const string &current,
                                 const string &prev);

  // Return random string whose size is |size|.
  // Used for unittesting.
  static string GenRandomString(int size);

 private:
  SyncUtil() {}
  ~SyncUtil() {}
};
}  // sync
}  // mozc

#endif  // MOZC_SYNC_UTIL_H_
