//
// Created by JavaChip on 24. 10. 29.
//

#include "DynamicLoader/DynamicLoaderPlatform.h"
#include <stdexcept>
#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#endif


void* DynamicLoaderPlatform::LoadDynamicLibrary(const std::string& path) {

    void* handle = nullptr;

#ifdef _WIN32
    handle = LoadLibrary(path.c_str());
    if (!handle)
        throw std::runtime_error("Failed to load library");
#else
    handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle)
        throw std::runtime_error(dlerror());
#endif

    return handle;
}

void* DynamicLoaderPlatform::GetFunction(void* handle, const std::string& name) {
#ifdef _WIN32
    return reinterpret_cast<void*>(GetProcAddress((HMODULE) handle, name.c_str()));
#else
    return reinterpret_cast<void*>(dlsym(handle, name.c_str()));
#endif
}

void DynamicLoaderPlatform::UnloadLibrary(void* handle) {
#ifdef _WIN32
    FreeLibrary((HMODULE) handle);
#else
    dlclose(handle);
#endif
}
