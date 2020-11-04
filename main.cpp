
#include "disphelper.h"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	CDhInitialize init;
	CDispPtr cst, project, farFieldArray, farFieldPlot;
	long nParameters;
	double dParameter;

	dhToggleExceptions(TRUE);

	try
	{
		dhCheck(dhCreateObject(L"CSTStudio.Application", NULL, &cst));
		dhCheck(dhGetValue(L"%o", &project, cst, L".Active3D()"));
		dhCheck(dhGetValue(L"%o", &farFieldArray, project, L".FarFieldArray()"));
		dhCheck(dhGetValue(L"%o", &farFieldPlot, project, L".FarfieldPlot()"));
	}
	catch (string errstr)
	{
		std::cerr << "Fatal error details:" << std::endl
				  << errstr << std::endl;
	}
	dhCheck(dhGetValue(L"%d", &nParameters, project, L".GetNumberOfParameters()"));
	dhCheck(dhGetValue(L"%e", &dParameter, project, L".RestoreDoubleParameter(%s)", "taper_angle"));

	std::cout << nParameters << "\n";
	std::cout << dParameter << "\n";

	// FarField Array
	dhCheck(dhCallMethod(farFieldArray, L".UseArray(%b)", true));

	// Linear Array
	// dhCheck(dhCallMethod(farFieldArray, L".Arraytype(%s)", "rectangular"));
	// dhCheck(dhCallMethod(farFieldArray, L".XSet(%d,%e,%e)", 50, 10.0, 30.0));
	// dhCheck(dhCallMethod(farFieldArray, L".SetList()"));
	// dhCheck(dhCallMethod(farFieldPlot, L".ResetPlot()"));

	// Rectangular Array
	dhCheck(dhCallMethod(farFieldArray, L".Arraytype(%s)", "rectangular"));
	dhCheck(dhCallMethod(farFieldArray, L".XSet(%d,%e,%e)", 50, 10.0, 30.0));
	dhCheck(dhCallMethod(farFieldArray, L".YSet(%d,%e,%e)", 50, 10.0, 30.0));
	dhCheck(dhCallMethod(farFieldArray, L".SetList()"));
	dhCheck(dhCallMethod(farFieldPlot, L".ResetPlot()"));

	try
	{
		SAFE_RELEASE(project);
		SAFE_RELEASE(cst);
	}
	catch (string errstr)
	{
		std::cerr << "Fatal error details:" << std::endl
				  << errstr << std::endl;
	}
	dhUninitialize(TRUE);
	return 0;
}