#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"
#include "Sphere.h"

using namespace MATH;

class PhysicsObject {
	friend class Physics;
public:
	PhysicsObject();
	virtual ~PhysicsObject();
	

public:
	/// Untility functions so small they cane be inlined
	inline void setPos(const Vec3 &pos_) { pos = pos_; }
	inline Vec3 getPos() { return pos; }
	inline void setVel(const Vec3 &vel_) { vel = vel_; }
	inline Vec3 getVel() { return vel; }
	inline void setAccel(const Vec3 &accel_) { accel = accel_; }
	inline Vec3 getAccel() { return accel; }
	inline void setAngVel(const float& angVel_) { angVel = angVel_; }
	inline void applyForce(const Vec3 force) { accel = force / mass;  }
	inline float getAng() { return angle; }
	inline void applyTorque(const float torque) { angAccel = torque / rotationalI; }
protected:
	Vec3 pos, vel, accel;
	float rotationalI;
	float angle, angVel, angAccel;


	float mass;
	Sphere boundingSphere;
};
#endif

