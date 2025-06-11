//
// Created by JavaChip on 24. 10. 31.
//

#ifndef SERIALIZABLEUTILS_H
#define SERIALIZABLEUTILS_H

#include "ISerializable.h"

template<typename T>
[[nodiscard]] T CreateFromSerialized(const std::string& serializedData) {
    static_assert(std::is_base_of_v<ISerializable, T>, "T must derive from ISerializable");

    T obj;
    obj.Deserialize(serializedData);
    return obj;
}

#endif //SERIALIZABLEUTILS_H
