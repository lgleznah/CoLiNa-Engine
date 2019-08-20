//
// Created by usuario on 20/8/19.
//

#ifndef COLINA_ENGINE_PRINT_H
#define COLINA_ENGINE_PRINT_H

#include "Action.h"

#include <string>

class Print : public Action {
    public:
        Print(GameManager *mgr, std::string text);
        virtual void run() override ;
};


#endif //COLINA_ENGINE_PRINT_H
