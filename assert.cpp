#include <iostream>
#include <assert.h>

float travelTime(float distance, float speed){
    assert(speed >0);
    return distance/speed;
}
    
int main(){
    float distance,speed,time;
    std::cout << "Input distance: ";
    std::cin >> distance;
    std::cout << "Input speed: ";
    std::cin >> speed;
    time = travelTime(distance,speed);
    std::cout << "Time - " << time << std::endl;

}