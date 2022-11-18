#include<iostream>
#include<cstring>
#include "trafficLight.h"
#include "time.h"

using namespace std;

Time TrafficLight::globalClock(0,0,0);

TrafficLight::TrafficLight(Time _delay, char* _name){
  basicSetup(_delay, _name, NULL);
}

TrafficLight::TrafficLight(Time _delay, char* _name, TrafficLight& _correspondingLight){
  basicSetup(_delay, _name, &_correspondingLight);

  correspondingLight->correspondingLight = this;
}

void TrafficLight::basicSetup(Time& _delay, char* _name, TrafficLight* _correspondingLight){
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);

  lightColour = RED;

  delay = _delay;

  correspondingLight = _correspondingLight;
}

void TrafficLight::setTheTime(Time& _globalClock){
  globalClock = _globalClock;
}

void TrafficLight::carWantsToCross(){
  cout << "\n*** at " << globalClock << " a car wants to cross light " << name << ", with colour: " << lightColour << endl;
  
  if (lightColour == RED){
    if (correspondingLight->lightColour == GREEN)
      correspondingLight->requestLightChange(RED);
    else if (correspondingLight->lightColour == RED){
      lightChange(YELLOW);
      lightChange(GREEN);
    }
  }     
}

void TrafficLight::lightChange(Colour targetColour){
  globalClock.add(delay);
  lightColour = targetColour;
  cout << "    at " << globalClock << " " << name << " changes colour to " << lightColour << endl;
}

void TrafficLight::requestLightChange(Colour targetColour){
  if (targetColour == RED){
    if (lightColour == GREEN){
      lightChange(YELLOW);
      correspondingLight->requestLightChange(GREEN);
    }
    if (lightColour == YELLOW){
      lightChange(RED);
      correspondingLight->requestLightChange(GREEN);
    }
  }
  else if (targetColour == GREEN){
    if (lightColour == RED){
      lightChange(YELLOW);
      correspondingLight->requestLightChange(RED);
    }
    if (lightColour == YELLOW){
      lightChange(GREEN);
    }
  }
}

std::ostream& operator << (std::ostream& out, TrafficLight* trafficLight){
	out << "Name: " << trafficLight->name << "\nColour: \nDelay: " << trafficLight->delay << "\nGlobal Clock: " << trafficLight->globalClock << "\nColour: " << trafficLight->lightColour << "\ncorrespondingLight: " << trafficLight->correspondingLight << endl;

  return out;
}


std::ostream& operator << (std::ostream& out, const Colour lightColour){
  if (lightColour == RED)
    out << "red";
  if (lightColour == YELLOW)
    out << "yellow";
  if (lightColour == GREEN)
    out << "green";

  return out;
}

