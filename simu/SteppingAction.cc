#include "SteppingAction.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{
    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    
    const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    
    G4LogicalVolume *fSPVolume = detectorConstruction->GetSPVolume();
    
    G4Track *track = step->GetTrack();
    G4ParticleDefinition *particle = track->GetDefinition();
    G4String name = particle->GetParticleName();
 
    if(volume == fSPVolume)
    {
        if(name == "e-")
        {   
            if(step->IsFirstStepInVolume() == 1)
            {   
                G4AnalysisManager *man = G4AnalysisManager::Instance();
                
                fEventAction->IncMulti(count);
                
                man->FillNtupleDColumn(2, 0, step->GetPreStepPoint()->GetKineticEnergy());
    	        man->AddNtupleRow(2);
    	        
                time1 = track->GetGlobalTime();   
            }
        }
    }
    
    if(volume != fScoringVolume)
        return;
    
    if(name == "e-")
    {   
        if(step->IsFirstStepInVolume() == 1)
        {   
            G4double time2 = track->GetGlobalTime() - time1;
           
            G4AnalysisManager *man = G4AnalysisManager::Instance();
            
            man->FillNtupleDColumn(0, 0, time2);
            man->AddNtupleRow(0);
        }

        G4double edep = step->GetTotalEnergyDeposit();
        fEventAction->AddEdep(edep);

    }
    
    if(name == "gamma")
    {   
        G4double edeplow = step->GetTotalEnergyDeposit();
        fEventAction->AddEdepLow(edeplow);
    }
}
