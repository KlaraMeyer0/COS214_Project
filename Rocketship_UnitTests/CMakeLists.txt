cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp factorymethod_unitTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)


#../CrewDragonFactory.cpp ../CrewDragonFactory.h ../DragonFactory.cpp ../DragonFactory.h ../DragonSpacecraft.h ../DragonSpacecraft.cpp ../CrewDragonSpacecraft.h ../CrewDragonSpacecraft.cpp

#../Cargo.h ../CommunicationRelay.h ../PointOfCommunication.h ../StarlinkSatellite.h ../Station.h ../BaseStation.h ../SpaceStation.h ../FalconRocket.h ../Engine.h ../MerlinEngine.h ../FalconCore.h ../StageEngine.h ../VacuumEngine.h ../Stage1Engine.h ../Stage2Engine.h ../HeavyEngine.h ../_9Engine.h ../FalconHeavy.h ../Falcon9.h ../Rocketship.h ../LaunchFile.h ../LaunchCaretaker.h ../TestLaunch.h ../LaunchInterface.h ../StopTest.h ../Spacecraft.h ../SpacecraftFactory.h ../DragonSpacecraft.h ../CrewDragonSpacecraft.h ../CrewDragonFactory.h ../DragonFactory.h ../CargoFactory.h ../Equipment.h ../EquipmentFactory.h ../Human.h ../HumanFactory.h ../RocketFactory.h ../Falcon9Factory.h ../FalconHeavyFactory.h ../DragonRocketship.h ../CrewDragonRocketship.h ../DragonBay.h ../CrewDragonBay.h ../LaunchReal.h ../StarlinkCollection.h ../SatelliteManager.h ../SatelliteIterator.h ../StarlinkBay.h ../RocketshipEngineer.h ../CreateCrewDragon.h ../CreateDragon.h ../CreateStarlink.h ../Backup.h ../OrderCargo.h ../Director.h ../EnginePresentTest.h ../CargoTest.h ../EngineFireTest.h ../CargoHandler.h ../HumanHandler.h ../EquipmentHandler.h