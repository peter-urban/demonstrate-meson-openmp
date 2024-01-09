// source: https://gcc.gnu.org/wiki/Visibility

// DEMOLIB_LIBRARY_BUILD is defined when building the library, and undefined when
// using (including) the library (use private compile arguments to set this)

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
  #define DEMOLIB_HELPER_DLL_IMPORT __declspec(dllimport)
  #define DEMOLIB_HELPER_DLL_EXPORT __declspec(dllexport)
  #define DEMOLIB_HELPER_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define DEMOLIB_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define DEMOLIB_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define DEMOLIB_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DEMOLIB_HELPER_DLL_IMPORT
    #define DEMOLIB_HELPER_DLL_EXPORT
    #define DEMOLIB_HELPER_DLL_LOCAL
  #endif
#endif

// Now we use the generic helper definitions above to define DEMOLIB_API and DEMOLIB_LOCAL.
// DEMOLIB_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// DEMOLIB_LOCAL is used for non-api symbols.

#ifdef DEMOLIB_DLL // defined if DEMO is compiled as a DLL
  #ifdef DEMOLIB_DLL_EXPORTS // defined if we are building the DEMO DLL (instead of using it)
    #define DEMOLIB_API DEMOLIB_HELPER_DLL_EXPORT
  #else
    #define DEMOLIB_API DEMOLIB_HELPER_DLL_IMPORT
  #endif // DEMOLIB_DLL_EXPORTS
  #define DEMOLIB_LOCAL DEMOLIB_HELPER_DLL_LOCAL
#else // DEMOLIB_DLL is not defined: this means DEMO is a static lib.
  #define DEMOLIB_API
  #define DEMOLIB_LOCAL
#endif // DEMOLIB_DLL