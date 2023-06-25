main: obj/main.o obj/Buscador.o obj/Recupera.o
	g++ -o $@ $^ -std=c++17 -I.

obj/main.o: main.cpp Buscador.hpp
	g++ -c -o $@ $< -std=c++17 -I.

obj/Buscador.o: Buscador.cpp Buscador.hpp
	g++ -c -o $@ $< -std=c++17 -I.

obj/Recupera.o: Recupera.cpp Recupera.hpp Buscador.cpp Buscador.hpp 
	g++ -c -o $@ $< -std=c++17 -I.