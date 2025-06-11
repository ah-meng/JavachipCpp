//
// Created by bklee on 25. 3. 25.
//

#ifndef ISWITCHABLE_H
#define ISWITCHABLE_H

class ISwitchable {
  public:
    virtual ~ISwitchable() = default;
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
};

#endif //ISWITCHABLE_H
