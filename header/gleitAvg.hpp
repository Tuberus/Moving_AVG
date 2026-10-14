#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Avg
{
public:
    Avg(std::vector<double> data, double WindSize) : data(data), WindSize(WindSize)
    {
        if (WindSize < 0)
        {
            std::cout << "WindSize muss Größer 0 sein" << std::endl;
        }
    }

    std::vector<double> calcAvg() const
    {
        std::vector<double> result;
        for (auto i = 0; i <= WindSize; i++)
        {
            result.push_back(data[i]);
        }
        for (int i = 0; i + WindSize <= (int)data.size(); i++)
        {
            double sum = 0.0;

            for (int j = 0; j < WindSize; j++)
            {
                sum += data[i + j];
            }
            result.push_back(sum / WindSize);
        }
        return result;
    }

private:
    std::vector<double> data;
    double WindSize;
};