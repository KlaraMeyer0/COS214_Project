cmake_minimum_required(VERSION 2.6)
project(COS214_Project)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp
        ../FalconRocket.h
        ../FalconRocket.cpp
        ../_9Engine.h
        ../_9Engine.cpp
        ../Stage1Engine.cpp
        ../Stage1Engine.h
        ../Stage2Engine.h
        ../Stage2Engine.cpp
        ../StageEngine.h
        ../StageEngine.cpp
        ../VacuumEngine.h
        ../VacuumEngine.cpp
        ../MerlinEngine.h
        ../MerlinEngine.cpp
        ../HumanHandler.h
        ../HumanHandler.cpp
        ../Engine.h
        ../Engine.cpp
        ../Cargo.h
        ../Cargo.cpp
        ../Falcon9.h
        ../Falcon9.cpp
        ../FalconCore.h
        ../FalconCore.cpp
        ../EquipmentHandler.h
        ../EquipmentHandler.cpp
        ../CargoHandler.h
        ../CargoHandler.cpp
        ../StarlinkCollection.cpp
        ../StarlinkCollection.h
        ../PointOfCommunication.cpp
        ../PointOfCommunication.h
        ../StarlinkSatellite.cpp
        ../StarlinkSatellite.h
        ../CommunicationRelay.cpp
        ../CommunicationRelay.h
        ../Station.h
        ../Station.cpp
        ../SpaceStation.h
        ../SpaceStation.cpp
        ../BaseStation.h
        ../BaseStation.cpp
        ../Rocketship.cpp
        ../Rocketship.h
        ../SatelliteManager.h
        ../SatelliteManager.cpp
        ../SatelliteIterator.cpp
        ../SatelliteIterator.h
        mediator_unitTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

