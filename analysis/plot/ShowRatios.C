#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void ShowRatios()
{	
	
	std::vector<double> energy;
	std::vector<double> ratiovec1;
	std::vector<double> ratiovec2;
	std::vector<double> ratiovec3;
	std::vector<double> ratiovec4;
	std::vector<double> ratiovec5;
	std::vector<double> ratiovec6;
	
	fstream infile1;
	fstream infile2;
	fstream infile3;
	fstream infile4;
	fstream infile5;
	fstream infile6;
	
	infile1.open("/vol0/simtetra/analysis/runcf4/ratios/Ratio1File.dat", ios::in);
	infile2.open("/vol0/simtetra/analysis/runcf4/ratios/Ratio2File.dat", ios::in);
	infile3.open("/vol0/simtetra/analysis/runcf4/ratios/Ratio3File.dat", ios::in);
	infile4.open("/vol0/simtetra/analysis/runcf4/ratios/Ratio4File.dat", ios::in);
	infile5.open("/vol0/simtetra/analysis/runcf4/ratios/Ratio5File.dat", ios::in);
	infile6.open("/vol0/simtetra/analysis/runcf4/ratios/Ratio6File.dat", ios::in);
	
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
		
		cout << value1 << endl;
		cout << value2 << endl;
		cout << value3 << endl;
		cout << value4 << endl;
		cout << value5 << endl;
		cout << value6 << endl;
	}

	infile1.close();
	infile2.close();
	infile3.close();
	infile4.close();
	infile5.close();
	infile6.close();
}
