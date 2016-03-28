#include <chrono>
#include <iostream>
#include <thread>

int main()
{
// serialisieren von Zeit
// time_point --> to_time_t -->ctime
    using namespace std::literals;
    typedef std::chrono::time_point<std::chrono::system_clock> time_point;
    
    auto beginn = std::chrono::system_clock::now();
    auto begin_time = std::chrono::system_clock::to_time_t(beginn);
    std::cout << std::ctime(&begin_time) << std::endl;
    
    std::this_thread::sleep_for(1s);
    
    auto ende = std::chrono::system_clock::now();
    auto ende_time = std::chrono::system_clock::to_time_t(ende);
    std::cout << std::ctime(&ende_time) << std::endl;
    
    std::chrono::duration<double, std::milli> elapsed = ende-beginn;

    std::cout << elapsed.count() << std::endl;

    return 0;
}