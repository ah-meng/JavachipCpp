//
// Created by bklee on 25. 5. 19.
//

#ifndef ILISTENER_H
#define ILISTENER_H

template<typename T>
class IListener {
public:
    virtual ~IListener() = default;

    virtual void OnNotify(const T &data) = 0;
};

#endif //ILISTENER_H

