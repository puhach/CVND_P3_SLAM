
#include "world.h"
#include "robot.h"
#include "graphslam.h"

#include <iostream>


int main()
{
    try
    {
        // Initialize the world.

        int worldWidth = 0, worldHeight = 0;
        std::cout << "Enter the world size (width and height): ";
        std::cin >> worldWidth >> worldHeight;
        
        int nLandmarks = 0;
        std::cout << "Enter the number of landmarks: ";
        std::cin >> nLandmarks;

        if (std::cin.fail())
            throw std::runtime_error("Invalid input for the world parameters.");
               
        World world(worldWidth, worldHeight, nLandmarks);
                
        // Show the landmarks.
        std::cout << world << std::endl;


        // Create the robot.

        double rx0 = 0, ry0 = 0;
        std::cout << "Enter the initial robot position (x and y): ";
        std::cin >> rx0 >> ry0;

        double sensorRange = 0;
        std::cout << "Enter the sensor range: ";
        std::cin >> sensorRange;

        if (std::cin.fail())
            throw std::runtime_error("Invalid input for the robot parameters.");

        Robot& robot = world.createRobot(rx0, ry0, sensorRange, 1, 0.008, 0.008);
                
        
        // Simulate robot motions and measurements over the specified number of time steps.
        
        int timesteps = 0;
        std::cout << "Enter the number of time steps: ";
        std::cin >> timesteps;

        if (std::cin.fail())
            throw std::runtime_error("Invalid number of time steps.");

        std::cout << std::endl << "Actual robot positions:" << std::endl << rx0 << " " << ry0 << std::endl;

        robot.sense(); // record zero displacement and landmark distances

        for (int t = 1; t <= timesteps; ++t)
        {
            robot.roamAndSense();

            std::cout << world.getRobotX() << " " << world.getRobotY() << std::endl;
        }

                
        // Run SLAM to estimate positions of the robot and landmarks.

        auto [estPositions, estLandmarks] = robot.localize(GraphSlam(rx0, ry0, static_cast<int>(world.getLandmarkNum())));
        

        // Print estimated positions and landmarks.

        std::cout << "\nEstimated robot positions:" << std::endl;
        for (const auto& [x, y] : estPositions)
            std::cout << x << " " << y << std::endl;
        

        std::cout << "\nEstimated landmark locations:" << std::endl;
        for (const auto& [x, y] : estLandmarks)
            std::cout << x << " " << y << std::endl;

    }   // try
    catch (const std::exception & e)
    {
        std::cout << std::endl << e.what() << std::endl;
    }
}