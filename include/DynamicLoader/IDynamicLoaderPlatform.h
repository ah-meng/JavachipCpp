//
// Created by JavaChip on 24. 10. 29.
//

#ifndef IDYNAMICLOADERPLATFORM_H
#define IDYNAMICLOADERPLATFORM_H

#include <string>

class IDynamicLoaderPlatform {
public:
    virtual ~IDynamicLoaderPlatform() = default;

    virtual void* LoadDynamicLibrary(const std::string& path) = 0;
    virtual void* GetFunction(void* handle, const std::string& name) = 0;
    virtual void UnloadLibrary(void* handle) = 0;
};

#endif //IDYNAMICLOADERPLATFORM_H
