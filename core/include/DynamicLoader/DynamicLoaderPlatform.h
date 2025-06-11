//
// Created by JavaChip on 24. 10. 29.
//

#ifndef DYNAMICLOADERPLATFORM_H
#define DYNAMICLOADERPLATFORM_H
#include <DynamicLoader/IDynamicLoaderPlatform.h>

class DynamicLoaderPlatform final : public IDynamicLoaderPlatform {
public:
    void* LoadDynamicLibrary(const std::string& path) override;
    void* GetFunction(void* handle, const std::string& name) override;
    void UnloadLibrary(void* handle) override;
};

#endif //DYNAMICLOADERPLATFORM_H
