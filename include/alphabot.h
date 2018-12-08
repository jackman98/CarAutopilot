#ifndef ALPHABOT_H
#define ALPHABOT_H
class AlphaBot 
{
public:
	AlphaBot();
	~AlphaBot();
	void forward(void);
	void stop(void);
	void backward(void);
	void left(void);
	void right(void);
    void setPWMA(int value); //Right wheel
    void setPWMB(int value); //Left wheel
	void setMotor(int left, int right);
private:
	const int IN1 = 12;
	const int IN2 = 13;
	const int IN3 = 20;
	const int IN4 = 21;
	const int ENA = 6;
	const int ENB = 26;

};
#endif
