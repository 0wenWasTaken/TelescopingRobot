#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Commands.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/ConditionalCommand.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/smartdashboard/SmartDashboard.h>
#include "RobotContainer.h"

class Hand : public frc2::SubsystemBase {

    public:
        Hand();
    
    private:
        //code
};