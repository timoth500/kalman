//============================================================================
// Name        : scratch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"
#include <random>
using namespace std;


int main() {

	int iterMax = 10;
	double state[6] = {};
	double stateMatrix[6][6] = {};
	double u[6] = {};
	double obsMatrix[6][6] = {};
	identify(stateMatrix);
	identify(obsMatrix);

	double noise[6] = {};
	addNoise(noise);

	seeState(state);

	for(int i = 0; i < iterMax; i++){

		// Step 1: Predict the state vector
		cout << "Predict the state vector: " << i << endl;
		predictState(stateMatrix,state,obsMatrix,u,noise);
		seeState(state);
		usleep(1000000);

		// Step 2: Predict the covariance matrix
		//cout << "Predict the covariance matrix: " << i  << endl;
		//usleep(1000);

		// Step 3: Calculate the Kalman gain
		//cout << "Calculate the Kalman gain: " << i  << endl;
		//usleep(10000);

		// Step 4: Update the state vector
		//cout << "Update the state vector: " << i  << endl;
		//usleep(100000);

		// Step 5: Update the covariance matrix
		//cout << "Update the covariance matrix: " << i  << endl;
		//usleep(1000000);


	}
	cout << "Finished!" << endl; // prints !!!Hello World!!!
	return 0;
}
