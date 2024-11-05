//
// Created by JavaChip on 24. 10. 29.
//

#ifndef JAVACHIPCPP_DYNAMICLOADER_H
#define JAVACHIPCPP_DYNAMICLOADER_H

#include <memory>
#include <stdexcept>
#include <string>

#include "IDynamicLoaderPlatform.h"

class DynamicLoader {
public:
    explicit DynamicLoader(const std::string& path);
    DynamicLoader(const std::string& path, std::unique_ptr<IDynamicLoaderPlatform> platform);

    ~DynamicLoader();

    template<typename T>
    [[nodiscard]] T LoadFunction(const std::string& name);

private:
    void* handle = nullptr;
    std::unique_ptr<IDynamicLoaderPlatform> platform;
};

template<typename T>
T DynamicLoader::LoadFunction(const std::string& name) {
    T func = reinterpret_cast<T>(platform->GetFunction(handle, name));

    if (!func)
        throw std::runtime_error("Failed to load function: " + name);

    return func;
}

#endif //JAVACHIPCPP_DYNAMICLOADER_H
