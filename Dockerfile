FROM ubuntu:latest
EXPOSE 23500
# Update the package list and install necessary tools and libraries
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    gcc \
    libboost-all-dev \
    libasio-dev \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
#COPY CMakeLists.txt .
COPY app .

CMD ["./runCommands.sh"]