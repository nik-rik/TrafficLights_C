#include <iostream>
#include "time.h"

/*Default constructor initialises time to 0:0:0 */
Time::Time(){
  theHour = 0;
  theMins = 0;
  theSecs = 0;
}  

/* Constructor that creates a Time object with user imputs */
Time::Time(int hours, int mins, int secs){
  theHour = hours;
  theMins = mins;
  theSecs = secs;
}

/* Overloads << operator to output time in h:m:s format */
std::ostream& operator << (std::ostream& out, Time& time){
  out << time.theHour << ":" << time.theMins << ":" << time.theSecs;

  return out;
}

/* Adds seconds to seconds, minutes to minutes and hours to hours, taking into account that a day has 24 hours, an hour has
   60 minutes and a minute has 60 seconds */
void Time::add(Time& anotherTime){
  int newHour;
  int newMins;
  int newSecs;
    
  newSecs = (theSecs + anotherTime.theSecs) % 60;
  newMins = (theMins + anotherTime.theMins + ((theSecs + anotherTime.theSecs)/60)) % 60;
  newHour = (theHour + anotherTime.theHour + (theMins + anotherTime.theMins + (theSecs + anotherTime.theSecs) / 60) / 60) % 24;

  theSecs = newSecs;
  theMins = newMins;
  theHour = newHour;
}
