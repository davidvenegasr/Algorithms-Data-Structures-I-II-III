all:
	g++ -o tsp tsp.cpp hamc.cpp hagm.cpp mheur.cpp hvmc.cpp -O2 -std=c++14
	
debug:
	g++ -o tsp tsp.cpp hamc.cpp hagm.cpp mheur.cpp hvmc.cpp -g -std=c++14

test:
	g++ -o test-tsp tsp-tester.cpp hvmc.cpp -O2 -std=c++14

clean:
	rm -f $(OBJS)
	rm -f $(EXE)
	rm -f *.o
	rm -f tsp test-tsp                                       
