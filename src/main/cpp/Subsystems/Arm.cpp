#include "Subsystems/Arm.h"

Arm::Arm() {
    ctre::phoenix6::configs::TalonFXConfiguration configs{};
    configs.Slot0.kP = 60; 
    configs.Slot0.kI = 0;  
    configs.Slot0.kD = 6; 

    // Amp peaks at 120
    configs.TorqueCurrent.PeakForwardTorqueCurrent = 120;
    configs.TorqueCurrent.PeakReverseTorqueCurrent = -120;

    m_motor.SetPosition(0_tr);
}

// Every 50ms sends its position to the smartdashboard
void Arm::Periodic() {
    frc::SmartDashboard::PutNumber("ARM POS", m_motor.GetPosition().GetValueAsDouble());
}

// Takes PosValue, goal position, and acceptable range, to determine if your position is within the acceptable range
bool Arm::Is_Done(units::angle::turn_t goal) {
    return CONSTANTS::IN_THRESHOLD<units::turn_t>(m_motor.GetPosition().GetValue(), goal, 0.01_tr);
}

void Arm::Move(units::angle::turn_t goal) {
    m_motor.SetControl(m_positionTorque.WithPosition(goal));
}

frc2::CommandPtr Arm::Move_Command(units::angle::turn_t goal)
{
    return frc2::cmd::Run( [this, goal] {
        Move(goal);
    }, {this} );
}

frc2::CommandPtr Arm::Idle()
{
    return frc2::cmd::Run( [this] {
        Move(CONSTANTS::ARM::STOWED);
        }, {this} );
}