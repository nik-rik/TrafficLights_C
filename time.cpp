#include <iostream>
#include "time.h"


Time::Time(){
  theHour = 0;
  theMins = 0;
  theSecs = 0;
}  


Time::Time(int hours, int mins, int secs){
  theHour = hours;
  theMins = mins;
  theSecs = secs;
}


std::ostream& operator << (std::ostream& out, Time& time){
  out << time.theHour << ":" << time.theMins << ":" << time.theSecs;

  return out;
}

void Time::add(Time& anotherTime){
  int newHour;
  int newMins;
  int newSecs;
    
  newSecs = (theSecs + anotherTime.theSecs) % 60;
  newMins = (theMins + anotherTime.theMins + ((theSecs + anotherTime.theSecs)/60)) & 60;
  newHour = (theHour + anotherTime.theHour + (theMins + anotherTime.theMins + (theSecs + anotherTime.theSecs) / 60) / 60) % 24;

  theSecs = newSecs;
  theMins = newMins;
  theHour = newHour;
}
