/*
 * initialconditions.h
 *
 *  Created on: Sep 6, 2017
 *      Author: tim
 */

#ifndef INITIALCONDITIONS_H_
#define INITIALCONDITIONS_H_

namespace tracker {


double B[3] = {0.0,0.0,.9583};
double state[6] = {0.0,0.0,0.0,1000.0,0.0,10.0};
double stateMatrix[6][6] = {{1.0,0.0,0.0,dt,0.0,0.0},{0.0,1.0,0.0,0.0,dt,0.0},{0.0,0.0,1.0,0.0,0.0,dt},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
double u[6] = {};
double input[6] = {.5*dt*dt, .5*dt*dt, .5*dt*dt, dt, dt, dt };
double coMatrix[6][6] = {{.01,0,0,0,0,0},{0,.01,0,0,0,0},{0,0,.01,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
double procnoicoMatrix[6][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
double noise[6] = {};
double s[3] = {1000.0,0.0,10.0};

}


#endif /* INITIALCONDITIONS_H_ */
