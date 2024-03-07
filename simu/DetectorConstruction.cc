#include "DetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{	
	G4NistManager *nist = G4NistManager::Instance();
	WLSMaterials *WLSnist = WLSMaterials::GetInstance();
	
//MATERIALS AND ELEMENTS

	//Vaccum (world)	
    G4double    atomicMassAir = 29.*g/mole,
                pressureVac = 9e-9*bar,
                temperature = 290.*kelvin,
                molar_constant = CLHEP::Avogadro*CLHEP::k_Boltzmann,
                densityVac = (atomicMassAir*pressureVac)/(temperature*molar_constant);
                
    worldMat = new G4Material("realVac", densityVac, 1, kStateGas, temperature, pressureVac);
    
    air = nist->FindOrBuildMaterial("G4_AIR");
    
    worldMat->AddMaterial(air, 100.*perCent);
    
    //Plastic beta detector
    plasticMat = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    
    plastic = new G4Material("plastic", 1.023*g/cm3, 1);
    plastic->AddMaterial(plasticMat, 100.*perCent);
    
    //Aluminium foil
    aluMat = nist->FindOrBuildMaterial("G4_Al");
    
    //Black tape
    tapeMat = nist->FindOrBuildMaterial("G4_POLYVINYL_CHLORIDE");
    
    //Transparent plastic (PMMA)
    pmmaMat = WLSnist->GetMaterial("PMMA");
    
    //Mylar
    mylarMat = nist->FindOrBuildMaterial("G4_MYLAR");
    
//VOLUMES
	
	//World
    solidWorld = new G4Box("World", 15.*cm, 15.*cm, 15.*cm);

	logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
	
    //Plastic beta detector 
    G4ThreeVector zTrans(0., 0., 0.*mm);
    
    solidPlastic = new G4Tubs("solidPlastic", 22.4*mm, 25.4*mm, 49.*mm, 0., 360.);
    
    //plasticIn = new G4Tubs("plasticIn", 0., 22.4*mm, 49.*mm, 0., 360.);
    
    //solidPlastic = new G4SubtractionSolid("solidPlastic", plasticOut, plasticIn, 0, zTrans);
    
    logicPlastic = new G4LogicalVolume(solidPlastic, plastic, "logicPlastic");
    
    physPlastic = new G4PVPlacement(0, G4ThreeVector(0., 0., 36.5), logicPlastic, "physPlastic", logicWorld, false, 0, true);
    
    fScoringVolume = logicPlastic;
    
    //Aluminium
    G4ThreeVector zTransBis(0., 0., 0.*mm);
    
    solidAlu = new G4Tubs("solidAlu", 22.370*mm, 22.400*mm, 49*mm, 0., 360.);
    
    //aluIn = new G4Tubs("aluIn", 0.*mm, 22.370*mm, 49*mm, 0., 360.);
    
    //solidAlu = new G4SubtractionSolid("solidAlu", aluOut, aluIn, 0, zTransBis);
    
    logicAlu = new G4LogicalVolume(solidAlu, mylarMat, "logicAlu");
    
    physAlu = new G4PVPlacement(0, G4ThreeVector(0., 0., 36.5), logicAlu, "physAlu", logicWorld, false, 0, true);
    
    //Tape
    solidTape = new G4Tubs("solidTape", 22.120*mm, 22.370*mm, 49.*mm, 0., 360.);
    
    logicTape = new G4LogicalVolume(solidTape, tapeMat, "logicTape");
    
    physTape = new G4PVPlacement(0, G4ThreeVector(0., 0., 36.5), logicTape, "physTape", logicWorld, false, 0, true);
    
    //PMMA1
    solidPmma1 = new G4Tubs("solidPmma1", 0., 2.*mm, 10.2*mm, 0., 360.);
    
    logicPmma1 = new G4LogicalVolume(solidPmma1, aluMat, "logicPmma1");
    
    G4RotationMatrix *RotMat = new G4RotationMatrix();
    
    RotMat->rotateY(90*deg);
    
    physPmma1 = new G4PVPlacement(RotMat, G4ThreeVector(0., 12.1*mm, 0.), logicPmma1, "physPmma1", logicWorld, false, 0, true);
    
    //PMMA2
    solidPmma2 = new G4Tubs("solidPmma2", 0., 2.*mm, 10.2*mm, 0., 360.);
    
    logicPmma2 = new G4LogicalVolume(solidPmma2, aluMat, "logicPmma2");
    
    physPmma2 = new G4PVPlacement(RotMat, G4ThreeVector(0., -12.1*mm, 0.), logicPmma2, "physPmma2", logicWorld, false, 0, true);
    
    //PMMA3
    solidPreSub = new G4Box("solidPreSub", 2.*mm, 14.1*mm, 44.1*mm);
    
    solidSub = new G4Box("solidSub", 2.1*mm, 8.*mm, 17*mm);
    
    G4ThreeVector zTrans1(0., 0., -20.*mm);
    G4ThreeVector zTrans2(0., 0., 20.*mm);
    
    solidPmma3HalfCut = new G4SubtractionSolid("solidPmma3HalfCut", solidPreSub, solidSub, 0, zTrans1);
    
    solidPmma3 = new G4SubtractionSolid("solidPmma3", solidPmma3HalfCut, solidSub, 0, zTrans2);
    
    logicPmma3 = new G4LogicalVolume(solidPmma3, aluMat, "logicPmma3");
    
    physPmma3 = new G4PVPlacement(0, G4ThreeVector(12.2*mm, 0., 42.1*mm), logicPmma3, "physPmma3", logicWorld, false, 0, true);
    
    //PMMA4
    physPmma4 = new G4PVPlacement(0, G4ThreeVector(-12.2*mm, 0., 42.1*mm), logicPmma3, "physPmma4", logicWorld, false, 0, true);
    
    //Source Point
	solidSP = new G4Sphere("SP", 0., 0.1*mm, 0., 360., 0., 180.);
	
	logicSP = new G4LogicalVolume(solidSP, worldMat, "logicSP");
	
	physSP = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicSP, "physSP", logicWorld, false, 0, true);
	
	fSPVolume = logicSP;
	
	return physWorld;
}
