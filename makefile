CXX=g++
TARGET=main
OBJS= Cargo.o CommunicationRelay.o PointOfCommunication.o StarlinkSatellite.o Station.o BaseStation.o SpaceStation.o FalconRocket.o StageEngine.o Rocketship.o LaunchFile.o LaunchCaretaker.o TestLaunch.o LaunchInterface.o Spacecraft.o SpacecraftFactory.o CrewDragonFactory.o DragonFactory.o CargoFactory.o EquipmentFactory.o HumanFactory.o RocketFactory.o Falcon9Factory.o FalconHeavyFactory.o DragonRocketship.o $(TARGET).o
all: $(OBJS)
	$(CXX) -g $(OBJS) -o $(TARGET)


%.o: %.cpp
	$(CXX) -c -g $< -o $@

run:
	./$(TARGET)


clean:
	rm -f $(TARGET) $(OBJS) 