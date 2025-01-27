# Use a base image that includes a package manager (e.g., Ubuntu)
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y locales && locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Install dependencies including build tools, curl, libcurl, and Boost libraries
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    bash \
    wget \
    g++ \
    cmake \
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
