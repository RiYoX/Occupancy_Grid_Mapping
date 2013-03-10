/*
 * Author: Chris Savill, chs17@aber.ac.uk
 * File Name: Pioneer.h
 * Description: Stores function prototypes for Pioneer to use.
 * First Created: 25/02/2013
 * Last Modified: 08/03/2013
 */

#ifndef PIONEER_H
#define PIONEER_H

#include <iostream>
#include <libplayerc++/playerc++.h>
#include <cstdio>
#include <cstdlib>
#include "Occupancy_Grid.h"

#ifndef DIRECTIONS
#define DIRECTIONS
#define ZERO 0
#define ONE_EIGHTY 180
#define NIGHTY 90
#define MINUS_NIGHTY -90
#endif

#define MOVE_PGAIN 0.5
#define TURN_PGAIN 0.5
#define MOVE_ERROR_BOUND 0.025
#define TURN_ERROR_BOUND 0.05
#define FRONT_REAR_SONAR_RANGE 0.635
#define LEFT_RIGHT_SONAR_RANGE 0.645

using namespace PlayerCc;

class Pioneer {
private:
    Occupancy_Grid *oG;
    int frontSensorFacing; /* Field that describes the direction the front sensor currently faces relative to its original direction 'UP' */
    int rearSensorFacing; /* Field that describes the direction the rear sensor currently faces relative to its original direction 'DOWN' */
    int leftSensorFacing; /* Field that describes the direction the right sensor currently faces relative to its original direction 'LEFT' */
    int rightSensorFacing; /* Field that describes the direction the left sensor currently faces relative to its original direction 'RIGHT' */
    double calculateTurnRate(double currentYaw, double targetYaw);
    void turnToNewDirection(double targetYaw, Position2dProxy *pp, PlayerClient *robot);
    void moveToNextCell(Position2dProxy *pp);
    int evaluateDirection(double currentYaw);
    void setFrontSensorDirection(int currentDirection);
    void setRearSensorDirection(int currentDirection);
    void setLeftSensorDirection(int currentDirection);
    void setRightSensorDirection(int currentDirection);
    void reconfigureSensors(int currentDirection);
    void surveyCycle(double s3, double s4, double s12, double s11, double s0, double s15, double s7, double s8, int currentDirection);
    void configureCycle(PlayerClient *robot, Position2dProxy *pp, double *currentYaw, int *currentDirection);

public:
    void runPioneer();
    ~Pioneer();
};
#endif