//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_OUTPUTFIGHTERS_H
#define HTGS_TUTORIALS_OUTPUTFIGHTERS_H

#include <htgs/api/IData.hpp>
#include "Player.h"
#include "OutputPlayer.h"
class OutputFighters: public htgs::IData{
public:
    OutputFighters(std::shared_ptr<Player> playerA,std::shared_ptr<Player> playerB): playerA(playerA),playerB(playerB){}

    std::shared_ptr<Player> getPlayerA(){return playerA;}
    std::shared_ptr<Player> getPlayerB(){return playerB;}

private:
    std::shared_ptr<Player> playerA;
    std::shared_ptr<Player> playerB;
};
#endif //HTGS_TUTORIALS_OUTPUTFIGHTERS_H
