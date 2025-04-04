#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

struct ScanResult {
    std::string engine;
    std::string fileName;
    std::string url;
    bool threatDetected;
    std::string details;
};

bool simulateScan(const std::string& data, const std::string& engine) {
    // Simulate sending file data to different antivirus engines and return result
    return std::rand() % 2 == 0; // Random number simulating presence of threat
}

bool simulateUrlScan(const std::string& url, const std::string& engine) {
    // Simulate sending URL to different antivirus engines and return result
    return std::rand() % 2 == 0; // Random number simulating presence of threat
}

std::vector<ScanResult> scanFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::vector<std::string> engines = {"360", "Tencent", "ESET", "Bitdefender", "Kaspersky", "Avast", "Avira"};
    std::vector<ScanResult> results;

    for (const auto& engine : engines) {
        bool threatDetected = simulateScan(std::string(buffer.begin(), buffer.end()), engine);
        results.push_back({
            engine,
            fileName,
            "",
            threatDetected,
            threatDetected ? "Threat detected" : "No threat detected"
        });
    }

    return results;
}

std::vector<ScanResult> scanUrl(const std::string& url) {
    std::vector<std::string> engines = {"360", "Tencent", "ESET", "Bitdefender", "Kaspersky", "Avast", "Avira"};
    std::vector<ScanResult> results;

    for (const auto& engine : engines) {
        bool threatDetected = simulateUrlScan(url, engine);
        results.push_back({
            engine,
            "",
            url,
            threatDetected,
            threatDetected ? "Threat detected" : "No threat detected"
        });
    }

    return results;
}

void displayResults(const std::vector<ScanResult>& results) {
    std::cout << "<h2>Scan Results</h2>" << std::endl;
    for (const auto& result : results) {
        std::cout << "<p><strong>" << result.engine << " Engine:</strong> " << result.details;
        if (!result.fileName.empty()) {
            std::cout << " (" << result.fileName << ")";
        } else if (!result.url.empty()) {
            std::cout << " (" << result.url << ")";
        }
        std::cout << "</p>" << std::endl;
    }
}

int main() {
    std::srand(std::time(0)); // Initialize random number generator

    int choice;
    std::cout << "Simple File Scanner by 123456lwh&123回家" << std::endl;
    std::cout << "1. Start File Scan" << std::endl;
    std::cout << "2. Start URL Scan" << std::endl;
    std::cout << "Choose an operation: ";
    std::cin >> choice;

    if (choice == 1) {
        std::string fileName;
        std::cout << "Enter file name: ";
        std::cin >> fileName;
        try {
            std::vector<ScanResult> results = scanFile(fileName);
            displayResults(results);
        } catch (const std::exception& e) {
            std::cout << "<p>Scan failed: " << e.what() << "</p>" << std::endl;
        }
    } else if (choice == 2) {
        std::string url;
        std::cout << "Enter URL: ";
        std::cin >> url;
        std::vector<ScanResult> results = scanUrl(url);
        displayResults(results);
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}


