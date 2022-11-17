traffic: main.o time.o trafficLight.o
	g++ main.o time.o trafficLight.o -o traffic

main.o: main.cpp time.h trafficLight.h
	g++ -c -g -Wall main.cpp

time.o: time.cpp time.h
	g++ -c -g -Wall time.cpp

trafficLight.o: trafficLight.cpp trafficLight.h time.h
	g++ -c -g -Wall trafficLight.cpp

clean:
	rm -f *.o traffic


