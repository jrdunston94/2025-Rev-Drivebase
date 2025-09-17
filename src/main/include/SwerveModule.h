#pragma once

#include <rev/SparkMax.h>


class SwerveModule
{
public:

//this is called a constructor
  SwerveModule(int Driveid,int Turnid);

void SetState(double angle,double speed);
double GetState(int  )


private:

rev::spark::SparkMax Drive;
rev::spark::SparkMax Turn;

};