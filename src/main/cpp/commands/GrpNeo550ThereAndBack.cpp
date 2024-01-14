// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpNeo550ThereAndBack.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdNeo550SetPosition.h"
#include "commands/CmdPrintText.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
GrpNeo550ThereAndBack::GrpNeo550ThereAndBack() {

  AddCommands(
    CmdPrintText("GrpNeo550ThereAndBack Starting....."),
    CmdNeo550SetPosition(50.0), 

    frc2::WaitCommand(2_s),

    CmdNeo550SetPosition(0.0),

    CmdPrintText("GrpNeo550ThereAndBack Done!")
  );
}
