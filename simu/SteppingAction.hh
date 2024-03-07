#ifndef SteppingAction_h
#define SteppingAction_h

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"

class MySteppingAction : public G4UserSteppingAction
{
public:
    MySteppingAction(MyEventAction* eventAction);
    ~MySteppingAction();
    
    virtual void UserSteppingAction(const G4Step*);
    
private:
    MyEventAction *fEventAction;
    
    G4int count = 1;
    G4double time1;
};

#endif
