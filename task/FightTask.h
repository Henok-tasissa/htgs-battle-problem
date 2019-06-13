//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_FIGHTTASK_H
#define HTGS_TUTORIALS_FIGHTTASK_H
#include <htgs/api/ITask.hpp>
#include "../data/OutputFighters.h"
#include "../data/OutputResult.h"
#include "../data/Player.h"
class FightTask: public htgs::ITask<OutputFighters,OutputResult>{
public:
    FightTask(size_t numThreads) : ITask(numThreads) {}

    FightTask(){}
    virtual ~FightTask(){}

    virtual void executeTask(std::shared_ptr<OutputFighters> players){
        std::shared_ptr<Player> playerA = players->getPlayerA();
        std::shared_ptr<Player> playerB = players->getPlayerB();

        if (playerA->getStrength()>playerB->getStrength()){
            this->addResult(new OutputResult(playerA));
        }else if (playerA->getStrength()<playerB->getStrength()){
            this->addResult(new OutputResult(playerB));
        }else{
            this->addResult(new OutputResult(playerA, true));
        }
    }
    std::string getName(){
        return "Fight Task";
    }
    virtual FightTask *copy() override {
        return new FightTask();
    }
};
#endif //HTGS_TUTORIALS_FIGHTTASK_H