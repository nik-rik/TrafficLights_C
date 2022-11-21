/* trafficLights.h - header file for the class trafficLights */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

/*********************** Class TrafficLight ***************************/

enum Colour {RED, YELLOW, GREEN}; // Used to restict the colour of the traffic lights to RED, YELLOW and GREEN
std::ostream& operator<<(std::ostream&, Colour); // Overloads the << operator for Colour

class TrafficLight {

public:
	
  TrafficLight(Time,char*);
  TrafficLight(Time,char*,TrafficLight&);
  ~TrafficLight();
  void carWantsToCross();
  static void setTheTime(Time&); // Sets the time of the Global Clock	    	

private:

  char* name; // Name of the traffic light
  Time delay; // Delay of the traffic light
  TrafficLight* correspondingLight; // Pointer to the other traffic light in the pair
  static Time globalClock; // Global Clock
  Colour lightColour; // Colour of the traffic light

  
  void lightChange(const Colour); // Changes a colour of a traffic light
  void requestLightChange(const Colour); // Requests a traffic light to change colour
  void basicSetup(const Time&, const char*, TrafficLight*);	// Used in the traffic light constuctors for simplification
};

#endif


