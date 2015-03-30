#include <iostream>
#include <cmath> ///@todo only needed for example formula, maybe remove later

#include "CalculatorBase.h"
#include "OptSimulatedAnnealing.h"

using namespace cppOpt;

class MyCalculator : public CalculatorBase
{
public:
    void calculate(OptValue &optValue) const
    {
        optValue.result = pow(optValue.get_parameter("X"),2);
    }
};

using namespace std;

int main()
{
    OptBoundaries
        optBoundaries,
        optBoundaries2;
    unsigned int maxCalculations = 2;
    OptTarget optTarget = APPROACH;
    T coolingFactor = 0.995;
    T startChance = 0.25;
    OptBoundary optBoundary(-3.0, 10.0, "X");
    OptBoundary optBoundary2(-30.0, -10.0, "X");
    optBoundaries.add_boundary(optBoundary);
    optBoundaries2.add_boundary(optBoundary2);
    MyCalculator myCalculator;

    OptSimulatedAnnealing opt(optBoundaries, maxCalculations, &myCalculator, optTarget, 3.0, coolingFactor, startChance);
    OptSimulatedAnnealing opt2(optBoundaries2, maxCalculations, &myCalculator, optTarget, 3.0, coolingFactor, startChance);

    OptBase::enable_logging("log.test", optBoundaries); ///@todo usage of optBoundaries might not be clear here
    OptBase::run_optimisations(2);

    return 0;
}
