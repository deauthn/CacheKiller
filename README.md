# CacheKiller

CacheKiller is a utility program designed to help you clean up your system's memory and cache. It provides options to clear pagecache, dentries, inodes, swap space, temporary files, and systemd journal logs.

## Features

- Clear pagecache, dentries, and inodes
- Clear swap space
- Remove temporary files
- Clear systemd journal logs

## Prerequisites

- A Unix-like operating system (I use Arch btw.)
- C++ compiler

## Installation

1. Clone the repository or download the source code.
2. Open a terminal and navigate to the directory containing [`catch.cpp`](catch.cpp).
3. Compile the source code using the following command:

    ```sh
    g++ -o CacheKiller catch.cpp
    ```

4. The executable `CacheKiller` will be created in the same directory.

## Usage

Run the CacheKiller executable to start the program. You will be prompted to confirm each action before it is executed.

```sh
./CacheKiller
```

### Example

```
$ ./CacheKiller
CacheKiller! This program will help you clean up your system's memory and cache.
Do you want to clear pagecache, dentries, and inodes? (y/n): y
Clearing pagecache, dentries, and inodes...
Do you want to clear swap space? (y/n): y
Clearing swap space...
Do you want to remove temporary files? (y/n): y
Removing temporary files...
Do you want to clear systemd journal logs? (y/n): y
Clearing systemd journal logs...
Memory and cache cleanup finished, [CacheKiller]
```

## Logging

CacheKiller logs all actions to a file named `killer.log` in the current directory.

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss any changes.