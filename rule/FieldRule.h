//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_FIELDRULE_H
#define HTGS_TUTORIALS_FIELDRULE_H

#include <htgs/api/IRule.hpp>
#include "../data/Player.h"
#include "../data/OutputPlayer.h"
#include "../data/OutputFighters.h"
class FieldRule: public htgs::IRule<Player, OutputFighters>{
private:
    htgs::StateContainer<std::shared_ptr<Player>>*teamAPositionState;
    htgs::StateContainer<std::shared_ptr<Player>>*teamBPositionState;

public:
    FieldRule(size_t width, size_t height){
        this->teamAPositionState = this->allocStateContainer(width,height);
        this->teamBPositionState = this->allocStateContainer(width,height);
    }

    ~FieldRule(){
        delete teamAPositionState;
        delete teamBPositionState;
    }

public:
    void applyRule(std::shared_ptr<Player> player,size_t pipelineId) override{
        switch (player->getTeam()){
            case 'A':
                this->teamAPositionState->set(player->getX(),player->getY(),player);
                if(this->teamBPositionState->has(player->getX(),player->getY())){
                    this->addResult(new OutputFighters(player,this->teamBPositionState->get(player->getX(),player->getY())));
                }
                break;
            case 'B':
                this->teamBPositionState->set(player->getX(),player->getY(),player);
                if(this->teamAPositionState->has(player->getX(),player->getY())){
                    this->addResult(new OutputFighters(player,this->teamAPositionState->get(player->getX(),player->getY())));
                }
                break;
            default:
                break;
        }
    }
    std::string getName() override {
        return "Field Rule";
    }

};

#endif //HTGS_TUTORIALS_FIELDRULE_H
