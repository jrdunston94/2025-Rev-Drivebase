#pragma once

#include <frc2/command/Subsystem.h>
#include <rev/SparkMax.h>


class Drivebase : public frc2::SubsystemBase
{
public:

//this is called a constructor
  Drivebase();

void SetAngle(double angle);

void Periodic () override;

private:

rev::spark::SparkMax LeftFrontTurn{2,rev::spark::SparkLowLevel::MotorType::kBrushless};

};
