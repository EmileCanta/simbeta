#include "PrimaryGenerator.hh"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

MyPrimaryGenerator::MyPrimaryGenerator()
{   
    G4int n_particle = 1;
    fParticleGun  = new G4ParticleGun(n_particle);
    
    //Particle source
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable->FindParticle("e-");
    fParticleGun->SetParticleDefinition(particle);
    
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., 0.));    
    /*fParticleGun->SetParticleEnergy(0.*keV);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 0.));*/

    
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4double cosTheta = 2*G4UniformRand() - 1.;
    G4double sinTheta = std::sqrt(1. - cosTheta*cosTheta);
    G4double phi = CLHEP::twopi*G4UniformRand();
    G4double vx = sinTheta*std::cos(phi),
    vy = sinTheta*std::sin(phi),
    vz = cosTheta;

    pair<vector<float>, vector<float>> pair = LoadDecayFile();
    G4double fenergy = GenerateBetaMinus(pair.first, pair.second);

    //Radioactive source
    /*if(fParticleGun->GetParticleDefinition() == G4Geantino::Geantino()) 
    {
        G4int Z = 33, A = 85;
        G4double ionCharge   = 0.*eplus;
        G4double excitEnergy = 0.*keV;

        G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
        fParticleGun->SetParticleDefinition(ion);
        fParticleGun->SetParticleCharge(ionCharge);
    }*/

    fParticleGun->SetParticleEnergy(fenergy);

    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(vx,vy,vz));

    fParticleGun->GeneratePrimaryVertex(anEvent);
}

/*pair<vector<float>, vector<float>> MyPrimaryGenerator::LoadDecayFile()
{
    string a1, a2;
    vector<float> v1;
    vector<float> v2;

    ifstream coeff;
    coeff.open("decays/85As.decay");

    if (coeff.is_open())
    {

        while (!coeff.eof())
        {
            getline(coeff, a1, ' ');
            v1.push_back(stof(a1));
            getline(coeff, a2, '\n');
            v2.push_back(stof(a1));
        }

        coeff.close();
        
    }

    pair <vector<float>, vector<float>> pair (v1, v2);

    return pair;

}

G4double MyPrimaryGenerator::GenerateBetaMinus(vector<float> v1, vector<float> v2)
{
    G4int Z = 33, A = 85;
    G4double excitEnergy = 0.*keV;

    G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);

    G4double value = round(611*G4UniformRand());

    G4BetaMinusDecay *fBetaMinusDecay = new G4BetaMinusDecay(ion, v2[value], v1[value]*MeV, 0., G4Ions::G4FloatLevelBase::no_Float, allowed);

    G4DecayProducts* aaa = fBetaMinusDecay->DecayIt(0.);

    const G4DynamicParticle* beta = (*aaa)[0];

    const G4double energy = beta->GetKineticEnergy();

    return energy;
}*/