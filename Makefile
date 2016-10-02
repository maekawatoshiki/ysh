CXXFLAGS = -O3 -std=c++11
CXX = clang++

ysh: main.o ysh.o
	$(CXX) -o ysh main.o ysh.o

main.o: main.cpp common.hpp

ysh.o: ysh.cpp ysh.hpp common.hpp

clean:
	$(RM) *.o ysh
