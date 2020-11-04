
#include "disphelper.h"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{

	CDhInitialize init;
	CDispPtr cst, project;
	long nParameters;
	double dParameter;

	dhToggleExceptions(TRUE);

	try {
		dhCheck(dhCreateObject(L"CSTStudio.Application", NULL, &cst));
		dhCheck(dhGetValue(L"%o", &project, cst, L".Active3D()"));
	}
	catch (string errstr)
	{
		std::cerr << "Fatal error details:" << std::endl << errstr << std::endl;
	}
	dhCheck(dhGetValue(L"%d", &nParameters, project, L".GetNumberOfParameters()"));
	dhCheck(dhGetValue(L"%e", &dParameter, project, L".RestoreDoubleParameter(%s)", "taper_angle"));

	std::cout << nParameters << "\n";
	std::cout << dParameter << "\n";

	SAFE_RELEASE(project);
	SAFE_RELEASE(cst);
	dhUninitialize(TRUE);

	// system("pause");
	return 0;
}