#include "SwerveModule.h"
#include <units/math.h>

SwerveModule::SwerveModule(int Driveid,int Turnid)
:
  Drive{Driveid,rev::spark::SparkLowLevel::MotorType::kBrushless},
  Turn{Turnid,rev::spark::SparkLowLevel::MotorType::kBrushless}
{
rev::spark::SparkBaseConfig configdrive{};

  configdrive.SmartCurrentLimit(50);
  configdrive.SetIdleMode(rev::spark::SparkBaseConfig::kCoast);
//TODO:Get position conversion factor by doing math- gear ratio to the wheel and wheel diameter would reccomend this to be in meters there is a units library in C++
//2025 Comp drivebase is 6.23:1
//2024 Comp drivebase is 3.75:1
  
  //TODO: Velocity conversion factor for the drive - Position unit conversion factor dived by 60 to get

Double WheelDiameter = 3; //Value in inches
Double GearRatio = 3.75; 
Double PConversion= WheelDiameter*PI()/GearRatio;
Double VConversion= PConversion/60;

  //Provide these values above to here
  //Look in the REV library for additional desired functions, disable soft limits on all controllers
  //
  configdrive.encoder.PositionConversionFactor(PConversion);
  configdrive.encoder.VelocityConversionFactor(VConversion);
  configdrive.closedLoop.Pidf(0.06,0,0,0);

  //switch this to the internal encoder
  configdrive.closedLoop.SetFeedbackSensor(rev::spark::ClosedLoopConfig::FeedbackSensor::kAbsoluteEncoder);


  LeftFrontTurn.Configure(configazimuth,
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


  LeftFrontTurn.Configure(configazimuth,
                          rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                          rev::spark::SparkBase::PersistMode::kNoPersistParameters);
}

}
