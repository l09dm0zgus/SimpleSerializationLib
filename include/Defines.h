#if defined(_WIN32)
#define EXPORT_API  __declspec(dllexport)
#else
#define EXPORT_API
#endif