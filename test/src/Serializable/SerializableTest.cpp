//
// Created by JavaChip on 24. 11. 4.
//

#include <gtest/gtest.h>
#include <Serializable/ISerializable.h>

#include <utility>

class Person final : public ISerializable {
public:
    Person() : name(""), age(0) {
    }

    Person(std::string name, const int age) : name(std::move(name)), age(age) {
    }

    std::string Serialize() override {
        return name + "," + std::to_string(age);
    }

    void Deserialize(const std::string& data) override {
        if (const size_t pos = data.find(','); pos != std::string::npos) {
            name = data.substr(0, pos);
            age = std::stoi(data.substr(pos + 1));
        }
    }

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

private:
    std::string name;
    int age;
};


TEST(SerializableTest, Serialize) {
    Person person("John Doe", 30);
    const std::string serializedData = person.Serialize();
    EXPECT_EQ(serializedData, "John Doe,30");
}

TEST(SerializableTest, Deserialize) {
    Person person;
    person.Deserialize("Jane Doe,25");
    EXPECT_EQ(person, Person("Jane Doe", 25));
}
