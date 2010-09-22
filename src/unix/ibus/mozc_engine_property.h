// Copyright 2010, Google Inc.
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

#ifndef MOZC_UNIX_IBUS_MOZC_ENGINE_PROPERTY_H_
#define MOZC_UNIX_IBUS_MOZC_ENGINE_PROPERTY_H_

#include <ibus.h>

#include "base/base.h"
#include "session/commands.pb.h"

namespace mozc {
namespace ibus {

// The list of properties used in ibus-mozc.
const struct MozcEngineProperty {
  commands::CompositionMode composition_mode;
  const char *key;  // IBus property key for the mode.
  const char *label;  // text for the radio menu (ibus-anthy compatible).
  const char *label_for_panel;  // text for the language panel.
  const char *icon;
} kMozcEngineProperties[] = {
  {
    commands::HIRAGANA,
    "CompositionMode.Hiragana",
    "Hiragana",
    "\xe3\x81\x82",  // Hiragana letter A
    "hiragana.png",
  },
  {
    commands::FULL_KATAKANA,
    "CompositionMode.Katakana",
    "Katakana",
    "\xe3\x82\xa2",  // Katakana letter A
    "katakana_full.png",
  },
  {
    commands::HALF_ASCII,
    "CompositionMode.Latin",
    "Latin",
    "_A",
    "alpha_half.png",
  },
  {
    commands::FULL_ASCII,
    "CompositionMode.WideLatin",
    "Wide Latin",
    "\xef\xbc\xa1",  // Full width ASCII letter A
    "alpha_full.png",
  },
  {
    commands::HALF_KATAKANA,
    "CompositionMode.HalfWidthKatakana",
    "Half width katakana",
    "_\xef\xbd\xb1",  // Half width Katakana letter A
    "katakana_half.png",
  },
};

const size_t kMozcEnginePropertiesSize = arraysize(kMozcEngineProperties);
// DIRECT mode is obsolete and not supported.
COMPILE_ASSERT((commands::NUM_OF_COMPOSITIONS - 1)== kMozcEnginePropertiesSize,
               bad_number_of_props);
const commands::CompositionMode kMozcEngineInitialCompositionMode =
    commands::HIRAGANA;

const struct MozcEngineToolProperty {
  const char *key;    // IBus property key for the MozcTool.
  const char *mode;   // command line passed as --mode=
  const char *label;  // text for the menu.
  const char *icon;   // icon
} kMozcEngineToolProperties[] = {
  {
    "Tool.ConfigDialog",
    "config_dialog",
    "Property",
    "properties.png",
  },
  {
    "Tool.DictionaryTool",
    "dictionary_tool",
    "Dictionary tool",
    "dictionary.png",
  },
  {
    "Tool.AboutDialog",
    "about_dialog",
    "About Mozc",
    NULL,
  },
};

const size_t kMozcEngineToolPropertiesSize =
    arraysize(kMozcEngineToolProperties);
}  // namespace ibus
}  // namespace mozc

#endif  // MOZC_UNIX_IBUS_MOZC_ENGINE_PROPERTY_H_