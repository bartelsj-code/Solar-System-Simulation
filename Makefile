simulation:
	rm sim
	g++ central.cpp body.cpp -o sim -lsfml-graphics -lsfml-window -lsfml-system
	./sim
