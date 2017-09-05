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


void matrixOperate(double a[6][6], double b[6]){
	for(int i = 0;i<6;i++)
		for(int j = 0;j<6;j++)
			b[i] = a[j][i]*b[i];
}

void vectorAdd(double a[6],double b[6]){
	for(int i = 0;i<6;i++)
		a[i] = a[i] + b[i];
}

void identify(double a[6][6]){
	for(int i = 0;i<6;i++)
		a[i][i] = 1.0;
}

void predictState(double sm[6][6],double s[6], double os[6][6], double u[6], double noise[6]){
	//do something
	matrixOperate(sm,s);
	matrixOperate(os,u);
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

void cross(double a[6], double b[6]){
	double c[3];
	c[0] = a[3] - b[3];
	c[1] = b[4] - a[4];
	c[2] = a[5] - b[5];
	a = c;
}


#endif /* FUNCTIONS_H_ */
