#include<iostream>
#include<cstring>
#include "trafficLight.h"
#include "time.h"

using namespace std;

Time TrafficLight::globalClock(0,0,0); // Initialises the global clock to 0:0:0


/* Constructor for first traffic light in pair */
TrafficLight::TrafficLight(Time _delay, char* _name){
  basicSetup(_delay, _name, nullptr); // NULL pointer to corresponding light because it doesn't exist yet
}


/* Constructor for second traffic light in pair */
TrafficLight::TrafficLight(Time _delay, char* _name, TrafficLight& _correspondingLight){
  basicSetup(_delay, _name, &_correspondingLight);

  if (correspondingLight->correspondingLight == nullptr)
    correspondingLight->correspondingLight = this; // Changes other traffic light in pair's corresponding light
                                                   // pointer from NULL to the this pointer only if the corresponding light
                                                   // is not already paired
  else
    correspondingLight = nullptr;                  // If the other traffic light already has a pair, the current
                                                   // traffic light's corresponding light is set to NULL
}


/* Function to initialise name, lightColour, delay and correspondingLight variables in constructors */
void TrafficLight::basicSetup(const Time& _delay, const char* _name, TrafficLight* _correspondingLight){
  name = new char[strlen(_name) + 1]; // Creates a new character array on the heap
  strcpy(name, _name); // Copies _name into the name variable

  lightColour = RED;

  delay = _delay;

  correspondingLight = _correspondingLight;
}


/* TrafficLight Destructor */
TrafficLight::~TrafficLight(){
  if (correspondingLight != nullptr)
    correspondingLight->correspondingLight = nullptr;

  delete (name);
  
}


/* Function to set the Global Clock to a specific time */
void TrafficLight::setTheTime(Time& _globalClock){
  globalClock = _globalClock;
}


/* Function to signal that a car wants to cross */
void TrafficLight::carWantsToCross(){
  cout << "\n***  at " << globalClock << " a car wants to cross light " << name << ", with colour: " << lightColour << endl;

  /* Changes light to green if there is no corresponding Light linked  */
  if (correspondingLight == nullptr){
      lightChange(YELLOW);
      lightChange(GREEN);
  }
  
  /* Switch for what lights should do if a car wants to cross, depending on colour of traffic light */
  switch(lightColour){

  case RED:
    if (correspondingLight->lightColour == GREEN)     // If the other light is Green then we request it to turn red, and the
      correspondingLight->requestLightChange(RED);    // this light will automatically turn Green after, because the lights
                                                      // always work in tandem (i.e. when one is green the other should switch to red)

    else if (correspondingLight->lightColour == RED)  // However, we need to include this because the lights are both initialised
      requestLightChange(GREEN);                      // to be red at the outset so are not yet operating in tandem.
    
    break;
    
  /* According to the output, nothing should happen if the light is already green or yellow */
  case YELLOW:
    break;

  case GREEN:
    break;
  }
}


/* Function that requests a light to change colour */
void TrafficLight::requestLightChange(const Colour targetColour){

  /* Using recursion, we change the colour of the current light from Green to Yellow to Red
     and the corresponding light from Red to Yellow to Green (and vice versa) in the correct order */
  
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
    if (lightColour == YELLOW){ // Base case
      lightChange(GREEN);
    }
  }
}


/* Function that waits the delay, changes the colour of the light and outputs that the light has changed colour */
void TrafficLight::lightChange(const Colour targetColour){
  globalClock.add(delay);
  lightColour = targetColour;
  cout << "     at " << globalClock << " " << name << " changes colour to " << lightColour << endl;
}


/* Overrides the << operator for Colour so that it outputs colour values correctly */
std::ostream& operator << (std::ostream& out, const Colour lightColour){
  switch(lightColour){
  case RED:
    out << "red";
    break;

  case YELLOW:
    out << "yellow";
    break;

  case GREEN:
    out << "green";
    break;
  }

  return out;
}

