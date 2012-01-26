# Copyright 2010-2012, Google Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#     * Neither the name of Google Inc. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

{
  'variables': {
    'relative_dir': 'base',
    'gen_out_dir': '<(SHARED_INTERMEDIATE_DIR)/<(relative_dir)',
  },
  'targets': [
    {
      'target_name': 'base_test',
      'type': 'executable',
      'sources': [
        'clock_mock_test.cc',
        'cpu_stats_test.cc',
        'crash_report_util_test.cc',
        'encryptor_test.cc',
        'password_manager_test.cc',
        'process_mutex_test.cc',
        'scheduler_test.cc',
        'stopwatch_test.cc',
        'svm_test.cc',
        'timer_test.cc',
        'unnamed_event_test.cc',
        'update_util_test.cc',
        'url_test.cc',
      ],
      'dependencies': [
        'base.gyp:base',
        '../testing/testing.gyp:gtest_main',
      ],
      'variables': {
        'test_size': 'small',
      },
    },
    {
      'target_name': 'base_core_test',
      'type': 'executable',
      'sources': [
        'bitarray_test.cc',
        'flags_test.cc',
        'hash_tables_test.cc',
        'logging_test.cc',
        'mmap_test.cc',
        'mutex_test.cc',
        'singleton_test.cc',
        'stl_util_test.cc',
        'thread_test.cc',
        'text_normalizer_test.cc',
        'util_test.cc',
        'version_test.cc',
      ],
      'dependencies': [
        '../testing/testing.gyp:gtest_main',
        'base.gyp:base_core',
      ],
      'variables': {
        'test_size': 'small',
      },
    },
    # init_test.cc is separated from all other base_core_test because it
    # calls finalizers.
    {
      'target_name': 'base_init_test',
      'type': 'executable',
      'sources': [
        'init_test.cc',
      ],
      'dependencies': [
        '../testing/testing.gyp:gtest_main',
        'base.gyp:base',
      ],
      'variables': {
        'test_size': 'small',
      },
    },
    {
      'target_name': 'config_file_stream_test',
      'type': 'executable',
      'sources': [
        'config_file_stream_test.cc',
      ],
      'dependencies': [
        '../testing/testing.gyp:gtest_main',
        'base.gyp:config_file_stream',
      ],
      'variables': {
        'test_size': 'small',
      },
    },
    # Test cases meta target: this target is referred from gyp/tests.gyp
    {
      'target_name': 'base_all_test',
      'type': 'none',
      'dependencies': [
        'base_core_test',
        'base_init_test',
        'base_test',
        'config_file_stream_test',
      ],
    },
  ],
}
