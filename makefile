prog: main.o element.o character.o player.o weapon.o
	g++ main.o element.o character.o player.o weapon.o -o prog.exe
	./prog
main.o: main.cpp
	g++ -c main.cpp
element.o: element.cpp
	g++ -c element.cpp
character.o: character.cpp
	g++ -c character.cpp
player.o: player.cpp
	g++ -c player.cpp
weapon.o: weapon.cpp
	g++ -c weapon.cpp

clean:
	rm *.o prog.exe