# GitHub Action DockerHub - Containerized C Application

This project demonstrates how to containerize a simple C application using Docker and automate its build, testing, vulnerability scanning, and deployment using GitHub Actions. The project builds a Docker image of the application, scans for vulnerabilities with Trivy, and pushes the Docker image to Docker Hub if it passes security checks.

## Project Structure

- **Dockerfile**: Defines the multi-stage build process for the Docker image, compiling the C application in a build environment and copying the compiled binary to a smaller runtime image.
- **hello.c**: C code that includes a simple "Hello World" program and a basic test to verify functionality.
- **containerize-C-Application.yml**: GitHub Actions workflow file that automates building, testing, vulnerability scanning, and pushing the Docker image to Docker Hub.

## Running the Project Locally

To run the project and test it locally using Docker:
1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   
2. **Build the Docker Image**:
   ```bash
   docker build -t hello:latest .

3. **Run the Docker Container**:
   ```bash
   docker run hello:latest

4. **Run Trivy for Vulnerability Scanning (Optional): Install Trivy locally and scan your Docker image**:
   ```bash
   trivy image hello:latest

To run the project and test it locally without using Docker:
1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd <repository-directory>

2. **Compile the Application**:
   ```bash
   gcc -o helloworld hello.c

3. **Run the Application**:
   ```bash
    ./helloworld

This will print Hello World to the terminal and run a basic test to verify that the output is correct.

## GitHub Secrets
To securely push images to Docker Hub, add the following secrets in your GitHub repository settings:

   * DOCKER_USERNAME: Your Docker Hub username.
   * DOCKER_PASSWORD: Your Docker Hub password.

## Workflow Overview
This GitHub Actions workflow is triggered on a push to the main branch or can be manually triggered. It performs the following steps:

1. Checks out the code from the repository.
2. Verifies that GCC is installed.
3. Compiles the C code to create a binary.
4. Runs tests to verify functionality.
5. Builds a Docker image of the application.
6. Installs Trivy for vulnerability scanning.
7. Scans the Docker image for high and critical vulnerabilities.
8. If the image passes the scan, it is pushed to Docker Hub.

## License
This project is licensed under the MIT License.
Let me know if you need any further modifications or additions!
