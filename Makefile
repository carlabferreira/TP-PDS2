teste: obj/testes.o obj/Buscador.o
	g++ -o $@ $^ -I.

obj/testes.o: testes.cpp Buscador.hpp
	g++ -c -o $@ $< -I.

obj/Buscador.o: Buscador.cpp Buscador.hpp
	g++ -c -o $@ $< -I.