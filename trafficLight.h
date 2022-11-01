/* trafficLights.h - header file for the class trafficLights */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

/*********************** Class TrafficLight ***************************/

class TrafficLight {

	public:
	
		TrafficLight(Time,char*);
		TrafficLight(Time,char*,TrafficLight&); 
		 
		void carWantsToCross();
		static void setTheTime(Time&);
    	
     	friend std::ostream& operator << (std::ostream&, TrafficLight*);

	private:

                /* add members and operations to complete the class yourself */
	
};

#endif


