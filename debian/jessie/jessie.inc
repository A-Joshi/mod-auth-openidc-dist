FROM debian:jessie
MAINTAINER hans.zandbelt@zmartzone.eu

RUN mkdir -p /var/cache/apt/archives
RUN apt-get clean && apt-get --fix-missing update
RUN apt-get update && apt-get install -y apt-utils curl
