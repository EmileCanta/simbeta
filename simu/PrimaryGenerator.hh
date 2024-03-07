#ifndef PrimaryGenerator_h
#define PrimaryGenerator_h

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

#include "G4Geantino.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "Randomize.hh"
#include "globals.hh"
#include "G4BetaMinusDecay.hh"
#include "G4DynamicParticle.hh"
#include "G4DecayProducts.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
	MyPrimaryGenerator();
	~MyPrimaryGenerator();
	
	virtual void GeneratePrimaries(G4Event*);
	G4double GenerateBetaMinus(std::vector<float>, std::vector<float>);
	std::pair<std::vector<float>, std::vector<float>> LoadDecayFile();
	
private:
	G4ParticleGun *fParticleGun;
};

#endif
