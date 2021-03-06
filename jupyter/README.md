# Landmark Detection & Robot Tracking (SLAM)

## Project Overview

In this project we implement SLAM (Simultaneous Localization and Mapping) for a 2 dimensional world. It combines robot sensor measurements and movement to create a map of an environment from only sensor and motion data gathered by a robot, over time. SLAM gives a way to track the location of a robot in the world in real-time and identify the locations of landmarks such as buildings, trees, rocks, and other world features. This is an active area of research in the fields of robotics and autonomous systems. 

*Below is an example of a 2D robot world with landmarks (purple x's) and the robot (a red 'o') located and found using *only* sensor and motion data collected by that robot. This is just one example for a 50x50 grid world.*

<p align="center">
  <img src="./images/robot_world.png" width=50% height=50% />
</p>

The project is broken up into three Python notebooks:

__Notebook 1__ : Robot Moving and Sensing

__Notebook 2__ : Omega and Xi, Constraints 

__Notebook 3__ : Landmark Detection and Tracking 


## Setup

Before we can get started coding, we need to make sure to have all the libraries and dependencies required to support this project. 

### Local Environment Instructions

1. Clone the repository, and navigate to the downloaded folder.
```
git clone https://github.com/puhach/graph-slam.git
cd graph-slam
```

2. Create (and activate) a new environment, named `slam` with Python 3.6. If prompted to proceed with the install `(Proceed [y]/n)` type y.

	- __Linux__ or __Mac__: 
	```
	conda create -n slam python=3.6
	source activate slam
	```
	- __Windows__: 
	```
	conda create --name slam python=3.6
	activate slam
	```
	
	At this point your command line should look something like: `(slam) <User>:graph-slam <user>$`. The `(slam)` indicates that your environment has been activated, and you can proceed with further package installations.

6. Install a few required pip packages, which are specified in the requirements text file (including OpenCV).
```
pip install -r requirements.txt
```


## Notebooks

1. Navigate back to the repo (your source environment should still be activated at this point):
```shell
cd
cd graph-slam
```

2. Open the directory of notebooks, using the below command:
```shell
jupyter notebook
```

3. Once opened any of the project notebooks, make sure you are in the correct `slam` environment by clicking `Kernel > Change Kernel > slam`.


## License

This project is licensed under the terms of the MIT license.
