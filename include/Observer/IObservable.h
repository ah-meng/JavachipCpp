//
// Created by bklee on 25. 5. 19.
//

#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#include <memory>

template<typename T>
class IObservable {
public:
    virtual ~IObservable() = default;

    virtual void Subscribe(std::shared_ptr<T> observer) = 0;

    virtual void UnSubscribe(std::shared_ptr<T> observer) = 0;
};

#endif //IOBSERVABLE_H
