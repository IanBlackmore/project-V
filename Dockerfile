FROM alpine:3.22.2
EXPOSE 23500
# Update the package list and install necessary tools and libraries
RUN apk update
RUN apk add build-base 
RUN apk add cmake 
RUN apk add g++ 
RUN apk add gcc 
RUN apk add boost-dev 
RUN apk add asio-dev 
RUN apk add libstdc++ libc6-compat
RUN apk add bash
RUN apk add && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY app .

CMD ["./runCommands.sh"]


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
