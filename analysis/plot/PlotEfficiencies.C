#include <iostream>
#include <vector>
#include <fstream>

#include <algorithm>
#include <iterator>

using namespace std;

void PlotEfficiencies()
{	
	
	std::vector<double> xaxis;
	std::vector<double> Nvectot;
	std::vector<double> Nvec1;
	std::vector<double> Nvec2;
	std::vector<double> Nvec3;
	std::vector<double> Nvec4;
	
	xaxis.push_back(0.01);
	xaxis.push_back(0.05);
	
	for(double i = 0.1; i <= 10; i = i+0.1)
	{
		xaxis.push_back(i);
	}

	fstream infile1;
	fstream infile2;
	fstream infile3;
	fstream infile4;
	fstream infile5;
	
	infile1.open("/vol0/simtetra/analysis/run18/efficiency/NtotFile.dat", ios::in);
	infile2.open("/vol0/simtetra/analysis/run18/efficiency/Nr1File.dat", ios::in);
	infile3.open("/vol0/simtetra/analysis/run18/efficiency/Nr2File.dat", ios::in);
	infile4.open("/vol0/simtetra/analysis/run18/efficiency/Nr3File.dat", ios::in);
	infile5.open("/vol0/simtetra/analysis/run18/efficiency/Nr4File.dat", ios::in);
	
	double value1;
	double value2;
	double value3;
	double value4;
	double value5;
		
	while(1) 
	{
		infile1 >> value1;
		infile2 >> value2;
		infile3 >> value3;
		infile4 >> value4;
		infile5 >> value5;
		
		value1 = (value1/100000)*100;
		value2 = (value2/100000)*100;
		value3 = (value3/100000)*100;
		value4 = (value4/100000)*100;
		value5 = (value5/100000)*100;
		
		if(infile1.eof()) break;
		if(infile2.eof()) break;
		if(infile3.eof()) break;
		if(infile4.eof()) break;
		if(infile5.eof()) break;
		
		Nvectot.push_back(value1);
		Nvec1.push_back(value2);
		Nvec2.push_back(value3);
		Nvec3.push_back(value4);
		Nvec4.push_back(value5);
	}

	
	cout << "xaxis vector size:" << xaxis.size() << endl << "TotRing vector size:" << Nvectot.size() << endl << "Ring 1 vector size:" << Nvec1.size() << endl << "Ring 2 vector size:" << Nvec2.size() << endl << "Ring 3 vector size:" << Nvec3.size() << endl << "Ring 4 vector size:" << Nvec4.size() << endl;
	
	infile1.close();
	infile2.close();
	infile3.close();
	infile4.close();
	infile5.close();
	
	TCanvas *c1 = new TCanvas();
	
	TMultiGraph *mg = new TMultiGraph();
	
	TGraph *graph1 = new TGraph();
	TGraph *graph2 = new TGraph();
	TGraph *graph3 = new TGraph();
	TGraph *graph4 = new TGraph();
	TGraph *graph5 = new TGraph();
	
	for(int j = 0; j < 102; j++)
	{
		graph1->AddPoint(xaxis[j], Nvectot[j]);
		graph2->AddPoint(xaxis[j], Nvec1[j]);
		graph3->AddPoint(xaxis[j], Nvec2[j]);
		graph4->AddPoint(xaxis[j], Nvec3[j]);
		graph5->AddPoint(xaxis[j], Nvec4[j]);
	}
	
	graph1->SetTitle("EffTot");
	graph2->SetTitle("EffR1");
	graph3->SetTitle("EffR2");
	graph4->SetTitle("EffR3");
	graph5->SetTitle("EffR4");
	
	graph1->SetMarkerColor(kBlack);
	graph2->SetMarkerColor(kRed);
	graph3->SetMarkerColor(kCyan);
	graph4->SetMarkerColor(kGreen);
	graph5->SetMarkerColor(kGray);
	
	graph1->SetMarkerSize(2);
	graph2->SetMarkerSize(2);
	graph3->SetMarkerSize(2);
	graph4->SetMarkerSize(2);
	graph5->SetMarkerSize(2);
	
	mg->Add(graph1,"*");
	mg->Add(graph2,"*");
	mg->Add(graph3,"*");
	mg->Add(graph4,"*");
	mg->Add(graph5,"*");
	
    mg->GetXaxis()->SetTitle("Pressure (bar)");
    mg->GetYaxis()->SetTitle("Efficiency (%)");
	mg->Draw("A");
	
	gPad->BuildLegend();
}
