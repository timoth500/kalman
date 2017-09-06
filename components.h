/*
 * components.h
 *
 *  Created on: Sep 6, 2017
 *      Author: tim
 */

#ifndef COMPONENTS_H_
#define COMPONENTS_H_

namespace tracker {


class components {
public:
	components() {}
	virtual ~components() {}
};


class status: public components {
public:
	status() {}
	virtual ~status() {}
	double data[6] = {};
};

}
#endif /* COMPONENTS_H_ */
