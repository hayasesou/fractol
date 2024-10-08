# Fractol

![factol](https://github.com/hayasesou/fractol/blob/master/images/fractol.gif)

Fractol is an interactive program that visualizes the Mandelbrot set and Julia set. It is written in C and uses the MinilibX library for graphical display.

## Features

- Display of the Mandelbrot set
- Display of the Julia set
- Interactive exploration using mouse operations
- Color palette changes using keyboard operations

## Requirements

- Docker
- X11 (XQuartz for macOS)

## Installation and Execution

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/fractol.git
   ```

2. Navigate to the project directory:
   ```
   cd fractol
   ```

3. Build the Docker image:
   ```
   docker compose build
   ```

4. Start the Docker container:
   ```
   docker compose up -d
   ```

5. Enter the Docker container:
   ```
   docker exec -it 42fractol bash
   ```

6. Compile the program:
   ```
   make
   ```

7. Run the program:
   ```
   ./fractol <fractal_type>
   ```
   Specify either `mandelbrot` or `julia` for `fractal_type`.

## Host Configuration

### Linux

1. X11 configuration:
   ```
   xhost +local:docker
   ```

2. Set environment variable:
   ```
   export DISPLAY=:0
   ```

### macOS

1. Install XQuartz.

2. Launch XQuartz, go to "Preferences" -> "Security" tab, and check "Allow connections from network clients".

3. Run the following command in the terminal:
   ```
   xhost + 127.0.0.1
   ```

4. Set environment variable:
   ```
   export DISPLAY=host.docker.internal:0
   ```

## Permission Settings

1. Run the following command on the host to set X11 socket permissions:
   ```
   sudo chmod 1777 /tmp/.X11-unix
   ```

2. Add your user to the Docker group (first time only):
   ```
   sudo usermod -aG docker $USER
   ```
   You need to log out and log back in for the changes to take effect.

## Usage

- Left mouse click: Set parameters for the Julia set
- Mouse movement: Update the Julia set in real-time
- Mouse wheel: Zoom in/out
- Space key: Change color palette
- ESC key: Exit the program
