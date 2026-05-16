# Mediator Flyweight ATC, Keyed Registry

## Lab Assignment

 The project is due in one week: by the midnight on the day of the next lab. Make sure to include your name in comments of the source files. 
1.   **ATC.** Review the code for the Mediator-based [Air Traffic Controller (ATC) example](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Mediator/atc.cpp) and Flyweight [example](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Flyweight). 
Modify the code for the ATC example to use flyweight design pattern as follows. Every flight has an intrinsic flyweight portion in the form of the airline logo. The logo is a text of the airline name in CAPITAL LETTERS. Note that the logo may be shared by several flights of the same airline. Modify the ATC example such that after getting clearance and acknowledging takeoff/landing, there is an extra printout (with the logo) of the aircraft actually doing the takeoff/landing.


 Here is an example dialogue (user input is in **bold**):   JetBlue487 requesting landing
  Iberia53 requesting takeoff
  Delta703 requesting landing
  AirFrance794 requesting takeoff
  Tower: **Delta703 clear to land**
  Delta703 roger that, landing
  ...DELTA703 lands...
  LuftHansa822 requesting takeoff
  Tower: **Iberia53, clear to takeoff**
  Iberia53 roger that, taking off
  ...IBERIA53 takes off...
  Tower: 
2.   **Registry**. Review the registry-based implementation for [Observer](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Observer) and [Prototype](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Prototype). Note that in the classic Registry Design Pattern, the entry is looked up by key rather than by pointer. In the Prototype implementation, the lookup is by key. In the Observer implementation, the lookup is by pointer. Using the Prototype implementation as an example, modify the Observer implementation of the registry so that the observers may subscribe to and unsubscribe from messages in subjects by the subject's names rather than pointers. Modify the demonstration code in main() to showcase this behavior. 

**Milestone:** Implement the printout for DELTA only.
