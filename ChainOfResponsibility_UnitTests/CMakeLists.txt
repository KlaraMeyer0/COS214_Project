cmake_minimum_required(VERSION 2.6)
project(COS214_Project)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp
        ../Cargo.h
        ../Cargo.cpp
        ../Equipment.h
        ../Equipment.cpp
        ../Human.h
        ../Human.cpp
        ../Station.cpp
        ../Station.h
        ../BaseStation.cpp
        ../BaseStation.h
        ../SpaceStation.cpp
        ../SpaceStation.cpp
        ../CargoHandler.cpp
        ../CargoHandler.h
        ../EquipmentHandler.cpp
        ../EquipmentHandler.h
        ../HumanHandler.cpp
        ../HumanHandler.h
        ../PointOfCommunication.cpp
        ../PointOfCommunication.h
        ../StarlinkSatellite.cpp
        ../StarlinkSatellite.h
        ../CommunicationRelay.cpp
        ../CommunicationRelay.h
        chainOfResponsibility_UnitTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

