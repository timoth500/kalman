/*
 * functions.h
 *
 *  Created on: Sep 4, 2017
 *      Author: tim
 */

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <random>

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

namespace tracker {


void matrixOperate(double a[6][6], double b[6]){
	for(int i = 0;i<6;i++)
		for(int j = 0;j<6;j++)
			b[i] = a[j][i]*b[i];
}

void matrixAdd(double a[6][6], double b[6][6]){
	for(int i=0;i<6;i++)
		for(int j = 0;j<6;j++)
			a[i][j] = a[i][j] + b[i][j];
}

void matrixTranspose(double a[6][6]){
	for(int i=0;i<6;i++)
		for(int j = 0;j<6;j++)
			a[i][j] = a[j][i];
}

void vectorAdd(double a[6],double b[6]){
	for(int i = 0;i<6;i++)
		a[i] = a[i] + b[i];
}

void identify(double a[6][6]){
	for(int i = 0;i<6;i++)
		a[i][i] = 1.0;
}

void predictState(double sm[6][6],double s[6], double os[6], double u[6], double noise[6]){
	matrixOperate(sm,s);
	for(int i=1;i<6;i++) u[i]=os[i]*u[i];
	vectorAdd(s,u);
	vectorAdd(s,noise);

}

void addNoise(double a[6]){
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0,1.0);
	for (int i=0; i<6; i++)
		a[i] = distribution(generator);

}

void seeState(double a[6]){
	std::cout << "The elements are: " << a[0] << ", "  << a[1] << ", "  << a[2]   << ", "  << a[3] << ", "  << a[4] << ", "  << a[5] << std::endl;
}

void predictCovariance(double a[6][6]){
	std::cout << "in function now" << std::endl;
}

void cross(double u[3], double v[3]){
	u[0] = u[1]*v[2] - u[2]*v[1];
	u[1] = u[2]*v[0] - u[0]*v[2];
	u[2] = u[0]*v[1] - u[1]*v[0];
}

}


#endif /* FUNCTIONS_H_ */
