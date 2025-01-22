# myRadar

Display moving objects, simulate trajectories, detect and manage collisions between a great number of sprites, requiring efficient management of resources.

Project for semester 1 of the Epitech C Graphical Programming module.

### Description

This program runs a 2D air traffic simulation. It visualizes planes and control towers on a graphical interface, simulating their trajectories and possible collisions. There can be many entities in the simulation, so optimization plays an important role.

The planes fly in a straight path from their origin to their destination. They maintain a stable speed and can wait before taking off. If two planes collide in the simulation, they will crash and disappear from it. However, if the collision occurs within the range of a control tower, the crash will not take place.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [CSFML](https://www.sfml-dev.org/download/csfml/)
- [Python](https://www.python.org/) (optional)

### Installation

* Download/Clone the repository and enter its directory
* Install CSFML \
`sudo apt install libcsfml-dev` or `sudo dnf install CSFML-devel`
* Compile the code typing `make`

## Usage

**Execution:**

```
./my_radar input_file
```

Basic generator use

`python3 generator.py -p planes -t towers`


Generator explained in more detail running:

`python3 generator.py -h`

### Arguments

- `input_file`: File containing all the action that is going to happen, some examples are provided inside test, alongside the generator.

- `planes`: Amount of files to be simulated.

- `towers`: Amount of towers to be simulated.

### Examples

```
./tester.sh "numbers"
python3 len_test.py start stop step amount
```

### Controls

- `q` quit the program
- `s` toggle texture display
- `l` toggle hit box display

## Innerworkings

### Collisions

The program has to manage a lot of simultaneous planes at once, calculating the collisions for all of them at once can be pretty demanding. The solution for this is a quadtree. If there are too many planes, the quadtree will separate all them in 4 different areas, if one of this areas has again too many planes, it will be divided again in 4 sub-areas, and so on.

This makes collision detection more efficient, as checking collisions between `n` number of objects gets exponentially slower, while the quadtree only gets logariythmically slower, meaning that its more efficient to separate planes into small groups and then check for collisions than just checking for collisions in a big group.

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors

* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
