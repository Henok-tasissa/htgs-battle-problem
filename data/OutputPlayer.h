//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_OUTPUTPLAYER_H
#define HTGS_TUTORIALS_OUTPUTPLAYER_H

#include <htgs/api/IData.hpp>
#include "./Player.h"
class OutputPlayer: public htgs::IData{
public:
    OutputPlayer(std::shared_ptr<Player> player): player(player){}
    std::shared_ptr<Player> getPlayer(){
        return player;
    }
private:
    std::shared_ptr<Player> player;
};
#endif //HTGS_TUTORIALS_OUTPUTPLAYER_H
