#ifndef DetectorConstruction_h
#define DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "WLSMaterials.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{

public :
	MyDetectorConstruction();
	~MyDetectorConstruction();
    
    G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }
    
    G4LogicalVolume *GetSPVolume() const { return fSPVolume; }
	
	virtual G4VPhysicalVolume *Construct();
    
private:
    G4LogicalVolume *logicPlastic;
	
    G4LogicalVolume *fScoringVolume;
    
    G4LogicalVolume *logicSP;
    
    G4LogicalVolume *fSPVolume;
    
    G4VSolid *solidWorld, *solidPmma3, *solidPreSub, *solidSub, *solidPmma3HalfCut, *solidPlastic, *solidAlu;
    G4LogicalVolume *logicWorld, *logicAlu, *logicTape, *logicPmma1, *logicPmma2, *logicPmma3;
    G4VPhysicalVolume *physWorld, *physPlastic, *physAlu, *physTape, *physSP, *physPmma1, *physPmma2, *physPmma3, *physPmma4;
    G4Tubs *solidTape, *solidPmma1, *solidPmma2, *plasticIn, *plasticOut, *aluOut, *aluIn;
    G4Sphere *solidSP;
   
    G4Material *worldMat, *air, *plasticMat, *aluMat, *tapeMat, *pmmaMat, *plastic, *mylarMat;
    
};

#endif
