#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int main()
{
    int currentHome, Tin, Tout, Tlight;
    std::string state, tin, tout, mov, light;
    for (int day = 0; day < 2; ++day)
    {
        for (int hour = 0; hour < 24; ++hour)
        {
            std::cout << "Time: ";
            if (hour < 10)
                std::cout << "0";
            std::cout << hour << ":00\n"
                      << "Temperature inside, temperature outside, movement, lights:" << std::endl;
            std::getline(std::cin, state);
            std::stringstream buffer_stream(state);
            buffer_stream >> tin >> tout >> mov >> light;
            Tin = std::stoi(tin);
            Tout = std::stoi(tout);
            if (hour <= 16)
                Tlight = 5000;
            if (hour == 17)
                Tlight = 4500;
            if (hour == 18)
                Tlight = 3900;
            if (hour == 19)
                Tlight = 3300;
            if (hour >= 20)
                Tlight = 2700;
            if (Tin < 22 && !(currentHome & HEATERS))
            {
                currentHome |= HEATERS;
                std::cout << "Heaters ON!\n";
            }
            if (Tin > 25 && (currentHome & HEATERS))
            {
                currentHome &= (~HEATERS);
                std::cout << "Heaters OFF!\n";
            }
            if (Tin >= 30 && !(currentHome & CONDITIONER))
            {
                currentHome |= CONDITIONER;
                std::cout << "Conditioner ON!\n";
            }
            if (Tin <= 25 && (currentHome & CONDITIONER))
            {
                currentHome &= (~CONDITIONER);
                std::cout << "Conditioner OFF!\n";
            }
            if (Tout < 0 && !(currentHome & WATER_PIPE_HEATING))
            {
                currentHome |= WATER_PIPE_HEATING;
                std::cout << "Water Heating ON!\n";
            }
            if (Tout > 5 && (currentHome & WATER_PIPE_HEATING))
            {
                currentHome &= (~WATER_PIPE_HEATING);
                std::cout << "Water Heating OFF!\n";
            }
            if ((hour > 16 || hour < 5) && mov == "yes" && !(currentHome & LIGHTS_OUTSIDE))
            {
                currentHome |= LIGHTS_OUTSIDE;
                std::cout << "Lights ON!\n";
            }
            if ((hour > 16 || hour < 5) && mov == "no" && (currentHome & LIGHTS_OUTSIDE))
            {
                currentHome &= (~LIGHTS_OUTSIDE);
                std::cout << "Lights OFF!\n";
            }
            if ((hour >= 5 && hour <= 16) && (currentHome & LIGHTS_OUTSIDE))
            {
                currentHome &= (~LIGHTS_OUTSIDE);
                std::cout << "Lights OFF!\n";
            }
            if (light == "on" && !(currentHome & LIGHTS_INSIDE))
            {
                currentHome |= LIGHTS_INSIDE;
                std::cout << "Lights inside ON!\n";
            }
            if (light == "on" && (currentHome & LIGHTS_INSIDE))
            {
                std::cout << "Color temperature: " << Tlight << "K\n";
            }
            if (light == "off" && (currentHome & LIGHTS_INSIDE))
            {
                currentHome &= (~LIGHTS_INSIDE);
                std::cout << "Lights inside OFF!\n";
            }
        }
    }
}
