CXX=g++
TARGET=main
OBJS= FalconRocket.o Engine.o MerlinEngine.o FalconCore.o StageEngine.o VacuumEngine.o Stage1Engine.o Stage2Engine.o HeavyEngine.o _9Engine.o FalconHeavy.o Falcon9.o $(TARGET).o
all: $(OBJS)
	$(CXX) -g $(OBJS) -o $(TARGET)


%.o: %.cpp
	$(CXX) -c -g $< -o $@

run:
	./$(TARGET)


clean:
	rm -f $(TARGET) $(OBJS) 