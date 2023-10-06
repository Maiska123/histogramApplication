
#include "RandomEintegerGenerator.h"
#include "Log.h"
#include "Histogram.h"

#include <iostream>
#include <string>
#include <cstring>

void print_usage()
{
    printf("Usage: histogramApplication.exe 10 1 0\nWhere params are \n 10 - iteration count \n \
             1 - statistics on/off \n 0 - all values and occurrences on/off\n Output: no default output for iterations, use params to get output ");
}

int main(int argc, char const *argv[])
{

    int iterationCount = 10, extensiveLogging = 0, allValuesOutput = 0;

    std::string arg;
    std::size_t pos;
    int value;

    switch (argc)
    {
    case 4:
        arg = argv[3];
        value = std::stoi(arg, &pos);

        if (value == 1)
        {
            allValuesOutput = 1;
        }
        [[fallthrough]];
    case 3:
        arg = argv[2];
        value = std::stoi(arg, &pos);

        if (value == 1)
        {
            extensiveLogging = 1;
        }
        [[fallthrough]];
    case 2:
        arg = argv[1];
        value = std::stoi(arg, &pos);

        if (value > 0 && value < INT32_MAX)
            iterationCount = value;
        break;
    default:
        print_usage();
        exit(EXIT_FAILURE);

        break; // exists before this
    }

    RandomEintegerGenerator *randomGenerator = new RandomEintegerGenerator();

    std::unique_ptr<Hist::Logger> logger = std::make_unique<Hist::Logger>();

    Hist::Histogram histogram = Hist::Histogram(std::move(logger));

    for (int i = iterationCount - 1; i >= 0; i--)
    {

        histogram.add(randomGenerator->operator()());

        if (extensiveLogging == 1)
        {

            std::cout << "Histogram maxValue: " << histogram.getMaxValue()
                      << std::endl;

            std::cout << "Histogram minValue: " << histogram.getMinValue()
                      << std::endl;

            std::cout << "Histogram mode: " << histogram.getMode()
                      << std::endl;
        }

        if (allValuesOutput == 1)
        {
            std::cout << "All Values:"
                      << std::endl;

            for (auto &[key, value] : histogram.getAllValues())
            {

                std::cout << "\tkey: " << key << " amount: " << value
                          << std::endl;
            }
        }
        if (extensiveLogging == 1 || allValuesOutput == 1)
            std::cout << std::endl;
    }

    return 0;
}
