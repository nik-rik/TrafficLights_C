/* time.h - header file for the class Time */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Class Time ***************************/

class Time {

	public:

		Time();

		Time(int hours, int mins, int secs);
		
		Time(std::istream& in);
	
		void add(Time& anotherTime);
    		/* adds seconds to seconds, minutes to minutes and
    		hours to hours, taking into account that 
    		a day has 24 hours, an hour has 60 minutes
    		and a minute has 60 seconds */
    	
    	friend std::ostream& operator << (std::ostream&, Time&);


	private:

		int theHour;
		int theMins;
		int theSecs;	
		
		void init(int hours, int minutes, int seconds);
};

#endif

