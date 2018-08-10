//
// Copyright (c) 2008-2017 the miniclib project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "../Container/Vector.h"
#include "../Container/List.h"
#include "../Container/HashSet.h"
#include "../Container/HashMap.h"

#include <algorithm>

// VS2010+ and other compilers: use std::begin(), std::end() & range based for
// C++11 features need to be enabled
#if !defined(_MSC_VER) || _MSC_VER > 1600
#define foreach(VAL, VALS) for (VAL : VALS)
// Fallback solution for VS2010. Will have problem with break statement.
// See https://github.com/urho3d/miniclib/issues/561
#else

namespace miniclib
{

template<typename T>
struct false_wrapper {
    false_wrapper(const T& value) : value(value) { }
    operator bool() const { return false; }
    T value;
};

template<typename T>
false_wrapper<T> make_false_wrapper(const T& value) {
    return false_wrapper<T>(value);
}

// vector support functions

template <class T>
miniclib::RandomAccessIterator<T> Begin(miniclib::Vector<T> &v) {
    return v.Begin();
}
template <class T>
miniclib::RandomAccessIterator<T> Begin(miniclib::Vector<T> *v) {
    return v->Begin();
}

template <class T>
miniclib::RandomAccessConstIterator<T> Begin(const miniclib::Vector<T> &v) {
    return v.Begin();
}
template <class T>
miniclib::RandomAccessConstIterator<T> Begin(const miniclib::Vector<T> *v) {
    return v->Begin();
}

template <class T>
miniclib::RandomAccessIterator<T> End(miniclib::Vector<T> &v) {
    return v.End();
}
template <class T>
miniclib::RandomAccessIterator<T> End(miniclib::Vector<T> *v) {
    return v->End();
}

template <class T>
miniclib::RandomAccessConstIterator<T> End(const miniclib::Vector<T> &v) {
    return v.End();
}
template <class T>
miniclib::RandomAccessConstIterator<T> End(const miniclib::Vector<T> *v) {
    return v->End();
}

// podvector support functions

template <class T>
miniclib::RandomAccessIterator<T> Begin(miniclib::PODVector<T> &v) {
    return v.Begin();
}
template <class T>
miniclib::RandomAccessIterator<T> Begin(miniclib::PODVector<T> *v) {
    return v->Begin();
}

template <class T>
miniclib::RandomAccessConstIterator<T> Begin(const miniclib::PODVector<T> &v) {
    return v.Begin();
}
template <class T>
miniclib::RandomAccessConstIterator<T> Begin(const miniclib::PODVector<T> *v) {
    return v->Begin();
}

template <class T>
miniclib::RandomAccessIterator<T> End(miniclib::PODVector<T> &v) {
    return v.End();
}
template <class T>
miniclib::RandomAccessIterator<T> End(miniclib::PODVector<T> *v) {
    return v->End();
}

template <class T>
miniclib::RandomAccessConstIterator<T> End(const miniclib::PODVector<T> &v) {
    return v.End();
}
template <class T>
miniclib::RandomAccessConstIterator<T> End(const miniclib::PODVector<T> *v) {
    return v->End();
}

}

#define foreach(VAL, VALS) \
    if (const auto& _foreach_begin = miniclib::make_false_wrapper(miniclib::Begin(VALS))) { } else \
    if (const auto& _foreach_end = miniclib::make_false_wrapper(miniclib::End(VALS))) { } else \
    for (auto it = _foreach_begin.value; it != _foreach_end.value; ++it) \
    if (bool _foreach_flag = false) { } else \
    for (VAL = *it; !_foreach_flag; _foreach_flag = true)

#endif
