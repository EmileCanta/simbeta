void multi_plot()
{	
    
    TH1D *hist[20];
    
    TFile *file[20];
    
    TTree *tree[20];
    
    double var;
    
    THStack *hstack = new THStack("stack", "Energy ;Energy (MeV); Entries");
    
    TLegend *leg = new TLegend(0.7, 0.6, 0.9, 0.9);
    
    for(int i = 0; i < 20; i++)
    {   
        var = 0;
        
        float pressurevalue = 0.5 + 0.5*i;
        TString pressure = std::to_string(pressurevalue);
        
        TString namehist = Form("hist%d",i);
        hist[i] = new TH1D(namehist, "Histogram", 1000, 0, 1);
        
        hist[i]->SetMarkerStyle(i+20);
        hist[i]->SetMarkerColor(i+1);
        
        hstack->Add(hist[i]);
        
        leg->AddEntry(hist[i], "P = "+pressure+" bar", "p");
        
        TString nameout = Form("output%d", i);
        
        file[i] = new TFile(nameout+".root", "READ");
        
        tree[i] = (TTree*)file[i]->Get("Scoring");
        
        tree[i]->SetBranchAddress("fEdep", &var);
        
        int fEntries = tree[i]->GetEntries();
        
        for(int j = 0; j < fEntries; j++)
        {
            tree[i]->GetEntry(j);
            hist[i]->Fill(var);
        }
    }     
 
    TCanvas *c1 = new TCanvas();
    c1->SetGrid();
    c1->SetTickx();
    c1->SetTicky();
    
    hstack->Draw("Pnostack");
    leg->Draw();
    

}
