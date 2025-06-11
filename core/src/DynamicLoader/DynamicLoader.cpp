//
// Created by JavaChip on 24. 10. 29.
//

#include "DynamicLoader/DynamicLoader.h"
#include "DynamicLoader/DynamicLoaderPlatform.h"

DynamicLoader::DynamicLoader(const std::string& path) : DynamicLoader(path, std::make_unique<DynamicLoaderPlatform>()) {
}

DynamicLoader::DynamicLoader(const std::string& path, std::unique_ptr<IDynamicLoaderPlatform> platform) {
    this->platform = std::move(platform);

    handle = this->platform->LoadDynamicLibrary(path);
}

DynamicLoader::~DynamicLoader() {
    if (handle != nullptr)
        platform->UnloadLibrary(handle);
}
