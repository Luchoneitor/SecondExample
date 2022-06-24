#include "pch.h"


//Include global variables libraries

//map inputs and outputs to meaningful names



DLLEXPORT void plecsSetSizes( SimulationSizes* aSizes)
{ 
	*aSizes = (SimulationSizes){ SIMULATION_SIZES };
}


//This function is automatically called at the beginning of the simulation
DLLEXPORT void plecsStart(struct SimulationState* aState)
{
	
	
	
		
}


//This function is automatically called every sample time
//output is written to DLL output port after the output delay
DLLEXPORT void plecsOutput(struct SimulationState* aState)
{

	
}
