#ifndef PhysicsList_h
#define PhysicsList_h

#include "G4VModularPhysicsList.hh"

#include "G4EmPenelopePhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

class MyPhysicsList : public G4VModularPhysicsList
{

public:
	MyPhysicsList();
	~MyPhysicsList();
	
};

#endif
