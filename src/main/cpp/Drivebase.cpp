#include "Drivebase.h"

//set up 4 swerve modules in the include


Drivebase::Drivebase()
{
 
 //use the initiallizer syntax here
 // use the spark max reference swerce code

  //Front Left
    SwerveModule(1,2);
  //Front Right
    SwerveModule(3,4);
  //Back Left
    SwerveModule(5,6);
  //Back Right
    SwerveModule(7,8);




}


void Drivebase::SetAngle(double angle)
{

  LeftFrontTurn.GetClosedLoopController().SetReference(angle,rev::spark::SparkLowLevel::ControlType::kPosition);


}

void Drivebase::Periodic ()
{


}