#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void PlotRatios()
{	
	
	std::vector<double> energy;
	std::vector<double> ratiovec1;
	std::vector<double> ratiovec2;
	std::vector<double> ratiovec3;
	std::vector<double> ratiovec4;
	std::vector<double> ratiovec5;
	std::vector<double> ratiovec6;
	
	energy.push_back(0.01);
	energy.push_back(0.05);
	
	for(double i = 0.1; i <= 10; i = i+0.1)
	{
		energy.push_back(i);
	}

	fstream infile1;
	fstream infile2;
	fstream infile3;
	fstream infile4;
	fstream infile5;
	fstream infile6;
	
	infile1.open("/vol0/simtetra/analysis/run18/ratios/Ratio1File.dat", ios::in);
	infile2.open("/vol0/simtetra/analysis/run18/ratios/Ratio2File.dat", ios::in);
	infile3.open("/vol0/simtetra/analysis/run18/ratios/Ratio3File.dat", ios::in);
	infile4.open("/vol0/simtetra/analysis/run18/ratios/Ratio4File.dat", ios::in);
	infile5.open("/vol0/simtetra/analysis/run18/ratios/Ratio5File.dat", ios::in);
	infile6.open("/vol0/simtetra/analysis/run18/ratios/Ratio6File.dat", ios::in);
	
	double value1;
	double value2;
	double value3;
	double value4;
	double value5;
	double value6;
		
	while(1) 
	{
		infile1 >> value1;
		infile2 >> value2;
		infile3 >> value3;
		infile4 >> value4;
		infile5 >> value5;
		infile6 >> value6;
		
		if(infile1.eof()) break;
		if(infile2.eof()) break;
		if(infile3.eof()) break;
		if(infile4.eof()) break;
		if(infile5.eof()) break;
		if(infile6.eof()) break;
		
		ratiovec1.push_back(value1);
		ratiovec2.push_back(value2);
		ratiovec3.push_back(value3);
		ratiovec4.push_back(value4);
		ratiovec5.push_back(value5);
		ratiovec6.push_back(value6);
	}

	
	cout << "Energy vector size:" << energy.size() << endl << "Ratio 1 vector size:" << ratiovec1.size() << endl << "Ratio 2 vector size:" << ratiovec2.size() << endl << "Ratio 3 vector size:" << ratiovec3.size() << endl << "Ratio 4 vector size:" << ratiovec4.size() << endl << "Ratio 5 vector size:" << ratiovec5.size() << endl << "Ratio 6 vector size:" << ratiovec6.size() << endl;
	
	infile1.close();
	infile2.close();
	infile3.close();
	infile4.close();
	infile5.close();
	infile6.close();
	
	TCanvas *c1 = new TCanvas();
	c1->Divide(2, 3);
	
	TGraph *graph1 = new TGraph();
	TGraph *graph2 = new TGraph();
	TGraph *graph3 = new TGraph();
	TGraph *graph4 = new TGraph();
	TGraph *graph5 = new TGraph();
	TGraph *graph6 = new TGraph();
	
	for(int j = 0; j < 102; j++)
	{
		graph1->AddPoint(energy[j], ratiovec1[j]);
		graph2->AddPoint(energy[j], ratiovec2[j]);
		graph3->AddPoint(energy[j], ratiovec3[j]);
		graph4->AddPoint(energy[j], ratiovec4[j]);
		graph5->AddPoint(energy[j], ratiovec5[j]);
		graph6->AddPoint(energy[j], ratiovec6[j]);
	}
	
	c1->cd(1);
	graph1->Draw("A*");
	graph1->SetTitle("R2/R1");
	graph1->SetMinimum(0);
	graph1->SetMarkerColor(kRed);
	
	c1->cd(2);
	graph2->Draw("A*");
	graph2->SetTitle("R3/R1");
	graph2->SetMinimum(0);
	graph2->SetMarkerColor(kBlack);
	
	c1->cd(3);
	graph3->Draw("A*");
	graph3->SetTitle("R4/R1");
	graph3->SetMinimum(0);
	graph3->SetMarkerColor(kCyan);
	
	c1->cd(4);
	graph4->Draw("A*");
	graph4->SetTitle("R3/R2");
	graph4->SetMinimum(0);
	graph4->SetMarkerColor(kMagenta);

	c1->cd(5);
	graph5->Draw("A*");
	graph5->SetTitle("R4/R2");	
	graph5->SetMinimum(0);
	graph5->SetMarkerColor(kGreen);
	
	c1->cd(6);
	graph6->Draw("A*");
	graph6->SetTitle("R4/R3");
	graph6->SetMinimum(0);
	graph6->SetMarkerColor(kBlue);
}
