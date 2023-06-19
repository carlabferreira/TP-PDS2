teste: obj/testes.o obj/Buscador.o obj/Recupera.o
	g++ -o $@ $^ -std=c++17 -I.

obj/testes.o: testes.cpp Buscador.hpp
	g++ -c -o $@ $< -std=c++17 -I.

obj/Buscador.o: Buscador.cpp Buscador.hpp
	g++ -c -o $@ $< -std=c++17 -I.

obj/Recupera.o: Recupera.cpp Buscador.cpp Buscador.hpp Recupera.hpp 
	g++ -c -o $@ $< -std=c++17 -I.