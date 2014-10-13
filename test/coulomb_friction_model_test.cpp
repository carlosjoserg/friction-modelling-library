#include <iostream>
#include <friction_models/coulomb_friction_model.h>

int main()
{
	using namespace friction_models;

	// initialize parameters
	Parameters params;
	params.mu_c = 0.5;
	params.mu_s = 0.8;
	params.DV = 0.001;
	params.slope = 250;
	CoulombFriction coulomb_force(params);
	coulomb_force.printParameters();

	// fake data
	InputData in_data;
	in_data.f_n = 20.0;
	in_data.dx_dt = 0.01;
	coulomb_force.printInputData(in_data);

	// output variable
	double out_force;

	coulomb_force.computeFrictionForce(in_data, params, out_force);

	// print output
	std::cout << "friction force" << std::endl << "--------------" << std::endl;
	std::cout << "f_c: " << out_force << "N" << std::endl;
	std::cout << std::endl;

	

	return 0;
}