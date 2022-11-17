#include<iostream>
#include<cstring>
#include "trafficLight.h"
#include "time.h"


using namespace std;

Time TrafficLight::globalClock(0,0,0);

TrafficLight::TrafficLight(Time _delay, char* _name){
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);

  delay = _delay;

  correspondingLight = NULL;
}

TrafficLight::TrafficLight(Time _delay, char* _name, TrafficLight& _correspondingLight){
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);

  delay = _delay;

  correspondingLight = &_correspondingLight;

  correspondingLight->correspondingLight = this;
  
}

void TrafficLight::setTheTime(Time& _globalClock){
  globalClock = _globalClock;
}

std::ostream& operator << (std::ostream& out, TrafficLight* trafficLight){
  out << "Name: " << trafficLight->name << "\nColour: \nDelay: " << trafficLight->delay << "\ncorrespondingLight: " << trafficLight->correspondingLight << endl;

  return out;
}
