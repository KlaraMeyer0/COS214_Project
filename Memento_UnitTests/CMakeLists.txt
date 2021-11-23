cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp ../Engine.cpp ../Engine.h ../VacuumEngine.cpp ../VacuumEngine.h ../MerlinEngine.cpp ../MerlinEngine.h ../Stage1Engine.cpp ../Stage1Engine.h ../Stage2Engine.cpp ../Stage2Engine.h ../FalconCore.cpp ../FalconCore.h ../DragonSpacecraft.cpp ../DragonSpacecraft.h ../HeavyEngine.cpp ../HeavyEngine.h ../FalconHeavy.cpp ../FalconHeavy.h ../StageEngine.cpp ../StageEngine.h ../FalconRocket.cpp ../FalconRocket.h ../EquipmentHandler.cpp ../EquipmentHandler.h ../Human.cpp ../Human.h ../HumanHandler.cpp ../HumanHandler.h ../Cargo.cpp ../Cargo.h ../CargoHandler.cpp ../CargoHandler.h ../Spacecraft.cpp ../CommunicationRelay.cpp ../CommunicationRelay.h ../PointOfCommunication.cpp ../PointOfCommunication.h ../Launch.h ../LaunchTest.h ../LaunchReal.cpp ../LaunchReal.h ../Station.cpp ../Station.h ../EnginePresentTest.cpp ../EnginePresentTest.h ../EngineFireTest.cpp ../EngineFireTest.h ../Rocketship.cpp ../Rocketship.h ../StopTest.cpp ../StopTest.h ../CargoTest.cpp ../CargoTest.h ../LaunchFile.cpp ../LaunchFile.h ../LaunchCaretaker.cpp ../LaunchCaretaker.h ../LaunchInterface.cpp ../LaunchInterface.h ../DragonRocketship.cpp ../DragonRocketship.h ../SpaceStation.cpp ../SpaceStation.h ../BaseStation.cpp ../BaseStation.h memento_unitTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)