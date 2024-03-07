#ifndef EventAction_h
#define EventAction_h

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

#include "RunAction.hh"

class MyEventAction : public G4UserEventAction
{
public:
    MyEventAction(MyRunAction* runAction);
    ~MyEventAction();
    
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
    void AddEdep(G4double edep) {fEdep += edep; }
    void AddEdepLow(G4double edeplow) {fEdepLow += edeplow; }
    
    void IncMulti(G4int count) {fMulti += count; }
    
    G4int GetMulti() {return fMulti;}
    
public:
    G4int fMulti;

private:
    G4double fEdep, fEdepLow;
    
    MyRunAction *fRunAction;
};

#endif
