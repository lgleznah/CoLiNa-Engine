//
// Created by usuario on 20/8/19.
//

#ifndef COLINA_ENGINE_ENDGAME_H
#define COLINA_ENGINE_ENDGAME_H

#include "Action.h"

class EndGame : public Action {
    public:
        EndGame();
        virtual void run() override;
};


#endif //COLINA_ENGINE_ENDGAME_H
