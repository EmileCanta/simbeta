void PlotEnergy()
{	
    
    TH1D *hist[11];
    
    TTree *tree[11];
    
    TFile *dataFile = new TFile("../output.root", "READ");
    
    double var;
    
    for(int i = 0; i < 10; i++)
    {   
        var = 0;

        TString namehist = Form("hist%d",i);
        
        TString histnum = Form("%d",i+1);
        
        hist[i] = new TH1D(namehist, "Histogram", 1000, 0, 1);
        
        tree[i] = (TTree*)dataFile->Get("N"+histnum);
        
        tree[i]->SetBranchAddress("fEdep"+histnum, &var);
        
        int fEntries = tree[i]->GetEntries();
        
        for(int j = 0; j < fEntries; j++)
        {
            tree[i]->GetEntry(j);
            hist[i]->Fill(var);
        }
    }
        
    //extra histo
    
    var = 0;
    
    hist[10] = new TH1D("hist10", "Histogram", 1000, 0, 1);
    tree[10] = (TTree*)dataFile->Get("LowEvents");
    tree[10]->SetBranchAddress("fEdepLow", &var);
    
    for (int j = 0; j < tree[10]->GetEntries(); j++)
    {
        tree[10]->GetEntry(j);
        hist[10]->Fill(var);
    }
   
    hist[0]->Add(hist[1]);
    hist[0]->Add(hist[2]);
    hist[0]->Add(hist[3]);
    hist[0]->Add(hist[4]);
    hist[0]->Add(hist[5]);
    hist[0]->Add(hist[6]);
    hist[0]->Add(hist[7]);
    hist[0]->Add(hist[8]);
    hist[0]->Add(hist[9]);
    hist[0]->Add(hist[10]);
 
    TCanvas *c1 = new TCanvas();
    c1->SetGrid();
    c1->SetTickx();
    c1->SetTicky();
    
    hist[0]->GetXaxis()->SetTitle("Energy(MeV)");
    hist[0]->GetYaxis()->SetTitle("Entries/keV");
    
    hist[0]->Draw();
    

}
