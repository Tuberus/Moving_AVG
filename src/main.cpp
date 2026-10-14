
#include "gleitAvg.hpp"

int main()
{
    std::vector<double> data;
    std::vector<double> result;
    std::string line;
    std::ifstream inputData("sensordaten.csv");
    std::ofstream NewFile("newdata_10.csv");
    

    if (!inputData)
    {
        std::cout << "ERROR NOT FOUND FILE" << std::endl;
    }

    while (getline(inputData, line))
    {

        // std::cout << line << std::endl;
        if (line.empty())
            continue;

        std::replace(line.begin(), line.end(), ',', '.');

        double wert = stod(line);
        data.push_back(wert);
    }
    Avg NewValue(data, 10);
    result = NewValue.calcAvg();

    for (const auto &i : result)
    {
        std::ostringstream ss;
        ss << i;
        std::string text = ss.str();
        std::replace(text.begin(), text.end(), '.', ',');
        
        NewFile << text << "\n";
    }
    inputData.close();
    NewFile.close();

    return 0;
}