void PlotTime()
{	
	double time;	
	
	TCanvas *c1 = new TCanvas();
	
	TH1F *hist = new TH1F("hist", "hist", 2000, -10000, 4e5);
	
	TFile *dataFile;
	TTree *dataTree;
	
	dataFile = TFile::Open("../runcf4/output.root");
    
    dataTree = (TTree*)dataFile->Get("Hits");
    
    dataTree->SetBranchAddress("fTime", &time);
    
    int fEntries = dataTree->GetEntries();
    
    for(int i = 0; i < fEntries; i++)
    {
    	dataTree->GetEntry(i);
    	hist->Fill(time);
    }
    
    hist->Draw();
    //gStyle->SetOptStat(0);
    
}
