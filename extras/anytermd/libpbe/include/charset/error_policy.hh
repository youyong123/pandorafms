// error_policy.hh
// This file is part of libpbe; see http://anyterm.org/
// (C) 2008 Philip Endecott

// Distributed under the Boost Software License, Version 1.0:
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef libpbe_charset_error_policy_hh
#define libpbe_charset_error_policy_hh


namespace pbe {

// Error Policies
// --------------
//
// The function template char_conv takes a template parameter that specifies
// its behaviour on error.  This file supplies implementations of the
// error_policy concept, though the user is free to supply
// their own.
//
// An error_policy class should provide the following static
// member functions, corresponding to the different errors that char_conv
// may detect:
//
// static int no_equivalent()
//   Called when the output character set does not have an equivalent
//   character.
//
// static int invalid_input()
//   Called when the input is not valid for the input character set.
//
// TODO - perhaps something for approximate equivalents?
//
// If the function returns, the value that it returns is used as the return
// value of char_conv.

// In cases where these error policies throw an exception, by default it
// is the following:
struct conversion_error {};

// Throw an exception on error:
template <typename exception = conversion_error>
struct error_policy_throw {
  static int no_equivalent() {
    throw exception();
  }
  static int invalid_input() {
    throw exception();
  }
};

// Return a sentinel value on error:
template <int sentinel>
struct error_policy_return_sentinel {
  static int no_equivalent() {
    return sentinel;
  }
  static int invalid_input() {
    return sentinel;
  }
};


// The default error policy is error_policy_throw:

typedef error_policy_throw<> default_error_policy;


};

#endif
