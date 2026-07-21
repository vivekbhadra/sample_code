// thread_return_result.cpp
// This code demonstrates returning results from a thread in C++17.
// A worker thread processes sensor data and returns the computed
// moving average back to the main thread using std::promise and std::future.
#include <chrono>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

double compute_moving_average(const std::vector<int> &samples)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate processing
    if (samples.empty())
        return 0.0;
    return static_cast<double>(std::accumulate(samples.begin(), samples.end(), 0LL)) / samples.size();
}

int main()
{
    std::promise<std::vector<int>> data_promise;
    std::future<std::vector<int>> data_future = data_promise.get_future();

    std::promise<double> result_promise;
    std::future<double> result_future = result_promise.get_future();

    // Worker thread: receives raw data, computes average, sends result
    std::thread worker(
        [df = std::move(data_future), &result_promise]() mutable
        {
            try
            {
                std::vector<int> samples = df.get(); // std::future::wait() blocks until the data is ready
                double avg = compute_moving_average(samples);
                result_promise.set_value(avg);
            }
            catch (...)
            {
                result_promise.set_exception(std::current_exception());
            }
        });

    // Main thread: simulates sensor input
    std::vector<int> sensor_readings = { 22, 23, 25, 24, 23, 26, 24 };
    std::cout << "Main: Sending sensor data...\n";
    data_promise.set_value(sensor_readings); // Could also use std::move if the main thread no longer needs it

    // Wait for result
    std::cout << "Main: Waiting for processed average...\n";
    double average = result_future.get();
    std::cout << "Main: Moving average = " << average << "\n";

    worker.join();
    return 0;
}