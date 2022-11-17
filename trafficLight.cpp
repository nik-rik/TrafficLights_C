#include<iostream>
#include<cstring>
#include "trafficLight.h"
#include "time.h"


using namespace std;

Time TrafficLight::globalClock(0,0,0);

TrafficLight::TrafficLight(Time _delay, char* _name){
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);

  lightColour = RED;

  delay = _delay;

  correspondingLight = NULL;
}

TrafficLight::TrafficLight(Time _delay, char* _name, TrafficLight& _correspondingLight){
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);

  lightColour = RED;

  delay = _delay;

  correspondingLight = &_correspondingLight;

  correspondingLight->correspondingLight = this;
  
}

void TrafficLight::setTheTime(Time& _globalClock){
  globalClock = _globalClock;
}

void TrafficLight::carWantsToCross(){
  cout << "\n***at " << globalClock << " a car wants to cross light " << name << ", with colour: " << lightColour << endl;
  
  if (lightColour == RED){
    if (correspondingLight->lightColour == GREEN)
      requestLightChange(RED, *correspondingLight);
    else if (correspondingLight->lightColour == RED){
      lightChange(YELLOW, *this);
      lightChange(GREEN, *this);
    }
  }     
}

void TrafficLight::lightChange(Colour targetColour, TrafficLight& trafficLight){
  globalClock.add(trafficLight.delay);
  trafficLight.lightColour = targetColour;
  cout << "   at " << globalClock << " " << trafficLight.name << " changes colour to " << trafficLight.lightColour << endl;
}

void TrafficLight::requestLightChange(Colour targetColour, TrafficLight& trafficLight){
  if (targetColour == RED){
    if (trafficLight.lightColour == GREEN){
      lightChange(YELLOW, trafficLight);
      requestLightChange(GREEN, *(trafficLight.correspondingLight));
    }
    if (trafficLight.lightColour == YELLOW){
      lightChange(RED, trafficLight);
      requestLightChange(GREEN, *(trafficLight.correspondingLight));
    }
  }
  if (targetColour == GREEN){
    if (trafficLight.lightColour == RED){
      lightChange(YELLOW, trafficLight);
      lightChange(RED, *(trafficLight.correspondingLight));
    }
    if (trafficLight.lightColour == YELLOW){
      lightChange(GREEN, trafficLight);
    }
  }
}

std::ostream& operator << (std::ostream& out, TrafficLight* trafficLight){
	out << "Name: " << trafficLight->name << "\nColour: \nDelay: " << trafficLight->delay << "\nGlobal Clock: " << trafficLight->globalClock << "\nColour: " << trafficLight->lightColour << "\ncorrespondingLight: " << trafficLight->correspondingLight << endl;

  return out;
}


std::ostream& operator << (std::ostream& out, Colour lightColour){
  if (lightColour == RED)
    out << "red";
  if (lightColour == YELLOW)
    out << "yellow";
  if (lightColour == GREEN)
    out << "green";

  return out;
}
