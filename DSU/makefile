all: compile link

compile: 
	g++ -c test_3.cpp -I"F:\Le Khai\SFML-2.6.0\include" -DSFML_STATIC

link:
	g++ test_3.o -o test_3 -L"F:\Le Khai\SFML-2.6.0\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	del *.exe *.o