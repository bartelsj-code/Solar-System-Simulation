simulation:
	g++ Body.cpp Simulation.cpp setupFunctions.cpp physics.cpp central.cpp -o sim -lsfml-graphics -lsfml-window -lsfml-system
	./sim

