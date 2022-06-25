#pragma once

#include"Sizes.h"
//OFFSET CALCULATIONS FOR INPUTS

#define NO_OF_INPUTS (NO_OF_TRIG + NO_OF_MEAS + NO_OF_COMMANDS)
#define TRIG_BASE 0
#define MEAS_BASE (TRIG_BASE+NO_OF_TRIG)
#define COMM_BASE (MEAS_BASE+NO_OF_MEAS)

//OFFSET CALCULATIONS FOR OUTPUTS
#define NO_OF_OUTPUTS (NO_OF_PWMS + NO_OF_SCOPES + NO_OF_RELAYS )
#define PWM_BASE  0
#define SCOPE_BASE (PWM_BASE + NO_OF_PWMS)
#define REL_BASE (SCOPE_BASE + NO_OF_SCOPES)



// ASSIGN Commands
// no _STATIC_ASSERT(port>=0 && port< NO_OF_COMMANDS); here - the range is checked during runtime

#define COMMAND(command,port)\
            command = (bool)g_aState->inputs[COMM_BASE+port]

// ASSIGN Triggers

#define TRIG(trig,port)\
            _STATIC_ASSERT(port>=0 && port< NO_OF_TRIG);\
            trig = (uint16_t)g_aState->inputs[TRIG_BASE+port]


//ASSIGN Inputs

#define MEAS(meas,port)\
            _STATIC_ASSERT(port>=0 && port< NO_OF_MEAS);\
            meas = (float)g_aState->inputs[MEAS_BASE+port]

//ASSIGN Otuputs: PWM, Scopes, Relays
#define PWM(duty,port)\
            _STATIC_ASSERT(port>=1 && port< NO_OF_PWMS+1);\
            aState->outputs[PWM_BASE+port-1] = 1.0f-duty

#define PHS(phs,port)\
            _STATIC_ASSERT(port>=1 && port< NO_OF_PWMS+1);\
            aState->outputs[PWM_BASE+port-1] = phs

#define SCOPE(value,port)\
            _STATIC_ASSERT(port>=1 && port< NO_OF_SCOPES+1);\
            aState->outputs[SCOPE_BASE+port-1] = value


#define RELAY(value,port)\
            _STATIC_ASSERT(port>=1 && port< NO_OF_RELAYS+1);\
           g_aState->outputs[REL_BASE+port-1] = value



//ASSIGN PARAMS
#define PARAM(param,port)\
            _STATIC_ASSERT(port>=0 && port< NO_OF_PARAMS);\
            param = (float)aState->parameters[port]



#define SIMULATION_SIZES .numInputs     = NO_OF_INPUTS, \
                        .numOutputs    = NO_OF_OUTPUTS,\
                        .numParameters = NO_OF_PARAMS, \
                        .numStates     = NO_OF_STATES



#define CLEAR_SCOPES {\
    for (size_t i =SCOPE_BASE; i < (SCOPE_BASE + NO_OF_SCOPES); ++i)\
    {\
        g_aState->outputs[i] = -123.0f; \
    }\
}

#define RESET_PWM {\
    for (size_t i = PWM_BASE; i < (PWM_BASE+ NO_OF_PWMS); ++i)\
    {\
        g_aState->outputs[i] = 0.0f;\
    }\
}

#define RESET_REL    {\
    for (size_t i = REL_BASE; i < (REL_BASE+NO_OF_RELAYS); ++i)\
    {\
        g_aState->outputs[i] = 0U;\
    }\
}