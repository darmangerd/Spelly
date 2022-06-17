# Contribution and developer manual

## On host machine
### Requirements
- [gcc](https://gcc.gnu.org)
- [cmake (version >= 3.18)](https://cmake.org)

### Compile and run
```sh
cmake -B build
cd build
make
./spelly
```

### Run tests
```sh
cmake -B build
cd build
make
./spelly_tests
```

## Using Docker
### Requirements
- [Docker](https://docs.docker.com/desktop/)

### Compile and run
```sh
$ cd <root_path_to_spelly>
$ docker build -t spelly .
$ docker run spelly
```

### Run tests
```sh
$ cd <root_path_to_spelly>
$ docker build -t spelly_tests -f DockerfileTests .
$ docker run spelly_tests
```

# Documentation
You can access the documentation by opening the file located in `docs/index.html`.

If you need to regenerate the documentation, you can achieve it by running the following command:
```sh
$ doxygen .doxygen
```

> A git commit hook hook is setup to build the documentation at each commit
