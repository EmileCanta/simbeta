#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void PlotOneRatio()
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
	
	infile1.open("Ratio1File.dat", ios::in);
	infile2.open("Ratio2File.dat", ios::in);
	infile3.open("Ratio3File.dat", ios::in);
	infile4.open("Ratio4File.dat", ios::in);
	infile5.open("Ratio5File.dat", ios::in);
	infile6.open("Ratio6File.dat", ios::in);
	
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

	TGraph *graph = new TGraph();
	
	for(int j = 0; j < 102; j++)
	{
		graph->AddPoint(energy[j], ratiovec3[j]);
	}
	

	graph->Draw("A*");
	graph->SetTitle("R4/R1");
	graph->SetMinimum(0);
	graph->SetMarkerColor(kRed);
	graph->SetMarkerSize(4);
	

}
