FROM alpine:3.22.2
EXPOSE 23500
ENV TZ=America/Toronto \
DEBIAN_FRONTEND=noninteractive
# Update the package list and install necessary tools and libraries
RUN apk --no-cache update
RUN apk --no-cache add build-base \
cmake \
g++ \
gcc \
boost-dev \
asio-dev \
libstdc++ libc6-compat \
bash

WORKDIR /app
COPY app .
RUN chmod +x build/proj_v

CMD ["./build/proj_v"]


#FROM ubuntu:latest
#EXPOSE 23500
## Update the package list and install necessary tools and libraries
#RUN apt-get update && apt-get install -y \
#    build-essential \
#    cmake \
#    g++ \
#    gcc \
#    libboost-all-dev \
#    libasio-dev \
#    libstdc++6 \
#    && rm -rf /var/lib/apt/lists/*
#
#
#WORKDIR /app
#COPY app .
#
#
#CMD ["./runCommands.sh"]
