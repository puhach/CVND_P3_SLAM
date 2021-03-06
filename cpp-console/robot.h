#pragma once

#include "position.h"
#include "measurement.h"

#include <tuple>
#include <vector>
#include <random>
#include <functional>


class World;


class Robot
{
public:

	double getSensorRange() const { return this->sensorRange; }

	double getStepSize() const { return this->stepSize; }

	double getMeasurementNoise() const { return this->measurementNoise; }

	double getMotionNoise() const { return this->motionNoise; }

	void sense();
	
	bool moveAndSense(double dx, double dy);

	void roamAndSense();

	template <class Localizer>
	std::pair<Positions, Positions> localize(const Localizer &localizer) const;



protected:
	Robot(double sensorRange, double stepSize, double measurementNoise, double motionNoise, World &world
		, std::function<bool (World&, double dx, double dy, double noise)> move
		, std::function<Measurement (const World&, double range, double noise)> senseLandmarks);

	Robot(const Robot& other) = delete;

	Robot(Robot&& other) = default;	// noexcept deduced
	//Robot(Robot&& other) noexcept = default;	

	virtual ~Robot() noexcept = default;

	Robot& operator = (const Robot& other) = delete;

	Robot& operator = (Robot&& other) = default;	// noexcept deduced

private:

	double sensorRange, stepSize, measurementNoise, motionNoise;
	World& world;
	std::function<bool(World&, double dx, double dy, double noise)> move;
	std::function<Measurement(const World&, double range, double noise)> senseLandmarks;

	Measurements measurements;
	Displacements displacements;
};	// Robot

