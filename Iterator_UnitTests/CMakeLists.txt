cmake_minimum_required(VERSION 2.6)
project(COS214_Project)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp
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
        ../PointOfCommunication.cpp
        ../PointOfCommunication.h
        ../Rocketship.cpp
        ../Rocketship.h
        ../SatelliteManager.h
        ../SatelliteManager.cpp
        ../SatelliteIterator.cpp
        ../SatelliteIterator.h
        ../Cargo.cpp
        ../Cargo.h
        ../Human.cpp
        ../Human.h
        ../Equipment.cpp
        ../Equipment.h
        ../CargoHandler.cpp
        ../CargoHandler.h
        ../HumanHandler.cpp
        ../HumanHandler.h
        ../EquipmentHandler.h
        ../EquipmentHandler.cpp
        ../FalconRocket.h
        ../FalconRocket.cpp
        ../StageEngine.h
        ../StageEngine.cpp
        iterator_unitTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

