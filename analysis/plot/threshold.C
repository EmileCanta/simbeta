void threshold()
{	
	double energy;
	
	TCanvas *c1 = new TCanvas();
	
	TH1F *histtrh = new TH1F("histtrh", "Source energy distribution", 9000, 0, 9);
	TH1F *histnotrh = new TH1F("histnotrh", "Source energy distribution", 9000, 0, 9);
	
	TFile *dataFile;
	TTree *dataTree;
	
	dataFile = TFile::Open("../saved_runs/GEO4/vlep2.root");
    
    dataTree = (TTree*)dataFile->Get("Scoring");
    
    dataTree->SetBranchAddress("fEdep", &energy);
    
    int fEntries = dataTree->GetEntries();
    
    for(int i = 0; i < fEntries; i++)
    {
    	dataTree->GetEntry(i);
    	histnotrh->Fill(energy);
    	
    	if(energy >= 0.260)
    	{
    	    histtrh->Fill(energy);
    	}
    
    }
    
    histnotrh->Draw();
    histtrh->Draw("same");
    histnotrh->SetLineColor(kRed);
    
    gStyle->SetOptStat(0);
    
    c1->SetGrid();
    c1->SetTickx();
    c1->SetTicky();
    
    histtrh->GetXaxis()->SetTitle("Energy(MeV)");
    histtrh->GetYaxis()->SetTitle("Entries/keV");
    
    cout << "No threshold: " << histnotrh->GetEntries() << endl;
    cout << "With threshold: " << histtrh->GetEntries() << endl;
}
