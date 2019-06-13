//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_GENERATEPLAYER_H
#define HTGS_TUTORIALS_GENERATEPLAYER_H

#include <htgs/api/ITask.hpp>
#include "../data/InitializePlayer.h"
#include "../data/OutputPlayer.h"
#include "../data/Player.h"
class GeneratePlayer: public htgs::ITask<InitializePlayer,Player>{
public:
    GeneratePlayer(){}
    virtual ~GeneratePlayer(){}

    virtual void executeTask(std::shared_ptr<InitializePlayer> InitPlayer){
        int x = InitPlayer->getX();
        int y = InitPlayer->getY();
        char t = InitPlayer->getTeam();

        std::shared_ptr<Player> player = std::make_shared<Player>(x,y,t);

        this->addResult(player);
    }

    std::string getName(){
        return "GeneratePlayer";
    }

    virtual GeneratePlayer *copy(){
        return new GeneratePlayer();
    }
};
#endif //HTGS_TUTORIALS_GENERATEPLAYER_H
