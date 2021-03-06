#pragma once

#include "sfwdraw.h"

#define SOFTRED 0xbfbfbf31

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PADDLE_Y_POS = WINDOW_HEIGHT / 8;
const float PADDLE_X_POS = WINDOW_WIDTH / 2 - 50;

extern bool bisSoliActivate;

//const int paddleLength = 200;
//const int paddleHeight = 12;

//const float matrix[16] = { 1,0,0,0,  0,1,0,0, 0,0,1,0, 0,0,0,1 };
//bool bisGameOver = false;
//int BallsLeft = 5;
//int totalPoints = 0;

struct vector2d
{
	float x, y;
};

class Box
{
private:
	vector2d position;
	int width, height;
public:
	void setPosition(float x, float y);
	void setDimension(int w, int h);

	vector2d getPosition() const;
	vector2d getDimension() const;

	Box CreateBox(float x, float y, int width, int height);
	void DrawBox(unsigned color, unsigned fill) const;
	void UpdateBox();

	bool isBoxColliding(float x, float y);
};

class Ball
{
private:
	vector2d position, velocity;
	float radius;
	bool out = false;
	float velocityMult = 1.0f;
	int health;

public:		
	void setRadius(float r);
	void setPosition(float x, float y);
	void setVelocity(float x, float y);
	void setVelocityMult(float x);
	void setOut();
	
	void UpdateBall();

	bool outBounds() const;
	bool getOut() const;

	float getRadius() const;
	vector2d getPosition() const;
	vector2d getVelocity() const;
	float getVelocityMult() const;
	void drawColorBall(float radius) const;
	Ball createBall(float posX, float posY, float veloX, float veloY, float radius);

	void doCollision(Ball &b);

	bool isColliding(Ball b) const;

	void reduceHealth(int dmg);
	int getHealth() const;
	void setHealth(int h);

};

float randomRange(int start, int end);