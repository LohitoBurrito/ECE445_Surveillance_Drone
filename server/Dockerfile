# Use a base image that includes a package manager (e.g., Ubuntu)
FROM ubuntu:20.04

# Set environment variables to non-interactive to prevent prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies including build tools, curl, libcurl, and Boost libraries
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    bash \
    wget \
    g++ \
    make \
    libcurl4-openssl-dev \
    libboost-all-dev \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /workspace

# Copy your Makefile and source files into the container
COPY . /workspace

# Set the default command to bash so you can interact with the container
CMD ["/bin/bash"]
