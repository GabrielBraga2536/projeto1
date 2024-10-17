#include <iostream>
#include <future>   // For async and future
#include <chrono>   // For timing
#include <thread>   // For thread sleep

bool getUserInputWithTimeout(char& input, int timeoutMs) {
    std::promise<char> promise;
    std::future<char> future = promise.get_future();
    
    // Lambda to capture user input in a separate thread
    std::thread([&promise]() {
        char temp;
        std::cin >> temp;
        promise.set_value(temp);
    }).detach();

    if (future.wait_for(std::chrono::milliseconds(timeoutMs)) == std::future_status::ready) {
        input = future.get();
        return true;  // Input was provided
    } else {
        return false;  // Timeout reached, no input
    }
}

int main() {
    std::cout << "Press any key within 5 seconds to provide input, or the code will continue...\n";
    
    char input;
    if (getUserInputWithTimeout(input, 5000)) {
        std::cout << "You entered: " << input << "\n";
    } else {
        std::cout << "No input provided, continuing the code...\n";
    }

    // Continue with the rest of the program
    std::cout << "Program continues...\n";

    return 0;
}