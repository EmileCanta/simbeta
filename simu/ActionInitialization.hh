#ifndef ActionInitialization_h
#define ActionInitialization_h

#include "G4VUserActionInitialization.hh"

#include "PrimaryGenerator.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
	MyActionInitialization();
	~MyActionInitialization();
	
	virtual void Build() const;
	virtual void BuildForMaster() const;
};

#endif
