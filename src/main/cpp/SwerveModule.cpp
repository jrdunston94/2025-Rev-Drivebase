#include "SwerveModule.h"
//#include <units/math.h>

SwerveModule::SwerveModule(int Driveid,int Turnid)
:
  Drive{Driveid,rev::spark::SparkLowLevel::MotorType::kBrushless},
  Turn{Turnid,rev::spark::SparkLowLevel::MotorType::kBrushless}
{

  //TODO:Get position conversion factor by doing math- gear ratio to the wheel and wheel diameter would reccomend this to be in meters there is a units library in C++
//2025 Comp drivebase is 6.23:1
//2024 Comp drivebase is 3.75:1
rev::spark::SparkBaseConfig configdrive{};

  configdrive.SmartCurrentLimit(50);
  configdrive.SetIdleMode(rev::spark::SparkBaseConfig::kCoast);

    double WheelDiameter = 3; //Value in inches
    double GearRatio = 3.75; //unitless
    double PConversion= WheelDiameter*std::numbers::pi/GearRatio;
    double VConversion= PConversion/60;

  //Look in the REV library for additional desired functions, disable soft limits on all controllers
  configdrive.encoder.PositionConversionFactor(PConversion);
  configdrive.encoder.VelocityConversionFactor(VConversion);
  configdrive.closedLoop.Pidf(0.06,0,0,0);
  configdrive.softLimit.ForwardSoftLimitEnabled(false);	
  configdrive.softLimit.ReverseSoftLimitEnabled(false);
  configdrive.closedLoop.SetFeedbackSensor(rev::spark::ClosedLoopConfig::FeedbackSensor::kPrimaryEncoder);

Drive.Configure(configdrive,
                          rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                          rev::spark::SparkBase::PersistMode::kNoPersistParameters);

  rev::spark::SparkBaseConfig configazimuth{};

  configazimuth.SmartCurrentLimit(20);
  configazimuth.SetIdleMode(rev::spark::SparkBaseConfig::kCoast);
  configazimuth.absoluteEncoder.PositionConversionFactor(360);
  configazimuth.closedLoop.Pidf(0.06,0,0,0);
  configazimuth.closedLoop.PositionWrappingEnabled(true);
  configazimuth.closedLoop.PositionWrappingMinInput(0);
  configazimuth.closedLoop.PositionWrappingMaxInput(360);
  configazimuth.closedLoop.SetFeedbackSensor(rev::spark::ClosedLoopConfig::FeedbackSensor::kAbsoluteEncoder);
  configazimuth.softLimit.ForwardSoftLimitEnabled(false);	
  configazimuth.softLimit.ReverseSoftLimitEnabled(false);


Turn.Configure(configazimuth,
                          rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                          rev::spark::SparkBase::PersistMode::kNoPersistParameters);
}
//Set state, Get State, get the Angle the azimuth is facing relative to the module, Set the module angle relative to the module as well as the target velocity
//Get the encoder position and velocity of the drive motor from the module

}
