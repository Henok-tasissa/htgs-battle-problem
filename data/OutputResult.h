//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_OUTPUTRESULT_H
#define HTGS_TUTORIALS_OUTPUTRESULT_H

#include <htgs/api/IData.hpp>
#include "OutputPlayer.h"
#include "Player.h"
class OutputResult: public htgs::IData{
public:
//    OutputResult(Player player): result(player){}
//
//    Player getResult(){
//        return result;
//    }

    OutputResult(const std::shared_ptr<Player> &winner, const bool &draw = false) : winner(winner), draw(draw) {}

    const std::shared_ptr<Player> &getWinner() const {

            return winner;

    }

    bool isDraw() const {
        return draw;
    }

private:
    std::shared_ptr<Player> winner;
    bool draw;
};
#endif //HTGS_TUTORIALS_OUTPUTRESULT_H
