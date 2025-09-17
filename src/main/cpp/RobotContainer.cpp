// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include <frc2/command/Command.h>

RobotContainer::RobotContainer() {
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings()
{
PrimaryController.A().OnTrue(frc2::cmd::RunOnce([this](){drive.SetAngle(0);},{&drive}));
PrimaryController.B().OnTrue(frc2::cmd::RunOnce([this](){drive.SetAngle(90);},{&drive}));
PrimaryController.X().OnTrue(frc2::cmd::RunOnce([this](){drive.SetAngle(180);},{&drive}));
PrimaryController.Y().OnTrue(frc2::cmd::RunOnce([this](){drive.SetAngle(270);},{&drive}));


}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
