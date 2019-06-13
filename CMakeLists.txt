cmake_minimum_required(VERSION 3.14)
project(BattleV2)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DPROFILE)

add_executable(BattleV2 main.cpp data/InitializePlayer.h data/OutputPlayer.h data/Player.h task/GeneratePlayer.h rule/FieldRule.h task/FightTask.h data/OutputResult.h data/OutputFighters.h)