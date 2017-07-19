timermake: Run.cpp Timer.cpp
	g++ Run.cpp Timer.cpp Doer.cpp -o Run -pthread -std=c++11
