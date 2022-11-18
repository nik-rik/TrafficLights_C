/* trafficLights.h - header file for the class trafficLights */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

/*********************** Class TrafficLight ***************************/

enum Colour {RED, YELLOW, GREEN};

class TrafficLight {

	public:
	
		TrafficLight(Time,char*);
		TrafficLight(Time,char*,TrafficLight&); 
		void carWantsToCross();
  static void setTheTime(Time&);
  void lightChange(Colour, TrafficLight&);
  void requestLightChange(Colour, TrafficLight&);
  const Colour get_colour() const;
  void basicSetup(Time&, char*, TrafficLight*);		
    	
     	friend std::ostream& operator << (std::ostream&, TrafficLight*);
     	friend std::ostream& operator << (std::ostream&, enum Colour);
	private:

  char* name;
  Time delay;
  TrafficLight* correspondingLight;
  static Time globalClock;
  Colour lightColour;

                /* add members and operations to complete the class yourself */
	
};

#endif


