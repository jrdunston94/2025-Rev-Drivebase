#include "Drivebase.h"

Drivebase::Drivebase()
{
  //Create 4 calls of the modules
    SwerveModule(1,2);



}


void Drivebase::SetAngle(double angle)
{

  LeftFrontTurn.GetClosedLoopController().SetReference(angle,rev::spark::SparkLowLevel::ControlType::kPosition);


}

void Drivebase::Periodic ()
{


}