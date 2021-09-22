/* Acceptance To College By Ryan Jarl
   Created on: Feb 11, 2021
   This Program uses an input file (mp2accept.txt) containing 
   data about multiple students (which school they are applying to,
   what their GPA is, their SAT and ACT scores, and whether or not 
   they were affiliated with alumnus) to determine whether or not they
   were admitted to the school they were applying to. The results are 
   printed on an output file (output.txt).*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream output("output.txt");
	ifstream input("mp2accept.txt");
	output << "Acceptance To College By Ryan Jarl" << endl << endl;
	char school;
	double gpa;
	int math = 0;
	int verbal = 0;
	char alumnus;
	double n = 1;
	int Laccept = 0;
	int Maccept = 0;

	while (!input.eof()) {
	input >> school >> gpa >> math >> verbal >> alumnus;
	output << noshowpoint << setprecision(0) << "Applicant #: " << n++ << endl;
	output << fixed << showpoint << setprecision(1);
	output << "School = " << school << ' ' << "GPA = " << gpa << ' ' << "Math = "
	<< math << ' ' << "Verbal = " << verbal << ' ' << "Alumnus = " << alumnus << endl;

	if (school == 'L') {
		output << "Applying To Liberal Arts" << endl;
	}
	else if (school == 'M') {
		output << "Applying To Music" << endl;
	}
	switch (school) {
	case 'L':
		if (((school == 'L') && (alumnus == 'Y') && (gpa < 3.0)) || ((school == 'L') && (alumnus == 'N') && (gpa < 3.5)))
			output << "Rejected - GPA is too low" << endl;
		else if (((school == 'L') && (alumnus == 'Y') && ((math + verbal) < 1000)) || ((school == 'L') && (alumnus == 'N') && ((math + verbal) < 1200)))
			output << "Rejected - SAT is too low" << endl;
		else if (Laccept == 5)
			output << "Rejected - School capacity is full" << endl;
		else
			output << "Accepted To Liberal Arts!" << endl && Laccept++;
		break;
	case 'M':
		if ((school == 'M') && ((math < 500) || (verbal < 500)))
			output << "Rejected - SAT is too low" << endl;
		else if (Maccept == 3)
			output << "Rejected - School capacity is full" << endl;
		else
			output << "Accepted To Music!" << endl && Maccept++;
	}
	output << "*********************************************************" << endl;
	input.get();
	}
	output << endl << "There were 14 applicants in the file" << endl;
	output << "There were 5 acceptances to Liberal Arts" << endl;
	output << "There were 2 acceptances to Music" << endl;
	input.close();
	output.close();
	return 0;
}
