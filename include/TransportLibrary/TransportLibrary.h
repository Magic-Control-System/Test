#pragma once

#if defined(_WIN32) && defined(_DLL)
#if !defined(TRANSPORT_LIBRARY_DLL) && !defined(TRANSPORT_LIBRARY_STATIC)
#define TRANSPORT_LIBRARY_DLL
#endif
#endif


//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the Foundation_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// Foundation_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if (defined(_WIN32) || defined(_WIN32_WCE)) && defined(TRANSPORT_LIBRARY_DLL)
#if defined(TRANSPORT_LIBRARY_EXPORTS)
#define TRANSPORT_LIBRARY_API __declspec(dllexport)
#else
#define TRANSPORT_LIBRARY_API __declspec(dllimport)
#endif
#endif


#if !defined(TRANSPORT_LIBRARY_API)
#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
#define TRANSPORT_LIBRARY_API __attribute__ ((visibility ("default")))
#else
#define TRANSPORT_LIBRARY_API
#endif
#endif


//
// Automatically link Foundation library.
//
#if defined(_MSC_VER)
#if defined(TRANSPORT_LIBRARY_DLL)
#if defined(_DEBUG)
#define TRANSPORT_LIBRARY_LIB_SUFFIX ".lib"
#else
#define TRANSPORT_LIBRARY_LIB_SUFFIX ".lib"
#endif
#elif defined(_DLL)
#if defined(_DEBUG)
#define TRANSPORT_LIBRARY_LIB_SUFFIX "mdd.lib"
#else
#define TRANSPORT_LIBRARY_LIB_SUFFIX "md.lib"
#endif
#else
#if defined(_DEBUG)
#define TRANSPORT_LIBRARY_LIB_SUFFIX "mtd.lib"
#else
#define TRANSPORT_LIBRARY_LIB_SUFFIX "mt.lib"
#endif
#endif

#if !defined(TRANSPORT_LIBRARY_NO_AUTOMATIC_LIBS) && !defined(TRANSPORT_LIBRARY_EXPORTS)
#pragma comment(lib, "TransportLibrary" TRANSPORT_LIBRARY_LIB_SUFFIX)
#endif
#endif
