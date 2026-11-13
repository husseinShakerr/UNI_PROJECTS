#include <iostream>
#include <vector>
#include <chrono>
#define CHUNKGiB 1073741824
#define CHUNKKiB 1024

void allocateMemory(size_t cSize) {
	int counter = 0;
	std::vector<char*> addresses;
	auto start = std::chrono::high_resolution_clock::now();
	try
	{
		while (true) {
			char* block = new char[cSize];
			addresses.push_back(block);
			counter++;
			if ((counter * cSize) % (1024 * 1024) == 0) std::cout << counter * cSize / (1024 * 1024) << "\n";
		}
	}
	catch (const std::bad_alloc&)
	{
		double totalMemoryGB = (static_cast<double>(counter) * cSize) / 1073741824;
		std::cout << "Total blocks: " << counter << std::endl;
		std::cout << "Total memory allocated: " << totalMemoryGB << " GB" << std::endl;
		std::cout << "Out of memory resources..." << std::endl;
		std::cout << "Last adress allocated: " << static_cast<void*>(addresses.back()) << std::endl;
		auto stop = std::chrono::high_resolution_clock::now();
		auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		std::cout << "Allocating time: " << totalTime.count() << " (ms)." << std::endl;
		system("Pause");
	}
}

int main()
{
	bool running = 1;
	int userChoice;
	size_t chunkSize;
	do {
		std::cout << "Press one of these options for chunk size.\n1 for GiB\n2 for KiB\n3 to exit program\nEnter choice: ";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			chunkSize = CHUNKGiB;
			running = false;
			break;
		case 2:
			chunkSize = CHUNKKiB;
			running = false;
			break;
		case 3:
			running = false;
			std::cout << "Exiting program...";
			return 0;
		default:
			std::cout << "Press a valid option." << std::endl;
			continue;
		}
	}while(running);
	std::cout << "Selected chunk size: " << chunkSize << " bytes.\n";
	std::cout << "Allocating memory...\n";
	allocateMemory(chunkSize);
	return 0;
}

