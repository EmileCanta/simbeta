#include "RunAction.hh"
#include "EventAction.hh"

MyRunAction::MyRunAction()
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    man->CreateNtuple("Timing", "Timing");
    man->CreateNtupleDColumn("fTime");
    man->FinishNtuple(0);
    
    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("fEdep");
    man->FinishNtuple(1);
    
    man->CreateNtuple("E_ini", "E_ini");
    man->CreateNtupleDColumn("fE_ini");
    man->FinishNtuple(2);
    
    man->CreateNtuple("Multiplicity", "Multiplicity");
    man->CreateNtupleDColumn("fMulti");
    man->FinishNtuple(3);
    
    man->CreateNtuple("LowEvents", "LowEvents");
    man->CreateNtupleDColumn("fEdepLow");
    man->FinishNtuple(4);
    
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    G4int runID = run->GetRunID();
    
    std::stringstream strRunID;
    strRunID << runID;
    
    man->OpenFile("/Users/cantacuzene/simbeta/analysis/output"+strRunID.str()+".root");
    
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile();
}
