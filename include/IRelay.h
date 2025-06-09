//
// Created by bklee on 25. 3. 25.
//

#ifndef IRELAY_H
#define IRELAY_H

#include "ISwitchable.h"

class IRelay : public ISwitchable {
  public:
    virtual ~IRelay() = default;
};

#endif //IRELAY_H
