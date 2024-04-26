#include <iostream>
#include <string>
#include <thread>
#include <shared_mutex>

std::string str = "";
std::shared_mutex m;

void Read()
{
    std::shared_lock lock(m);
    std::cout << "Read(): " << str << std::endl;
}

void Write(const char* text)
{
    std::unique_lock lock(m);
    str += text;
    std::cout << "Write(): " << str << std::endl;
}

int main()
{
    std::thread thread_read(Read);
    std::thread thread_write(Write, "new string");


    thread_read.join();
    thread_write.join();
    std::cout << "main(): " << str << std::endl;

    return 0;
}