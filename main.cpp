#include <iostream>

#include <htgs/api/TaskGraphConf.hpp>
#include <htgs/api/TaskGraphRuntime.hpp>
#include "./task/GeneratePlayer.h"
#include "./task/FightTask.h"
#include "./data/OutputFighters.h"
#include "./data/OutputResult.h"
#include "./rule/FieldRule.h"
int main() {

    size_t field_width = 10;
    size_t field_height = 10;

    int teamAwinCount = 0;
    int teamBwinCount = 0;
    int teamDrawCount = 0;

    GeneratePlayer *generatePlayer = new GeneratePlayer();
    FightTask *fightTask = new FightTask(5);
    FieldRule *fieldRule = new FieldRule(field_width,field_height);

    auto bookkeeper = new htgs::Bookkeeper<Player>();

    auto taskGraph = new htgs::TaskGraphConf<InitializePlayer,OutputResult>();

    taskGraph->setGraphConsumerTask(generatePlayer);
    taskGraph->addEdge(generatePlayer,bookkeeper);
    taskGraph->addRuleEdge(bookkeeper,fieldRule,fightTask);
    taskGraph->addGraphProducerTask(fightTask);

    taskGraph->writeDotToFile("battleV2.dot", DOTGEN_COLOR_COMP_TIME | DOTGEN_FLAG_SHOW_ALL_THREADING | DOTGEN_FLAG_SHOW_CONNECTORS);

    auto runtime = new htgs::TaskGraphRuntime(taskGraph);
    runtime->executeRuntime();

    for (size_t i=0;i<field_width;i++){
        for (size_t j = 0; j < field_height; ++j) {
            auto playerA = new InitializePlayer(i,j,'A');
            auto playerB = new InitializePlayer(i,j,'B');
            taskGraph->produceData(playerA);
            taskGraph->produceData(playerB);
        }
    }

    taskGraph->finishedProducingData();
    runtime->waitForRuntime();

    while (!taskGraph->isOutputTerminated()){
        auto data = taskGraph->consumeData();
        if(data != nullptr){
            if(data->isDraw()) {
                std::cout << "Draw at position " << data->getWinner()->getX() << ", " << data->getWinner()->getY()
                          << " strenght: " << data->getWinner()->getStrength() << std::endl;

                teamDrawCount++;
            }else{
                std::cout << "Winner:  " << data->getWinner()->getTeam() << " at: "  << data->getWinner()->getX() << ", " << data->getWinner()->getY() << " strenght: " << data->getWinner()->getStrength() <<std::endl;
                if(data->getWinner()->getTeam()=='A'){teamAwinCount++;}
                else{teamBwinCount++;}
            }
      }
    }
    std::cout<<"Total Win Count: "<<std::endl;
    std::cout<<"\tTeam A : "<<teamAwinCount<<std::endl;
    std::cout<<"\tTeam B : "<<teamBwinCount<<std::endl;
    std::cout<<"\tTeam Draw : "<<teamDrawCount<<std::endl;


    taskGraph->writeDotToFile("battleV2afterresult.dot", DOTGEN_COLOR_COMP_TIME | DOTGEN_FLAG_SHOW_ALL_THREADING | DOTGEN_FLAG_SHOW_CONNECTORS);
    delete runtime;
    return 0;
}