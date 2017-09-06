// kalman electron tracker

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "/home/tim/workspace/scratch/src/functions.h"
#include "/home/tim/workspace/scratch/src/components.h"
#include "/home/tim/workspace/scratch/src/constants.h"
#include "/home/tim/workspace/scratch/src/initialconditions.h"

using namespace std;
using namespace tracker;

int main() {

	status a;
	cout << a.data[0] << endl;
	int iterMax = 10;

	for(int i = 0; i < iterMax; i++){

		// Step 0: Estimate Lorentz force vector

		cross(s,B);
		u[0] = (q/m)*s[0];u[1] = (q/m)*s[1];u[2] = (q/m)*s[2];u[3] = (q/m)*s[0];u[4] = (q/m)*s[1];u[5] = (q/m)*s[2];
		seeState(u);
		// Step 1: Predict the state vector
		cout << "Predict the state vector: " << i << endl;
		predictState(stateMatrix,state,input,u,noise);
		//seeState(state);
		seeState(u);
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
