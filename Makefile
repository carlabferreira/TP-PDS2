teste: obj/testes.o obj/Buscador.o obj/Recupera.o
	g++ -o $@ $^ -I.

obj/testes.o: testes.cpp Buscador.hpp
	g++ -c -o $@ $< -I.

obj/Buscador.o: Buscador.cpp Buscador.hpp
	g++ -c -o $@ $< -I.

obj/Recupera.o: Recupera.cpp Recupera.hpp Buscador.hpp Buscador.cpp 
	g++ -c -o $@ $< -I.