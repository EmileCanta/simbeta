#include "PhysicsList.hh"

MyPhysicsList::MyPhysicsList()
{	
    RegisterPhysics(new G4EmPenelopePhysics());
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}

MyPhysicsList::~MyPhysicsList()
{}
