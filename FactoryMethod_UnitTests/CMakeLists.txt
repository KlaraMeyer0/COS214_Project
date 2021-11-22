cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED) 
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp ../DragonSpacecraft.h ../DragonSpacecraft.cpp ../CrewDragonSpacecraft.h ../CrewDragonSpacecraft.cpp ../Spacecraft.h ../Spacecraft.cpp ../DragonFactory.h ../DragonFactory.cpp ../CrewDragonFactory.h ../CrewDragonFactory.cpp ../SpacecraftFactory.h ../SpacecraftFactory.cpp ../CargoFactory.h ../CargoFactory.cpp ../RocketFactory.h ../RocketFactory.cpp ../FalconRocket.h ../FalconRocket.cpp ../Falcon9.h ../Falcon9.cpp ../FalconHeavy.h ../FalconHeavy.cpp ../HeavyEngine.h ../HeavyEngine.cpp ../_9Engine.h ../_9Engine.cpp ../FalconCore.h ../FalconCore.cpp ../StageEngine.h ../StageEngine.cpp ../Stage1Engine.h ../Stage1Engine.cpp ../Stage2Engine.h ../Stage2Engine.cpp ../Engine.h ../Engine.cpp ../VacuumEngine.h ../VacuumEngine.cpp ../MerlinEngine.h ../MerlinEngine.cpp ../FalconHeavyFactory.h ../FalconHeavyFactory.cpp ../Falcon9Factory.h ../Falcon9Factory.cpp ../HumanFactory.h ../HumanFactory.cpp ../EquipmentFactory.h ../EquipmentFactory.cpp ../Cargo.h ../Cargo.cpp ../Equipment.h ../Equipment.cpp ../Human.h ../Human.cpp factorymethod_unitTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

#include "CrewDragonFactory.h"
#include "DragonFactory.h"
#include "DragonSpacecraft.h"
#include "CrewDragonSpacecraft.h"

#../CrewDragonFactory.cpp ../CrewDragonFactory.h ../DragonFactory.cpp ../DragonFactory.h ../DragonSpacecraft.h ../DragonSpacecraft.cpp ../CrewDragonSpacecraft.h ../CrewDragonSpacecraft.cpp

#../Cargo.h ../CommunicationRelay.h ../PointOfCommunication.h ../StarlinkSatellite.h ../Station.h ../BaseStation.h ../SpaceStation.h ../FalconRocket.h ../Engine.h ../MerlinEngine.h ../FalconCore.h ../StageEngine.h ../VacuumEngine.h ../Stage1Engine.h ../Stage2Engine.h ../HeavyEngine.h ../_9Engine.h ../FalconHeavy.h ../Falcon9.h ../Rocketship.h ../LaunchFile.h ../LaunchCaretaker.h ../TestLaunch.h ../LaunchInterface.h ../StopTest.h ../Spacecraft.h ../SpacecraftFactory.h ../DragonSpacecraft.h ../CrewDragonSpacecraft.h ../CrewDragonFactory.h ../DragonFactory.h ../CargoFactory.h ../Equipment.h ../EquipmentFactory.h ../Human.h ../HumanFactory.h ../RocketFactory.h ../Falcon9Factory.h ../FalconHeavyFactory.h ../DragonRocketship.h ../CrewDragonRocketship.h ../DragonBay.h ../CrewDragonBay.h ../LaunchReal.h ../StarlinkCollection.h ../SatelliteManager.h ../SatelliteIterator.h ../StarlinkBay.h ../RocketshipEngineer.h ../CreateCrewDragon.h ../CreateDragon.h ../CreateStarlink.h ../Backup.h ../OrderCargo.h ../Director.h ../EnginePresentTest.h ../CargoTest.h ../EngineFireTest.h ../CargoHandler.h ../HumanHandler.h ../EquipmentHandler.h