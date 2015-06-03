// Copyright tom zhou<iwebpp@gmail.com>, 2015.
//
// device_wrap.h, device stream binding
//

// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef DEVICE_WRAP_H_
#define DEVICE_WRAP_H_

#include "handle_wrap.h"
#include "stream_wrap.h"

namespace node {

using v8::Object;
using v8::Handle;
using v8::Local;
using v8::Value;
using v8::Arguments;


class DEVICEWrap : StreamWrap {
 public:
  static void Initialize(Handle<Object> target);

  static v8::Local<v8::Object> Instantiate();

  static DEVICEWrap* Unwrap(Local<Object> obj);

  uv_device_t* UVHandle();

 private:
  DEVICEWrap(Handle<Object> object, const char* path, int flags);
  ~DEVICEWrap();

  static Handle<Value> New(const Arguments& args);
  static Handle<Value> SetIOCtl(const Arguments& args);

  uv_device_t handle_;

  // tuntap specific ioctl
  // set tun interface name
  static Handle<Value> SetTunName(const Arguments& args);
  // set tap interface name
  static Handle<Value> SetTapName(const Arguments& args);
};

} // namespace node

#endif // DEVICE_WRAP_H_
