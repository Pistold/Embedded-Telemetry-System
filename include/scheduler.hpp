#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <functional>
#include <vector>
#include <chrono>

// Represents a single scheduled task
struct Task {
    std::function<void()> func;                     // Function to execute
    std::chrono::milliseconds period;               // Execution period
    std::chrono::steady_clock::time_point next_run; // Next scheduled time
};

// Simple cooperative scheduler (embedded-style)
class Scheduler {
public:
    // Add a task that runs every `period`
    void add_task(const std::function<void()>& task,
                  std::chrono::milliseconds period);

    // Call this regularly from the main loop
    void tick();

private:
    std::vector<Task> tasks_;
};

#endif // SCHEDULER_HPP