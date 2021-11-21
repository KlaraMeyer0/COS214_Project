CXX=g++
TARGET=main
OBJS= Cargo.o CommunicationRelay.o PointOfCommunication.o StarlinkSatellite.o Station.o BaseStation.o SpaceStation.o FalconRocket.o Engine.o MerlinEngine.o FalconCore.o StageEngine.o VacuumEngine.o Stage1Engine.o Stage2Engine.o HeavyEngine.o _9Engine.o Rocketship.o LaunchFile.o LaunchCaretaker.o TestLaunch.o LaunchInterface.o StopTest.o Spacecraft.o SpacecraftFactory.o CrewDragonFactory.o DragonFactory.o CargoFactory.o Equipment.o EquipmentFactory.o Human.o HumanFactory.o RocketFactory.o Falcon9Factory.o FalconHeavyFactory.o DragonRocketship.o CrewDragonRocketship.o DragonBay.o CrewDragonBay.o LaunchReal.o LaunchCaretaker.o  $(TARGET).o
all: $(OBJS)
	$(CXX) -g $(OBJS) -o $(TARGET)


%.o: %.cpp
	$(CXX) -c -g $< -o $@

run:
	./$(TARGET)


clean:
	rm -f $(TARGET) $(OBJS) 