// kalman electron tracker

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "/home/tgw9/local/kalman/functions.h"
#include <random>
using namespace std;

int main() {
	
	double q=1.6e-19;
	double dt = 1e-9;
	double B[3] = {0.0,0.0,.9583};
	int iterMax = 10;
	double ax,ay,az = 0;
	double state[6] = {};	
	double stateMatrix[6][6] = {{1.0,0.0,0.0,dt,0.0,0.0},{0.0,1.0,0.0,0.0,dt,0.0},{0.0,0.0,1.0,0.0,0.0,dt},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
	double u[6] = {ax,ay,az,ax,ay,az};
	double inputMatrix[6][6] = {{.01,0,0,0,0,0},{0,.01,0,0,0,0},{0,0,.01,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
	identify(stateMatrix);
	identify(inputMatrix);
	double coMatrix[6][6] = {};
	double noise[6] = {};
	addNoise(noise);
	
	seeState(state);

	for(int i = 0; i < iterMax; i++){
		
		// Step 0: Estimate Lorentz force vector
			
		cross(state ,B);
		ax = 1.0;
		ay = 1.0;
		az = 1.0;
		// Step 1: Predict the state vector
		cout << "Predict the state vector: " << i << endl;
		predictState(stateMatrix,state,inputMatrix,u,noise);
		seeState(state);
		usleep(1000000);

		// Step 2: Predict the covariance matrix
		cout << "Predict the covariance matrix: " << i  << endl;
		predictCovariance(coMatrix);
		usleep(100000);

		// Step 6: Calculate the Kalman gain
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
