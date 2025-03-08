#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

void logAction(const std::string &action)
{
    std::ofstream logFile("killer.log", std::ios_base::app);
    logFile << action << std::endl;
}

bool executeCommand(const std::string &command)
{
    int result = system(command.c_str());
    if (result != 0)
    {
        std::cerr << "Error | " << command << std::endl;
        return false;
    }
    return true;
}

void clearPageCache()
{
    std::cout << "Clearing pagecache, dentries, and inodes..." << std::endl;
    if (executeCommand("sync; echo 3 > /proc/sys/vm/drop_caches"))
    {
        logAction("Cleared pagecache, dentries, and inodes");
    }
}

void clearSwap()
{
    std::cout << "Clearing swap space..." << std::endl;
    if (executeCommand("swapoff -a && swapon -a"))
    {
        logAction("Cleared swap space");
    }
}

void removeTempFiles()
{
    std::cout << "Removing temporary files..." << std::endl;
    if (executeCommand("rm -rf /tmp/*") && executeCommand("rm -rf /var/tmp/*"))
    {
        logAction("Removed temporary files");
    }
}

void clearJournalLogs()
{
    std::cout << "Clearing systemd journal logs..." << std::endl;
    if (executeCommand("journalctl --vacuum-time=1d"))
    {
        logAction("Cleared systemd journal logs");
    }
}

bool getUserConfirmation(const std::string &action)
{
    std::string input;
    while (true)
    {
        std::cout << "Do you want to " << action << "? (y/n): ";
        std::cin >> input;
        if (input == "y" || input == "Y")
            return true;
        else if (input == "n" || input == "N")
            return false;
        else
            std::cout << "You may only use Y && N [!]" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "CacheKiller! This program will help you clean up your system's memory and cache." << std::endl;

    if (getUserConfirmation("clear pagecache, dentries, and inodes"))
    {
        clearPageCache();
    }
    if (getUserConfirmation("clear swap space"))
    {
        clearSwap();
    }
    if (getUserConfirmation("remove temporary files"))
    {
        removeTempFiles();
    }
    if (getUserConfirmation("clear systemd journal logs"))
    {
        clearJournalLogs();
    }

    std::cout << "Memory and cache cleanup finished, [CacheKiller]" << std::endl;
    return 0;
}