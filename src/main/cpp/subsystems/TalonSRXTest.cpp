// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/TalonSRXTest.h"

TalonSRXTest::TalonSRXTest() = default;

// This method will be called once per scheduler run
void TalonSRXTest::Periodic() 
{
    SetPower(0.05);
}


void TalonSRXTest::Stop(void)
{
    m_talonSRX.Set(0.0);
}
void TalonSRXTest::SetPower(float power)
{
    m_talonSRX.Set(power);
}
