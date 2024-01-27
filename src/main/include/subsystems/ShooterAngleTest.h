#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

class ShooterAngleTest : public frc2::SubsystemBase {
 public:
  ShooterAngleTest();

  void Stop(void);

  void SetPower(double power);

  double GetPower(void);

  void SetEncoderPosition(float position );

  void Periodic() override;

 private:

  rev::CANSparkMax          m_brushedMotor{CAN_BRUSHEDMOTOR, rev::CANSparkMax::MotorType::kBrushed};
  rev::SparkRelativeEncoder m_brushed_encoder = m_brushedMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kQuadrature, 4096);
  rev::SparkAnalogSensor    m_analogSensor    = m_brushedMotor.GetAnalog(rev::SparkAnalogSensor::Mode::kAbsolute);

};
