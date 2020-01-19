CXX = g++
CXXFLAGS = -Wall -std=c+=11
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main:
	$(CXX) main.cpp -o main.exe $(LDLIBS)
