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

#ifndef MINICLIB_API_H
#define MINICLIB_API_H

#pragma warning(disable: 4251)
#pragma warning(disable: 4275)

#define MINICLIB_STATIC_DEFINE
#define MINICLIB_OPENGL
/* #undef MINICLIB_D3D11 */
#define MINICLIB_SSE
/* #undef MINICLIB_DATABASE_ODBC */
/* #undef MINICLIB_DATABASE_SQLITE */
/* #undef MINICLIB_LUAJIT */
/* #undef MINICLIB_TESTING */

#ifdef MINICLIB_STATIC_DEFINE
#  define MINICLIB_API
#  define MINICLIB_NO_EXPORT
#else
#  ifndef MINICLIB_API
#    ifdef Urho3D_EXPORTS
        /* We are building this library */
#      define MINICLIB_API __declspec(dllexport)
#    else
        /* We are using this library */
#      define MINICLIB_API __declspec(dllimport)
#    endif
#  endif

#  ifndef MINICLIB_NO_EXPORT
#    define MINICLIB_NO_EXPORT 
#  endif
#endif

#ifndef MINICLIB_DEPRECATED
#  define MINICLIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef MINICLIB_DEPRECATED_EXPORT
#  define MINICLIB_DEPRECATED_EXPORT MINICLIB_API MINICLIB_DEPRECATED
#endif

#ifndef MINICLIB_DEPRECATED_NO_EXPORT
#  define MINICLIB_DEPRECATED_NO_EXPORT MINICLIB_NO_EXPORT MINICLIB_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define MINICLIB_NO_DEPRECATED
#endif

#define NONSCRIPTABLE 

#endif
