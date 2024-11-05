//
// Created by JavaChip on 24. 10. 31.
//

#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <string>

class ISerializable
{
public:
    virtual std::string Serialize() = 0;
    virtual void Deserialize(const std::string& data) = 0;
    virtual ~ISerializable() = default;
};

#endif //ISERIALIZABLE_H
