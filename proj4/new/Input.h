#ifndef INPUT_H
#define INPUT_H

class Input
{
	private:
		double _velocity;
		double _steering_rate;
		double _timestamp;

	public:

		Input();
		Input(double _vel, double _ster_rate, double _time);

		double getVel() const;
		void setVel(double _vel);

		double getSteeringRate() const;
		void setSteeringRate(double _ster_rate);

		double getTimestamp() const;
		void setTimestamp(double _time);
};

#endif
