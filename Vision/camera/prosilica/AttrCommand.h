#ifndef _ATTR_COMMAND_H_
#define _ATTR_COMMAND_H_

#include "AttrBase.h"

#include <QPushButton>

class AttrCommand: public QPushButton, public AttrBase
{
    Q_OBJECT;

public:
    AttrCommand(tPvHandle cam, const char *name);

protected Q_SLOTS:
    void run();
};

#endif // _ATTR_COMMAND_H_