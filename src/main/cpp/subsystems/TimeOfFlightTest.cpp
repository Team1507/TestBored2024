// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/TimeOfFlightTest.h"
#include <frc/SmartDashboard/SmartDashboard.h>

TimeOfFlightTest::TimeOfFlightTest()
{


    m_timeOfFlight.SetRangingMode(frc::TimeOfFlight::RangingMode::kShort, 20.0);

};

// This method will be called once per scheduler run
void TimeOfFlightTest::Periodic() 
{
    frc::SmartDashboard::PutBoolean("TOF: IsRangeValid",  m_timeOfFlight.IsRangeValid()   );
    frc::SmartDashboard::PutNumber("TOF: GetRange",       m_timeOfFlight.GetRange()       );
    frc::SmartDashboard::PutNumber("TOF: GetStatus",      m_timeOfFlight.GetStatus()      );
}


bool TimeOfFlightTest::Inrange(void)
{
    return m_timeOfFlight.IsRangeValid();
}
