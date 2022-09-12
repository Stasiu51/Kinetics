#include "PhysicsLibrary.h"
#include <iostream>


using namespace std;

#ifndef FU_H
#define FU_H
#include <functional>
#endif

Sphere& sphere1 = *new Sphere(20, 20, 0.2);
Sphere& sphere2 = *new Sphere(20, 20, 0.2);
Sphere& sphere3 = *new Sphere(20, 20, 0.05);
Sphere& sphere4 = *new Sphere(20, 20, 0.5);

PhysicsObject& m1 = *new PhysicsObject(sphere1, 1.0, 0.0);
PhysicsObject& m2 = *new PhysicsObject(sphere2, 1.0, 0.0);
PhysicsObject& m3 = *new PhysicsObject(sphere3, 0.01, 0.0);
PhysicsObject& m4 = *new PhysicsObject(sphere4, 1000.0, 0.0);

//Helix& helix1 = *new Helix(1.0, 0.05, 0.01, 20, 1000, 20);
GravityConstraint& GC = *new GravityConstraint(0.1);
//SpringConstraint& SC1 = *new SpringConstraint(m1,m2,5.0,1.0,helix1);

function<void(float)>* physicsUpdate;
void update(float deltaTime) {
	(*physicsUpdate)(deltaTime);
}

int main(int argc, char** argv) {
	setGraphicsScale(0.2);
	initialiseGraphics(argc, argv);
	m1.position = Vector3D(0.0, 5.0, -0.0);
	m1.velocity = Vector3D(-3.5, 0.0, 0.0);
	m2.position = Vector3D(0.0, -2.0, 0.0);
	m2.velocity = Vector3D(4.0, 0.0, 0.0);
	m3.position = Vector3D(0.0, 5.5, 0.0);
	m3.velocity = Vector3D(-3.3,0.1, 0.0);
	m4.position = Vector3D(0.0, 0.5, 0.0);
	sphere1.init();
	sphere2.init();
	sphere3.init();
	sphere4.init();
	//helix1.init();
	addPhysicsObject(&m1);
	addPhysicsObject(&m2);
	addPhysicsObject(&m3);
	addPhysicsObject(&m4);
	GC.addObject(&m1);
	GC.addObject(&m2);
	GC.addObject(&m3);
	GC.addObject(&m4);
	addPhysicsConstraint(&GC);
	//addPhysicsConstraint(&SC1);

	physicsUpdate = getPhysicsUpdateFunction();
	startGraphics(new function<void(float)>(update));
	return 0;
}
