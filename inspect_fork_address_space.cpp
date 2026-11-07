// inspect_fork_address_space.cpp
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>

int shared_at_fork = 42;

int main()
{
    const pid_t child_pid = fork();

    if (child_pid == -1)
    {
        std::perror("fork");
        return EXIT_FAILURE;
    }

    if (child_pid == 0)
    {
        shared_at_fork = 99;
        std::cout << "Child PID: " << getpid() << ", address: " << &shared_at_fork << ", value: " << shared_at_fork
                  << '\n';
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds{ 30 });
        return EXIT_SUCCESS;
    }

    std::cout << "Parent PID: " << getpid() << ", child PID: " << child_pid << ", address: " << &shared_at_fork
              << ", value: " << shared_at_fork << '\n';
    std::cout.flush();

    int status = 0;
    if (waitpid(child_pid, &status, 0) == -1)
    {
        std::perror("waitpid");
        return EXIT_FAILURE;
    }

    return WIFEXITED(status) ? WEXITSTATUS(status) : EXIT_FAILURE;
}